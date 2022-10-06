#!/bin/bash

set -e
# set -x

source bash/functions.sh
source bash/log.bash

source variables.sh
source influxdb-tokens.env

THIS_SCRIPT_RSRC_DIR="svc-grafana.d"



#
# Prepare the container execution
#
LOG_INFO "Prepare the container execution..."
LOG_LEVEL_INC

	LOG_INFO "Create required directories..."
	LOG_LEVEL_INC

	if [ ! -d "${SVC_GRAFANA_DIR_PERSISTENTDATA}" ]
	then
		LOG_INFO "Create the persistent data dir..."
		mkdir -p -v -m 777 ${SVC_GRAFANA_DIR_PERSISTENTDATA}
	fi

	# LOG_INFO "Set the persistent data dir owner..."
	# chown -R 472:0 ${THIS_SCRIPT_RSRC_DIR}/data

	LOG_INFO "Done creating required directories."
	LOG_LEVEL_DEC
	

	LOG_INFO "Pull the container image tagged '${SVC_GRAFANA_CONTAINER_IMAGENAME}:${SVC_GRAFANA_CONTAINER_IMAGEVERSION}'..."
	LOG_LEVEL_INC

		docker pull \
			${SVC_GRAFANA_CONTAINER_IMAGENAME}:${SVC_GRAFANA_CONTAINER_IMAGEVERSION}

	LOG_INFO "Done pulling the image."
	LOG_LEVEL_DEC


LOG_INFO "Done preparing the container execution."
LOG_LEVEL_DEC


#
# Start the container
#
LOG_INFO "Start the container..."
LOG_LEVEL_INC

F_container_remove ${SVC_GRAFANA_CONTAINER_NAME}
docker run \
	--detach \
	--name=${SVC_GRAFANA_CONTAINER_NAME} \
	--net=${DOCKER_NETWORK_NAME} \
	-v ${SVC_GRAFANA_DIR_PERSISTENTDATA}:/var/lib/grafana/:rw \
	-v $PWD/${THIS_SCRIPT_RSRC_DIR}/provisioning/dashboards/conf:/etc/grafana/provisioning/dashboards/:ro \
	-v $PWD/${THIS_SCRIPT_RSRC_DIR}/provisioning/dashboards/json:/mnt/grafana/provisioning/dashboards/:ro \
	-v $PWD/${THIS_SCRIPT_RSRC_DIR}/provisioning/dashboards/home.json:/usr/share/grafana/public/dashboards/home.json:ro \
	-v $PWD/${THIS_SCRIPT_RSRC_DIR}/provisioning/datasources:/etc/grafana/provisioning/datasources/:ro \
	-e GF_SECURITY_ADMIN_USER=${SVC_GRAFANA_ADMIN_USER} \
	-e GF_SECURITY_ADMIN_PASSWORD=${SVC_GRAFANA_ADMIN_PASSWORD} \
	-e INFLUXDB_HOST=${INFLUXDB_HOST} \
	-e INFLUXDB_PORT=${INFLUXDB_PORT} \
	-e INFLUXDB_ORG=${INFLUXDB_ORG} \
	-e INFLUXDB_TOKEN=${SVC_GRAFANA_INFLUXDB_TOKEN} \
	--publish ${SVC_GRAFANA_PORT_WEBUI}:${SVC_GRAFANA_PORT_WEBUI} \
	${SVC_GRAFANA_CONTAINER_IMAGENAME}:${SVC_GRAFANA_CONTAINER_IMAGEVERSION}
	# -v $PWD/${THIS_SCRIPT_RSRC_DIR}/provisioning/dashboards/home.json:/etc/grafana/home_dashboard.json:ro \

LOG_INFO "Container is running."
LOG_LEVEL_DEC


exit $?
