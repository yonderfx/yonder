#ifndef FRAMEHELP_H
#define FRAMEHELP_H

#include <QMessageBox>
#include <QDebug>

#ifdef Q_OS_WIN
#include <taglib.h>
#else
#include <taglib/taglib.h>
#endif

#include <frameobject.h>

namespace Ui {
class FrameHelp;
}

class FrameHelp : public FrameObject
{
    Q_OBJECT
    
public:
    explicit FrameHelp(QWidget *parent = 0);
    ~FrameHelp();
    
private:
    Ui::FrameHelp *ui;

private slots:
    void showAbout();
};

#endif // FRAMEHELP_H
