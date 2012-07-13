CONFIG += warn_off
QT += core gui sql network

win32:INCLUDEPATH += C:/lib/taglib-1.7/include C:/lib/vlc-2.0.0/sdk/include
win32:LIBS += C:/lib/taglib-1.7/taglib/libtag.dll.a C:/lib/vlc-2.0.0/sdk/lib/libvlc.dll.a

unix:!macx:LIBS += -L/usr/lib/ -lvlc -ltag
unix:!macx:INCLUDEPATH += /usr/include
unix:!macx:DEPENDPATH += /usr/include

macx:LIBS += -L/usr/local/lib -ltag -L/Applications/VLC.app/Contents/MacOS/lib -lvlc
macx:INCLUDEPATH += /usr/local/include /Applications/VLC.app/Contents/MacOS/include
macx:DEPENDPATH += /usr/local/include /Applications/VLC.app/Contents/MacOS/include

TARGET = Yonder
TEMPLATE = app
SOURCES += main.cpp ambiencegenerator.cpp soundmanager.cpp \
    musicmanager.cpp \
    ambienceeditor.cpp \
    resourcebrowser.cpp \
    hotkeysmanager.cpp \
    agmediacontainer.cpp \
    singleshotmanager.cpp \
    atmospheremanager.cpp \
    sfxmanager.cpp \
    projectselector.cpp \
    delegate/qdoublespinboxdelegate.cpp \
    delegate/agtagbyiddelegate.cpp \
    delegate/agresourcedelegate.cpp \
    delegate/aghotkeyactiondelegate.cpp \
    view/singleshotobjectstracksview.cpp \
    view/singleshotlibraryview.cpp \
    view/sfxobjectstracksview.cpp \
    view/sfxlibraryview.cpp \
    view/musicplaylisttracksview.cpp \
    view/musiclibraryview.cpp \
    view/hotkeyslibraryspecialview.cpp \
    view/hotkeyslibrarysingleshotview.cpp \
    view/hotkeyslibrarysfxview.cpp \
    view/hotkeyslibrarymusicview.cpp \
    view/hotkeyslibraryatmosphereview.cpp \
    view/hotkeysactionsview.cpp \
    view/atmosphereobjectstracksview.cpp \
    view/atmospherelibraryview.cpp \
    view/agqpushbutton.cpp \
    view/agpreviewpushbutton.cpp \
    view/qlineeditfilter.cpp \
    model/objectstracksmodel.cpp \
    model/objectsmodel.cpp \
    model/librarymodel.cpp
HEADERS += ambiencegenerator.h soundmanager.h \
    musicmanager.h \
    ambienceeditor.h \
    resourcebrowser.h \
    hotkeysmanager.h \
    agmediacontainer.h \
    singleshotmanager.h \
    atmospheremanager.h \
    sfxmanager.h \
    projectselector.h \
    delegate/qdoublespinboxdelegate.h \
    delegate/agtagbyiddelegate.h \
    delegate/agresourcedelegate.h \
    delegate/aghotkeyactiondelegate.h \
    view/singleshotobjectstracksview.h \
    view/singleshotlibraryview.h \
    view/sfxobjectstracksview.h \
    view/sfxlibraryview.h \
    view/musicplaylisttracksview.h \
    view/musiclibraryview.h \
    view/hotkeyslibraryspecialview.h \
    view/hotkeyslibrarysingleshotview.h \
    view/hotkeyslibrarysfxview.h \
    view/hotkeyslibrarymusicview.h \
    view/hotkeyslibraryatmosphereview.h \
    view/hotkeysactionsview.h \
    view/atmosphereobjectstracksview.h \
    view/atmospherelibraryview.h \
    view/agqpushbutton.h \
    view/agpreviewpushbutton.h \
    view/qlineeditfilter.h \
    model/objectstracksmodel.h \
    model/objectsmodel.h \
    model/librarymodel.h
FORMS += ambiencegenerator.ui \
    ambienceeditor.ui \
    resourcebrowser.ui \
    projectselector.ui

RESOURCES += \
    yonder.qrc

RC_FILE = yonder.rc

OTHER_FILES += \
    data/yonder.svg \
    data/resource.sql \
    data/resource.db \
    icon/yonder.ico \
    icon/yonder-256x256.png \
    icon/yonder-128x128.png \
    icon/yonder-64x64.png \
    icon/yonder-32x32.png \
    icon/yonder-16x16.png \
    icon/splash.png \
    icon/package-x-generic.png \
    icon/media-skip-forward.png \
    icon/media-skip-backward.png \
    icon/media-seek-forward.png \
    icon/media-seek-backward.png \
    icon/media-playback-stop.png \
    icon/media-playback-start.png \
    icon/media-playback-pause.png \
    icon/icon-special.png \
    icon/icon-singleshot.png \
    icon/icon-singleshot-start.png \
    icon/icon-sfx.png \
    icon/icon-sfx-start.png \
    icon/icon-music.png \
    icon/icon-music-start.png \
    icon/icon-hotkeys.png \
    icon/icon-hotkeys-start.png \
    icon/icon-atmosphere.png \
    icon/icon-atmosphere-start.png \
    icon/folder.png \
    icon/edit-delete.png \
    icon/edit-clear.png \
    icon/document-new.png \
    icon/audio-x-generic.png \
    data/style.css \
    data/Ostrich Regular.ttf \
    data/manual/yonder.png \
    data/manual/sfx-concept.svg \
    data/manual/sfx-concept.png \
    data/manual/resourcebrowser.png \
    data/manual/index.htm \
    data/manual/ambienceeditor-hotkeys.png
