#ifndef MUSICMANAGER_H
#define MUSICMANAGER_H

#include <model/manager/mediamanager.h>
#include <model/manager/soundmanager.h>

class MusicManager : public SoundManager
{
Q_OBJECT
public:
    MusicManager(QString project_path, QSqlDatabase db, MediaManager *media, QObject *parent);

public slots:
    bool enqueue();
    void next();
    void playPause();
    void play();
    void pause();
};

#endif // MUSICMANAGER_H
