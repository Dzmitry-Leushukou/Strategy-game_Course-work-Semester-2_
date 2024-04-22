QT       += core gui
QT += opengl
QT += openglwidgets

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets


CONFIG += c++17

# You can make your code fail to compile if it uses deprecated APIs.
# In order to do so, uncomment the following line.
#DEFINES += QT_DISABLE_DEPRECATED_BEFORE=0x060000    # disables all the APIs deprecated before Qt 6.0.0

SOURCES += \
    aabb.cpp \
    block.cpp \
    camera.cpp \
    game.cpp \
    gamewindow.cpp \
    main.cpp \
    mainwindow.cpp \
    view.cpp \
    world.cpp

HEADERS += \
    aabb.h \
    block.h \
    camera.h \
    game.h \
    gamewindow.h \
    mainwindow.h \
    view.h \
    world.h

FORMS += \
    gamewindow.ui \
    mainwindow.ui

# Default rules for deployment.
qnx: target.path = /tmp/$${TARGET}/bin
else: unix:!android: target.path = /opt/$${TARGET}/bin
!isEmpty(target.path): INSTALLS += target

RESOURCES += \
    background_menu.qrc

DISTFILES += \
    Civilization.pro.user \
    README.md \
    resource/background_menu.png
