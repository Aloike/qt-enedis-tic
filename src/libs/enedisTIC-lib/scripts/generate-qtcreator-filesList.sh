#!/bin/bash

DIR_HEADERS=include
DIR_SOURCES=src

#FILE_OUTPUT=${DIR_SOURCES}/src.pri
FILE_OUTPUT=src.pri
SEARCHPATH+="${DIR_HEADERS}"
SEARCHPATH+=" ${DIR_SOURCES}"


# Halt on error
set -e

#pushd ${DIR_SOURCES}


# Clear output file
echo -n "" > ${FILE_OUTPUT}

for file in `find ${SEARCHPATH} -iname '*.ui'|sort`
do
	echo -e "FORMS\t+= ${file}" >> ${FILE_OUTPUT}
done

echo "" >> ${FILE_OUTPUT}

for file in `find ${SEARCHPATH} -iname '*.h'|sort`
do
	echo -e "HEADERS\t+= ${file}" >> ${FILE_OUTPUT}
done

echo "" >> ${FILE_OUTPUT}

for file in `find ${SEARCHPATH} -iname '*.cpp'|sort`
do
	echo -e "SOURCES\t+= ${file}" >> ${FILE_OUTPUT}
done

#popd

exit 0
