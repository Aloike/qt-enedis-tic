#!/bin/bash

set -e
# set -x

source bash/functions.sh
source bash/log.bash

source variables.sh



LOG_INFO "Docker - Create our test network..."
LOG_LEVEL_INC

docker network create ${DOCKER_NETWORK_NAME}

LOG_INFO "Done creating our test network."
LOG_LEVEL_INC


exit $?

