TEMPLATE    = subdirs


OTHER_FILES += LICENSE.md
OTHER_FILES += README.md


SUBDIRS	+= enedisTIC-lib/enedisTIC-lib.pro
SUBDIRS	+= enedisTIC-ui/enedisTIC-ui.pro


# where to find the sub projects - give the folders
enedisTIC-lib.subdir    = enedisTIC-lib
enedisTIC-ui.subdir = enedisTIC-ui


# what subproject depends on others
enedisTIC-ui.depends = enedisTIC-lib
