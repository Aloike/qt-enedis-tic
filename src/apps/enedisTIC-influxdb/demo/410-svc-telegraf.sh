#!/bin/bash

set -e
# set -x

source bash/functions.sh
source bash/log.bash

source variables.sh
source influxdb-tokens.env

THIS_SCRIPT_RSRC_DIR="svc-telegraf.d"



#
# Prepare the container execution
#
LOG_INFO "Prepare the container execution..."
LOG_LEVEL_INC

	# LOG_INFO "Create required directories..."
	# LOG_LEVEL_INC

	# if [ ! -d "${SVC_GRAFANA_DIR_PERSISTENTDATA}" ]
	# then
	# 	LOG_INFO "Create the persistent data dir..."
	# 	mkdir -p -v -m 777 ${SVC_GRAFANA_DIR_PERSISTENTDATA}
	# fi

	# # LOG_INFO "Set the persistent data dir owner..."
	# # chown -R 472:0 ${THIS_SCRIPT_RSRC_DIR}/data

	# LOG_INFO "Done creating required directories."
	# LOG_LEVEL_DEC
	

	LOG_INFO "Pull the container image tagged '${SVC_TELEGRAF_CONTAINER_IMAGENAME}:${SVC_TELEGRAF_CONTAINER_IMAGEVERSION}'..."
	LOG_LEVEL_INC

		docker pull \
			${SVC_TELEGRAF_CONTAINER_IMAGENAME}:${SVC_TELEGRAF_CONTAINER_IMAGEVERSION}

	LOG_INFO "Done pulling the image."
	LOG_LEVEL_DEC


LOG_INFO "Done preparing the container execution."
LOG_LEVEL_DEC


#
# Start the container
#
LOG_INFO "Start the container..."
LOG_LEVEL_INC

F_container_remove ${SVC_TELEGRAF_CONTAINER_NAME}
docker run \
	--detach \
	--name=${SVC_TELEGRAF_CONTAINER_NAME} \
	--net=${DOCKER_NETWORK_NAME} \
	-v $PWD/${THIS_SCRIPT_RSRC_DIR}/telegraf.conf:/etc/telegraf/telegraf.conf:ro \
	--env-file=variables.sh \
	-e DEMO_NAME=${DEMO_NAME} \
	-e CONTAINER_NAME=${SVC_TELEGRAF_CONTAINER_NAME} \
	-e INFLUXDB_HOST=${INFLUXDB_HOST} \
	-e INFLUXDB_PORT=${INFLUXDB_PORT} \
	-e INFLUXDB_ORG=${INFLUXDB_ORG} \
	-e INFLUXDB_TOKEN=${SVC_TELEGRAF_INFLUXDB_TOKEN} \
	-e INFLUXDB_BUCKET=${SVC_TELEGRAF_INFLUXDB_BUCKET} \
	-e PORT_LISTEN_INFLUXDB=${SVC_TELEGRAF_PORT_LISTEN_INFLUXDB} \
	--publish ${SVC_TELEGRAF_PORT_LISTEN_INFLUXDB}:${SVC_TELEGRAF_PORT_LISTEN_INFLUXDB} \
	${SVC_TELEGRAF_CONTAINER_IMAGENAME}:${SVC_TELEGRAF_CONTAINER_IMAGEVERSION}

LOG_INFO "Container is running."
LOG_LEVEL_DEC


exit $?
