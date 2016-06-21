TEMPLATE = app

QT += qml quick declarative
CONFIG += c++11

SOURCES += main.cpp \
    Engine/player.cpp \
    Engine/deck.cpp \
    Engine/card.cpp \
    Engine/engine.cpp \
    Interface/mainwindow.cpp
QMAKE_CXXFLAGS += -fPIC -fpic

RESOURCES += Resources/qml.qrc \
    Resources/deck.qrc \
    Resources/images.qrc

# Additional import path used to resolve QML modules in Qt Creator's code model
QML_IMPORT_PATH =

# Default rules for deployment.
include(deployment.pri)

DISTFILES +=

HEADERS += \
    Engine/player.h \
    Engine/deck.h \
    Engine/card.h \
    Engine/engine.h \
    Interface/mainwindow.h

