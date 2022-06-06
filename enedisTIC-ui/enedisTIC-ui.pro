TEMPLATE    = app
TARGET      = enedisTIC-ui

include( $$PWD/../config_build.pri )
include( $$PWD/../version_git.pri )

#DEFINES	+= TEST_DATA_FROM_FILE

# ##############################################################################
## Declaration of Qt modules used in the project
# ##############################################################################
QT  +=  core
QT  +=  gui
QT  +=  serialport
#QT  +=  xml

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets


# ##############################################################################
## Internal libs
# ##############################################################################

win32:CONFIG(release, debug|release):       LIBS += -L$$OUT_PWD/../enedisTIC/out/ -lenedisTIC
else:win32:CONFIG(debug, debug|release):    LIBS += -L$$OUT_PWD/../enedisTIC/out/ -lenedisTIC_d
else:unix: CONFIG(debug, debug|release):    LIBS += -L$$OUT_PWD/../enedisTIC/out/ -lenedisTIC_d
else:unix:CONFIG(release, debug|release):   LIBS += -L$$OUT_PWD/../enedisTIC/out/ -lenedisTIC

INCLUDEPATH += $$PWD/../enedisTIC/include
DEPENDPATH += $$PWD/../enedisTIC/out


# ##############################################################################
## Sources
# ##############################################################################

INCLUDEPATH += $$PWD/src

include( $$PWD/src.pri )

OTHER_FILES += LICENSE.md
OTHER_FILES += README.md
