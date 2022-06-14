TEMPLATE    = lib
TARGET      = enedisTIC
CONFIG += staticlib

include( $$PWD/../../../config_build.pri )
CONFIG += c++11
CONFIG -= qt

DEFINES += LIBENEDISTIC_LIBRARY


# The following define makes your compiler emit warnings if you use
# any Qt feature that has been marked deprecated (the exact warnings
# depend on your compiler). Please consult the documentation of the
# deprecated API in order to know how to port your code away from it.
DEFINES += QT_DEPRECATED_WARNINGS

# You can also make your code fail to compile if it uses deprecated APIs.
# In order to do so, uncomment the following line.
# You can also select to disable deprecated APIs only up to a certain version of Qt.
#DEFINES += QT_DISABLE_DEPRECATED_BEFORE=0x060000    # disables all the APIs deprecated before Qt 6.0.0

# Include sources using the dedicated `pri` file.
include(src.pri)
INCLUDEPATH += $$PWD/include
INCLUDEPATH += $$PWD/include/enedisTIC/
INCLUDEPATH += $$PWD/include/enedisTIC/datasets/
INCLUDEPATH += $$PWD/include/enedisTIC/datasets/historical/
INCLUDEPATH += $$PWD/include/enedisTIC/datasets/standard/
INCLUDEPATH += $$PWD/include/enedisTIC/transport/
INCLUDEPATH += $$PWD/src


# Target to install public headers
public_headers.files = include/*
unix:!android: {
     public_headers.path = $$INSTALL_PREFIX/include
}
INSTALLS += public_headers
