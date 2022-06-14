TEMPLATE = app

include( $$PWD/../../config_build.pri )

QT += testlib
#QT -= gui

CONFIG += qt console warn_on depend_includepath testcase
CONFIG -= app_bundle


# ##############################################################################
## External libs
# ##############################################################################

# Catch2 test framework
INCLUDEPATH += $$PWD/../common/
HEADERS     += $$PWD/../common/catch2/catch.hpp


# ##############################################################################
## Internal libs
# ##############################################################################

# root directory of the main project
INCLUDEPATH += $$PWD/../../src/


DIR_ENEDISTICLIB=$$OUT_PWD/../../src/libs/enedisTIC-lib
win32:CONFIG(release, debug|release):       LIBS += -L$$DIR_ENEDISTICLIB/out/ -lenedisTIC
else:win32:CONFIG(debug, debug|release):    LIBS += -L$$DIR_ENEDISTICLIB/out/ -lenedisTIC_d
else:unix: CONFIG(debug, debug|release):    LIBS += -L$$DIR_ENEDISTICLIB/out/ -lenedisTIC_d
else:unix:CONFIG(release, debug|release):   LIBS += -L$$DIR_ENEDISTICLIB/out/ -lenedisTIC

INCLUDEPATH += $$DIR_ENEDISTICLIB/include
DEPENDPATH  += $$DIR_ENEDISTICLIB/out
#POST_TARGETDEPS  += $$DIR_ENEDISTICLIB/out/libenedisTIC_d.a



# ##############################################################################
## Sources
# ##############################################################################


SOURCES +=  \
    src/main.cpp \
#    src/tst_mytestcase.cpp
#    src/InfluxMeasurement_tst.cpp \

HEADERS += \
    src/testrunner.h \
#    src/tst_MyTestCase.h
#    src/InfluxMeasurement_tst.h \
