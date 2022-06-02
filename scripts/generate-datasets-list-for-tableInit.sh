#!/bin/bash

for lType in `ls -1 src/core/comm/protocol/tic/datasets/standard/*.h \
        |   sort \
        |   sed -e 's@^.*/\(.*\)\.h$@\1@'`
    do
        echo "    M_TABLEITEMS_FROM_DATASET( p_table, ERow${lType}, ${lType} )"
    done
