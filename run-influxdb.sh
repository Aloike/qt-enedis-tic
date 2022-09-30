#!/bin/sh

export LD_LIBRARY_PATH=/home/gom/projets/EnedisTIC/qt-enedis-tic/src/apps/enedisTIC-influxdb/../../../src-ext/influxdb-cxx//build/src/:/home/gom/projets/EnedisTIC/qt-enedis-tic/src/apps/enedisTIC-influxdb/../../libs/enedisTIC-lib/out/:/usr/lib/x86_64-linux-gnu

./src/apps/enedisTIC-influxdb/out/enedisTIC-influxdb_d

exit $?
