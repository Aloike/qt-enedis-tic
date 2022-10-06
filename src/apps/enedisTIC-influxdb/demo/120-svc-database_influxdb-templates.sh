#!/bin/bash

set -e
# set -x

source bash/functions.sh
source bash/log.bash

source variables.sh
# export $(grep -v '^#' variables.sh | xargs)


DIR_TEMPLATES="$(pwd)/svc-database_influxdb-templates.d"


# ##############################################################################
# ##############################################################################
#
##  @brief  Applies the YAML templates from the templates directory.
##
##  @see    https://www.influxdata.com/blog/downsampling-influxdb-v2-0/
##  @see    https://docs.influxdata.com/influxdb/cloud/reference/cli/influx/task/create/
#
function	F_templates_apply()
{
	LOG_INFO "Apply InfluxDB templates..."
	LOG_LEVEL_INC


	LOG_DBG "Run the utility container"
	# F_container_remove ${INFLUXUTILITYCONTAINER_NAME}
	docker run \
		-v ${DIR_TEMPLATES}:/mnt/templates \
		--env-file=variables.sh \
		--name=${SVC_INFLUXUTILITY_CONTAINER_NAME} \
		--net=${DOCKER_NETWORK_NAME} \
		${SVC_INFLUXUTILITY_CONTAINER_NAME} \
		influx apply \
		--force true \
		--host "http://${SVC_DATABASE_CONTAINER_NAME}:${SVC_DATABASE_HTTPSERVICE_PORT}" \
		--org "${INFLUXDB_ORG}" \
		--token "${INFLUXDB_ADMIN_TOKEN}" \
		--recurse \
		--file /mnt/templates/

	LOG_INFO "Done."
	LOG_LEVEL_DEC
}

# ##############################################################################
# ##############################################################################

function	F_influxdbUtilityContainer_create()
{
	LOG_INFO "Create the container image..."
	LOG_LEVEL_INC

	LOG_DBG "Container name: '${SVC_INFLUXUTILITY_CONTAINER_NAME}'"

	docker build \
		--tag "${SVC_INFLUXUTILITY_CONTAINER_NAME}" \
		- << EOF
FROM ${SVC_INFLUXUTILITY_CONTAINER_IMAGENAME}:${SVC_INFLUXUTILITY_CONTAINER_IMAGEVERSION}
EOF

	LOG_LEVEL_DEC
}

# ##############################################################################
# ##############################################################################

F_influxdbUtilityContainer_create
F_templates_apply
F_container_remove "${SVC_INFLUXUTILITY_CONTAINER_NAME}"

exit $?
