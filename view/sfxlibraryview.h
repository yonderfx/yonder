#ifndef SFXLIBRARYVIEW_H
#define SFXLIBRARYVIEW_H

#include <QTableView>
#include <QMimeData>
#include <QDrag>

class SfxLibraryView : public QTableView
{
    Q_OBJECT
public:
    explicit SfxLibraryView(QWidget *parent = 0);

protected:
    void startDrag(QMouseEvent *event);
    void mouseMoveEvent(QMouseEvent *event);
};

#endif // SFXLIBRARYVIEW_H
