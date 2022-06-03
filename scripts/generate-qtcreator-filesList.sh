#!/bin/bash

FILE_OUTPUT=src.pri
SEARCHPATH=src/


# Clear output file
echo -n "" >> ${FILE_OUTPUT}

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

exit 0
