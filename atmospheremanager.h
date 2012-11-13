#ifndef ATMOSPHEREMANAGER_H
#define ATMOSPHEREMANAGER_H

#include <QtCore>

#include <mediamanager.h>
#include <soundmanager.h>

class AtmosphereManager: public SoundManager
{
Q_OBJECT
public:
    AtmosphereManager(QString project_path, QSqlDatabase db, MediaManager *media, QObject *parent);

    void createChannels();

    QList<QStringList> objects;

public slots:
    void createObjectsList();
    void playPause(int channel);
    void play(int channel);
    void pause(int channel);
    bool enqueue(int channel);
};

#endif // ATMOSPHEREMANAGER_H