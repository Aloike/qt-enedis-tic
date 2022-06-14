TEMPLATE    = subdirs


OTHER_FILES += LICENSE.md
OTHER_FILES += README.md


SUBDIRS	+= src/libs/enedisTIC-lib/enedisTIC-lib.pro
SUBDIRS	+= src/apps/enedisTIC-ui/enedisTIC-ui.pro


# where to find the sub projects - give the folders
enedisTIC-lib.subdir    = src/libs/enedisTIC-lib
enedisTIC-ui.subdir = src/apps/enedisTIC-ui


# what subproject depends on others
enedisTIC-ui.depends = enedisTIC-lib
