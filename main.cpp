#include <QtGui/QApplication>
#include <ambiencegenerator.h>

QString NAME = "Yonder";
QString VERSION = "1.1";
QString ACTION_KEY = "";
QString AUTHOR = "Dominik Seemann";
QString WEBADDRESS = "http://yonderfx.com/";
QString ACCEPTED_MIMETYPES = "mp3 ogg flac aac wav";

void debugHandler(QtMsgType type, const char *msg)
{
    QByteArray err;
    QDateTime time = QDateTime::currentDateTime();
    err.append(time.toString("[yy.MM.dd hh:mm:ss] "));
    QFile debug_file(QString("%1/debug.log").arg(QDir::homePath()));
    debug_file.open(QIODevice::Append);
    switch (type) {
    case QtDebugMsg:
        err.append("DEBUG: ");
        break;
    case QtWarningMsg:
        err.append("WARNING: ");
        break;
    case QtCriticalMsg:
        err.append("CRITICAL: ");
        break;
    case QtFatalMsg:
        err.append("FATAL: ");
        abort();
    }
    err.append(msg);
    err.append("\n");
    debug_file.write(err);
    debug_file.close();
}

void noHandler(QtMsgType type, const char *msg)
{

}

int main(int argc, char *argv[])
{
    if(argc > 1 && QString(argv[1]) == "debug") {
        qInstallMsgHandler(debugHandler);
    } else if(argc > 1 && QString(argv[1]) == "debug-console") {

    } else {
        qInstallMsgHandler(noHandler);
    }

    qDebug() << QString("%1 %2").arg(NAME, VERSION);

    QApplication a(argc, argv);

    a.setOrganizationName(NAME);
    a.setOrganizationDomain(WEBADDRESS);
    a.setApplicationName(NAME);

    QPixmap splash(":/application/icons/splash.png");
    QSplashScreen *splash_screen = new QSplashScreen(splash);
    splash_screen->show();
    AmbienceGenerator w(splash_screen);
    w.show();
    splash_screen->finish(&w);

    return a.exec();
}
