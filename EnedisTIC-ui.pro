include( $$PWD/config_build.pri )
include( $$PWD/src/version_git.pri )

DEFINES	+= TEST_DATA_FROM_FILE

INCLUDEPATH += $$PWD/src

include( $$PWD/src.pri )
