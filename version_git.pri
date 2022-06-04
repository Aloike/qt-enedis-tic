###############################################################################
#   @file version_git.pri
#   @date   2013-06-18  Tue.
#
#   @brief  To generate a header containing the version of a software using git
#
#   This file, when included to a project .pro file, will generate a header
#   containing different variables such as the GIT description, the build date,
#   etc.
#   To use it, just do a include(version_git.pri) in your .pro file.
#   When at least one build has been done, a file named Version.h (by default)
#   will appear, containing the generated constants.
#
###############################################################################

contains( CONFIG, VERSION_GIT_PRI_INCLUDED ) {
#     message( "version_git.pri already included" )
} else {

###############################################################################
###############################################################################
#   Variables that you may have to edit depending on your project / platform
###############################################################################

VER_MAJ = 0
VER_MIN = 0
VER_PAT = 0
VERSION =$${VER_MAJ}.$${VER_MIN}.$${VER_PAT}

# SVN_REVISION holds what the command "svnversion -n ." return. May depend on
# your system configuration

#SVN_REVISION = $$system("svnversion -n .") # Directly in the command line

# VERSION_OUTPUT_FILE points to the destination file where the constants will
#be written

VERSION_OUTPUT_FILE=$$PWD/src-autogen/Version.h

###############################################################################
###############################################################################


unix {

target_gitrev.target    =   target_gitrev

# Create the destination directory
target_gitrev.commands  +=   if [ ! -d \"$\(shell dirname $$VERSION_OUTPUT_FILE\)\" ]; then mkdir -p \"$\(shell dirname $$VERSION_OUTPUT_FILE\)\"; fi

# To erase the old version file
target_gitrev.commands  +=  $$escape_expand(\\n\\t) #to go to next makefile line
target_gitrev.commands  +=   echo \'/* Auto-generated file ! */\n\' > $$VERSION_OUTPUT_FILE

target_gitrev.commands  +=  $$escape_expand(\\n\\t) #to go to next makefile line
target_gitrev.commands  +=  (echo \"\\043ifndef VERSION_H\" >> $$VERSION_OUTPUT_FILE)
target_gitrev.commands  +=  $$escape_expand(\\n\\t) #to go to next makefile line
target_gitrev.commands  +=  (echo \"\\043define VERSION_H\\n\" >> $$VERSION_OUTPUT_FILE)

# The major version number
target_gitrev.commands  +=  $$escape_expand(\\n\\t) #to go to next makefile line
target_gitrev.commands  +=  echo \'const QString VERSION_MAJOR\(\"$$VER_MAJ\"\);\' >> $$VERSION_OUTPUT_FILE

# The minor version number
target_gitrev.commands  +=  $$escape_expand(\\n\\t) #to go to next makefile line
target_gitrev.commands  +=  echo \'const QString VERSION_MINOR\(\"$$VER_MIN\"\);\' >> $$VERSION_OUTPUT_FILE

# The patch version number
target_gitrev.commands  +=  $$escape_expand(\\n\\t) #to go to next makefile line
target_gitrev.commands  +=  echo \'const QString VERSION_PATCH\(\"$$VER_PAT\"\);\' >> $$VERSION_OUTPUT_FILE

# The GIT version
target_gitrev.commands  +=  $$escape_expand(\\n\\t) #to go to next makefile line
target_gitrev.commands  +=  echo \"const QString VERSION_CVS\(\\\"$\(shell  git describe --long --tags --always --dirty)\\\"\);\" >> $$VERSION_OUTPUT_FILE

# The Build date
target_gitrev.commands  +=  $$escape_expand(\\n\\t) #to go to next makefile line
target_gitrev.commands  +=  echo \"const QString VERSION_BUILD\(\\\"$\(shell  date +%Y%m%d%H%M%S)\\\"\);\" >> $$VERSION_OUTPUT_FILE


target_gitrev.commands  +=  $$escape_expand(\\n\\t) #to go to next makefile line
target_gitrev.commands  +=  (echo \"\\n\\043endif /*< VERSION_H */\" >> $$VERSION_OUTPUT_FILE)


#&& echo '#ifndef __VERSION_H__' >> Version.h    \
#&& echo '#define __VERSION_H__' >> Version.h    \
#&& echo '#endif'    >> Version.h


# Add the created target to the qmake ones.
QMAKE_EXTRA_TARGETS += target_gitrev
PRE_TARGETDEPS      += target_gitrev

}else:win32{

target_gitrev.target    =   target_gitrev

# To erase the old version file
target_gitrev.commands  =   (echo "/* Auto-generated file ! */" > $$VERSION_OUTPUT_FILE )
target_gitrev.commands  +=  &&  (echo "$${LITERAL_HASH}ifndef VERSION_H" >> $$VERSION_OUTPUT_FILE )
target_gitrev.commands  +=  &&  (echo "$${LITERAL_HASH}define VERSION_H" >> $$VERSION_OUTPUT_FILE )
target_gitrev.commands  +=  &&  (echo.>>$$VERSION_OUTPUT_FILE)
target_gitrev.commands  +=  &&  (echo "$${LITERAL_HASH}include ^<QString^>">>$$VERSION_OUTPUT_FILE)
target_gitrev.commands  +=  &&  (echo. >>$$VERSION_OUTPUT_FILE)

# The major version number
target_gitrev.commands  +=  &&  (echo "const QString VERSION_MAJOR = \"$$VER_MAJ\";">>$$VERSION_OUTPUT_FILE)

## The minor version number
target_gitrev.commands  +=  &&  (echo "const QString VERSION_MINOR = \"$$VER_MIN\";">>$$VERSION_OUTPUT_FILE)

## The patch version number
target_gitrev.commands  +=  &&  (echo "const QString VERSION_PATCH = \"$$VER_PAT\";">>$$VERSION_OUTPUT_FILE)

## The GIT version
target_gitrev.commands  +=  &&  (echo "const QString VERSION_CVS = \"$(shell git --git-dir $$PWD/../.git --work-tree $$PWD../ describe --long --tags --always --dirty)\";">>$$VERSION_OUTPUT_FILE)

## The Build date
target_gitrev.commands  +=  &&  (echo "const QString VERSION_BUILD = \"$(shell echo %date:~6,4%%date:~3,2%%date:~0,2%)$(shell cmd /v:on /c \"set lTime=%time: =0% && echo !lTime:~0,2!!lTime:~3,2!!lTime:~6,2!\")\";">>$$VERSION_OUTPUT_FILE)


target_gitrev.commands  +=  &&  (echo. >>$$VERSION_OUTPUT_FILE)
target_gitrev.commands  +=  &&  (echo "$${LITERAL_HASH}endif /*^< VERSION_H */" >> $$VERSION_OUTPUT_FILE )

# Add the created target to the qmake ones.
QMAKE_EXTRA_TARGETS += target_gitrev
PRE_TARGETDEPS      += target_gitrev
}


}   #<  VERSION_GIT_PRI_INCLUDED
