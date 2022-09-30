TEMPLATE    = subdirs


OTHER_FILES += LICENSE.md
OTHER_FILES += README.md


SUBDIRS	+= src/apps/enedisTIC-influxdb/enedisTIC-influxdb.pro
SUBDIRS	+= src/apps/enedisTIC-ui/enedisTIC-ui.pro
SUBDIRS	+= src/libs/enedisTIC-lib/enedisTIC-lib.pro
SUBDIRS	+= tests/unit/enedisTIC-tests-unit.pro


# where to find the sub projects - give the folders
enedisTIC-lib.subdir    = src/libs/enedisTIC-lib
enedisTIC-tests-unit    = tests/unit/enedisTIC-tests-unit.pro
enedisTIC-ui.subdir     = src/apps/enedisTIC-ui


# what subproject depends on others
enedisTIC-influxdb.depends      += enedisTIC-lib
enedisTIC-ui.depends            += enedisTIC-lib
enedisTIC-tests-unit.depends    += enedisTIC-lib
