###############################################################################
#   @file
#   @brief  Contains Qt project's build configuration
#           (build directories, destination directory,...).
#   @author GOM
###############################################################################


# ##############################################################################
##  Global definitions about this project
# ##############################################################################
#TARGET      = MyProject
TEMPLATE    = app


CONFIG += c++14



# ##############################################################################
## Declaration of Qt modules used in the project
# ##############################################################################
QT  +=  core
QT  +=  gui
QT  +=  serialport
#QT  +=  xml

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets


# The following define makes your compiler emit warnings if you use
# any Qt feature that has been marked deprecated (the exact warnings
# depend on your compiler). Please consult the documentation of the
# deprecated API in order to know how to port your code away from it.
DEFINES += QT_DEPRECATED_WARNINGS

# You can also make your code fail to compile if it uses deprecated APIs.
# In order to do so, uncomment the following line.
# You can also select to disable deprecated APIs only up to a certain version of Qt.
#DEFINES += QT_DISABLE_DEPRECATED_BEFORE=0x060000    # disables all the APIs deprecated before Qt 6.0.0



# ##############################################################################
##  Destination directories configuration
# ##############################################################################

##  @brief  The DESTDIR variable defines where the generated target will be made
##          available.
DESTDIR = out


##  This section defines the prefix of build directories depending on the build
##  mode. It also adds a suffix to the target in debug mode.
CONFIG(release, debug|release) {
    BUILDDIR    = build/release
}else{
    BUILDDIR    = build/debug
    TARGET = $$join(TARGET,,,_d)
}


##  This section defines the build subdirs to group generated objects of the
##  same type in the same directory instead of putting all generated objects in
##  a common directory.
MOC_DIR     = $$BUILDDIR/moc
OBJECTS_DIR = $$BUILDDIR/obj
RCC_DIR     = $$BUILDDIR/rcc
UI_DIR      = $$BUILDDIR/ui


# Default rules for deployment.
qnx: target.path = /tmp/$${TARGET}/bin
else: unix:!android: target.path = /opt/$${TARGET}/bin
!isEmpty(target.path): INSTALLS += target
