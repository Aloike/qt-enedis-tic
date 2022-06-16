#!/bin/bash

lIsFirst=true

for lType in `ls -1 src/core/comm/protocol/tic/datasets/standard/*.h \
        |   sort \
        |   sed -e 's@^.*/\(.*\)\.h$@\1@'`
do
	if [[ ${lIsFirst} == true ]]
	then
		echo -n "        "
	else
		echo -n "        else "
	fi
	echo "if(lDatasetPtr->label() == TIC::Datasets::${lType}::LABEL )"
	echo "        {"
	echo "            lRow    = ERow${lType};"
	echo "        }"
	lIsFirst=false
done


echo "        else"
echo "        {"
echo "            TRACE_ERR("
echo "                \"Unknown label '%s'!\","
echo "                lDatasetPtr->label().c_str()"
echo "            )"
echo "            continue;"
echo "        }"

exit 0
