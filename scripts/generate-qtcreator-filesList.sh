#!/bin/bash

SEARCHPATH=src/

for file in `find ${SEARCHPATH} -iname '*.ui'|sort`
do
	echo -e "FORMS\t+= ${file}"
done

echo ""

for file in `find ${SEARCHPATH} -iname '*.h'|sort`
do
	echo -e "HEADERS\t+= ${file}"
done

echo ""

for file in `find ${SEARCHPATH} -iname '*.cpp'|sort`
do
	echo -e "SOURCES\t+= ${file}"
done

exit 0
