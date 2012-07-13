#include <soundmanager.h>

extern QString ACCEPTED_MIMETYPES;

SoundManager::SoundManager(QString project_path, QString identifier, QSqlDatabase db, QProgressBar *progress_bar, QObject *parent) : QObject(parent)
{
    inst = libvlc_new(0, NULL);

    this->project_path = project_path;
    this->identifier = identifier;
    this->db = db;
    this->library_identifier = QString("%1_library").arg(identifier);
    this->objects_identifier = QString("%1_objects").arg(identifier);
    this->objects_tracks_identifier = QString("%1_objects_tracks").arg(identifier);
    this->channels = 0;

    this->path = QString("%1/%2").arg(this->project_path, this->identifier);

    this->progress_bar = progress_bar;

    qDebug() << this->identifier << "instance summoned";
}

void SoundManager::createTables() {
    this->updateDatabase(this->library_identifier, QString("CREATE TABLE \"%1\" (\"id\" INTEGER PRIMARY KEY AUTOINCREMENT  NOT NULL  UNIQUE , \"path\" TEXT, \"last-change\" INTEGER, \"length\" INTEGER, \"artist\" VARCHAR, \"album\" VARCHAR, \"title\" VARCHAR)").arg(this->library_identifier));
    this->updateDatabase(this->objects_identifier, QString("CREATE TABLE \"%1\" (\"id\" INTEGER PRIMARY KEY  AUTOINCREMENT  NOT NULL  UNIQUE , \"name\" VARCHAR NOT NULL )").arg(this->objects_identifier));
    this->updateDatabase(this->objects_tracks_identifier, QString("CREATE TABLE \"%1\" (\"oid\" INTEGER NOT NULL, \"tid\" INTEGER NOT NULL )").arg(this->objects_tracks_identifier));
    this->updateDatabase(QString("%1-index").arg(this->objects_tracks_identifier), QString("CREATE UNIQUE INDEX \"%1-index\" on \"%2\" (oid, tid)").arg(this->objects_tracks_identifier, this->objects_tracks_identifier));
}

bool SoundManager::updateDatabase(QString identifier, QString sql) {
    QSqlQuery query;
    QString query_string = QString("SELECT COUNT(name) FROM sqlite_master WHERE type = \"table\" and name = \"%1\"").arg(identifier);
    query.exec(query_string);
    while(query.next()) {
        if(query.value(0) == 0) {
            query.exec(sql);
            this->db.commit();
            return true;
        }
    }
    return false;
}


/*!
 * Creates channels and fills media_container with AGMediaContainer objects
 */
bool SoundManager::createChannels(int channels) {
    for(int i=0; i<channels; i++) {
        this->channels = channels;
        media_container.append(new AGMediaContainer(inst, this));
        }
    return true;
}


/*!
 * Adjusts volume of each created channel
 */
bool SoundManager::setVolume(unsigned int volume) {
    int i;
    /*for(i=0; i<this->channels; i++) {
        this->media_output[i]->setVolume(volume);
    }*/

    // testing
    for(i=0; i<media_container.length(); i++) {
        media_container.at(i)->setVolume(volume);
    }
    //qDebug() << identifier << "volume" << volume << "on" << i << "objects";
    return true;
}


/*!
 * Creates library directory if needed, refreshes database
 * todo: remove dead entries from library
 */
bool SoundManager::rescanLibrary() {
    QSqlQuery query;
    QString query_string = QString("SELECT id, path FROM %1").arg(library_identifier);
    query.exec(query_string);

    int i = 0;
    while(query.next()) {
        qApp->processEvents();
        library_tracks << query.value(1).toString();
    }

    QDir library_dir(path);
    if(!library_dir.exists()) {
        if(!library_dir.mkdir(path)) {
            qDebug() << "Creating library directory failed";
        }
    }

    QStringList files_missing = QStringList(library_tracks);
    QStringList files(scanLibraryDirectory(this->path));

    int p = 0;
    progress_bar->setRange(0, files.count());
    progress_bar->show();

    for(int m=0; m<files.count(); m++) {
        qApp->processEvents();

        p++;
        progress_bar->setValue(p);

        db.transaction();
        if(!library_tracks.contains(files.at(m))) {
            QFileInfo file_info(absoluteFilePath(files.at(m)));
            library_model->addTrack(files.at(m), file_info.lastModified(), getTag(files.at(m), ARTIST), getTag(files.at(m), ALBUM), getTag(files.at(m), TITLE));
        }
        db.commit();
        library_model->select();

        // Remove file from missing file list
        files_missing.removeAll(files.at(m));

    }

    // Remove missing files in database
    db.transaction();
    foreach(QString file, files_missing) {
        QSqlQuery missing_query = QSqlQuery();
        missing_query.prepare(QString("DELETE FROM %1 WHERE path = :path").arg(library_model->identifier));
        missing_query.bindValue(":path", file);
        missing_query.exec();
    }
    db.commit();
    library_model->select();

    // Update tags in database
    query_string = QString("SELECT `id`, `path`, `last-change` FROM %1").arg(library_identifier);
    query.exec(query_string);

    while(query.next()) {
        QString file = absoluteFilePath(query.value(1).toString());
        QFileInfo file_info(file);
        unsigned int last_modified = query.value(2).toUInt();
        unsigned int file_modified = file_info.lastModified().toTime_t();
        if(file_modified > last_modified) {
            QString file_mod_string = QString("%1").arg(file_modified);
            QSqlQuery inner_query;
            QString inner_query_string = QString("UPDATE %1 SET `last-change` = \"%2\", `artist` = \"%3\", `album` = \"%4\", `title` = \"%5\" WHERE `id` = \"%6\"").arg(library_identifier, file_mod_string, getTag(query.value(1).toString(), ARTIST), getTag(query.value(1).toString(), ALBUM), getTag(query.value(1).toString(), TITLE), query.value(0).toString());
            inner_query.exec(inner_query_string);
            qDebug() << identifier << query.value(1).toString() << "updated";
        }
    }
    //library_model->select();

    progress_bar->hide();
    progress_bar->setValue(0);

}


/*!
 * recursively scans a directory and returns relative filepath
 */
QStringList SoundManager::scanLibraryDirectory(QString dir) {

    QDir dirscan(dir);

    QStringList files(dirscan.entryList());
    QStringList files_accepted;

    for(int k=0; k<files.count(); k++) {
        if(files.at(k) == "." || files.at(k) == "..") {
            continue;
        }
        QString file_full_path = QString("%1/%2").arg(dir, files.at(k));
        QFileInfo file_info = QFileInfo(file_full_path);
        if(file_info.isFile() && ACCEPTED_MIMETYPES.contains(file_info.suffix())) {
            files_accepted << relativeFilePath(file_full_path);
        } else if(file_info.isDir()) {
            files_accepted << scanLibraryDirectory(file_full_path);
        }
    }

    return files_accepted;
}


/*!
 * Returns tag for file for chosen field.
 */
QString SoundManager::getTag(QString file, int field) {
    QString full_path = absoluteFilePath(file);

    #ifdef _WIN32
        TagLib::FileRef file_tag(reinterpret_cast<const wchar_t*>(full_path.constData()));
    #else
        TagLib::FileRef file_tag(full_path.toAscii());
    #endif

    QString tag;
    TagLib::String field_taglib = "";
    if(file_tag.isNull() == false) {
        if(field == ARTIST) {
            field_taglib = file_tag.tag()->artist();
        } else if(field == ALBUM) {
            field_taglib = file_tag.tag()->album();
        } else if(field == TITLE) {
            field_taglib = file_tag.tag()->title();
        }
        tag = TStringToQString(field_taglib);
    } else {
        tag = QString();
    }
    return tag;
}


/*!
 * Converts relative to absolute filepath
 */
QString SoundManager::absoluteFilePath(QString relative) {
    return path + relative;
}


/*!
 * Converts absolute to relative filepath
 */
QString SoundManager::relativeFilePath(QString absolute) {
    return absolute.remove(0, path.length());
}



SoundManager::~SoundManager() {
    for(int i=0; i<media_container.length(); i++) {
        delete media_container.at(i);
    }
    delete inst;
    delete objects_tracks_model;
    delete objects_model;
    delete library_model;
}
