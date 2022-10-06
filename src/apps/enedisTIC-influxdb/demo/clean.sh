#!/bin/bash

# set -e

source bash/colors.bash
source bash/functions.sh
source bash/log.bash

source variables.sh


# ------------------------------------------------------------------------------
# Remove created containers
# ------------------------------------------------------------------------------
LOG_INFO "Docker - Remove created containers..."
LOG_LEVEL_INC

# F_container_remove  "${GTW_TELEGRAF_DOCKERHOST_CONTAINER_NAME}"
F_container_remove  "${GTW_CONTAINER_NAME}"
F_container_remove  "${SVC_DATABASE_CONTAINER_NAME}"
F_container_remove  "${SVC_GRAFANA_CONTAINER_NAME}"
F_container_remove  "${SVC_INFLUXUTILITY_CONTAINER_NAME}"

LOG_INFO "Done removing created containers."
LOG_LEVEL_DEC


# ------------------------------------------------------------------------------
# Delete the Docker network
# ------------------------------------------------------------------------------
LOG_INFO "Docker - Remove the test network..."
LOG_LEVEL_INC

docker network rm ${DOCKER_NETWORK_NAME}

LOG_INFO "Done removing the test network."
LOG_LEVEL_INC


exit $?
