#!/bin/bash

set -e  #!< Stop the script on error.
# set -x

source bash/functions.sh
source bash/log.bash

source variables.sh




LOG_INFO "Create directories"
LOG_LEVEL_INC

# F_createDirIfNotExists "${SVC_DATABASE_CONFDIR_DOCKERVOLUME_LOCALDIR}"
F_createDirIfNotExists "${SVC_DATABASE_DATADIR_DOCKERVOLUME_LOCALDIR}"

LOG_INFO "Done create directories."
LOG_LEVEL_DEC


#
# Start the container
#
LOG_INFO "Pull the InfluxDB container image tagged '${SVC_DATABASE_CONTAINER_IMAGENAME}:${SVC_DATABASE_CONTAINER_IMAGEVERSION}'..."
LOG_LEVEL_INC

docker pull ${SVC_DATABASE_CONTAINER_IMAGENAME}:${SVC_DATABASE_CONTAINER_IMAGEVERSION}

LOG_INFO "Done pulling the image."
LOG_LEVEL_DEC


LOG_INFO "Start the container..."
LOG_LEVEL_INC

docker run \
	-d \
	--name=${SVC_DATABASE_CONTAINER_NAME} \
	--net=${DOCKER_NETWORK_NAME} \
	--publish ${SVC_DATABASE_HTTPSERVICE_PORT}:${SVC_DATABASE_HTTPSERVICE_PORT} \
	-v ${SVC_DATABASE_DATADIR_DOCKERVOLUME_LOCALDIR}:/var/lib/influxdb2 \
	${SVC_DATABASE_CONTAINER_IMAGENAME}:${SVC_DATABASE_CONTAINER_IMAGEVERSION}

LOG_INFO "Container is running."
LOG_LEVEL_DEC


#
# Wait for the database service to be ready
#
LOG_INFO "Check container state..."
LOG_LEVEL_INC

while ! docker exec \
	${SVC_DATABASE_CONTAINER_NAME} \
	influx ping >/dev/null
do
	LOG_DBG "Waiting for the InfluxDB container to be ready..."
	sleep 1
done
LOG_INFO "Container is ready."
LOG_LEVEL_DEC


#
# Proceed to the initial setup of InfluxDB
#
LOG_INFO "Start InfluxDB setup command."
LOG_LEVEL_INC

docker exec \
	${SVC_DATABASE_CONTAINER_NAME} \
	influx setup \
	--org ${INFLUXDB_ORG} \
	--username ${INFLUXDB_ADMIN_USERNAME} \
	--password ${INFLUXDB_ADMIN_PASSWORD} \
	--token ${INFLUXDB_ADMIN_TOKEN} \
	--bucket ${INFLUXDB_PRIMARYBUCKET} \
	--retention 0 \
	--force

LOG_INFO "InfluxDB setup done."
LOG_LEVEL_DEC


exit $?
