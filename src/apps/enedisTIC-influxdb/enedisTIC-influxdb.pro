TEMPLATE    = app
TARGET      = enedisTIC-influxdb

include( $$PWD/../../../config_build.pri )
include( $$PWD/../../../version_git.pri )

# ##############################################################################
## Declaration of Qt modules used in the project
# ##############################################################################
QT  +=  core
#QT  +=  gui
QT  +=  serialport
#QT  +=  xml

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets


# ##############################################################################
## External libs
# ##############################################################################

CONFIG	+= c++17


DIR_LIBINFLUXCXX=$$OUT_PWD/../../../src-ext/influxdb-cxx/
LIBS += -L$$DIR_LIBINFLUXCXX/build/src/ -lInfluxDB

INCLUDEPATH += $$DIR_LIBINFLUXCXX/include
INCLUDEPATH += $$DIR_LIBINFLUXCXX/build/src/
DEPENDPATH  += $$DIR_LIBINFLUXCXX/build/src/


# ##############################################################################
## Internal libs
# ##############################################################################

DIR_ENEDISTICLIB=$$OUT_PWD/../../libs/enedisTIC-lib
win32:CONFIG(release, debug|release):       LIBS += -L$$DIR_ENEDISTICLIB/out/ -lenedisTIC
else:win32:CONFIG(debug, debug|release):    LIBS += -L$$DIR_ENEDISTICLIB/out/ -lenedisTIC_d
else:unix: CONFIG(debug, debug|release):    LIBS += -L$$DIR_ENEDISTICLIB/out/ -lenedisTIC_d
else:unix:CONFIG(release, debug|release):   LIBS += -L$$DIR_ENEDISTICLIB/out/ -lenedisTIC

INCLUDEPATH += $$DIR_ENEDISTICLIB/include
DEPENDPATH  += $$DIR_ENEDISTICLIB/out


# ##############################################################################
## Sources
# ##############################################################################

INCLUDEPATH += $$PWD/src

include( $$PWD/src.pri )

OTHER_FILES += LICENSE.md
OTHER_FILES += README.md
