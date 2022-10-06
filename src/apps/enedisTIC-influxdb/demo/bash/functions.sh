#!/bin/bash


# ##############################################################################
# ##############################################################################
#
##  @brief  Simple function to create a directory if it doesn't exist.
#
function	F_container_remove()
{
	pContainer="$1"

	LOG_INFO "Removing container '${pContainer}'..."
	LOG_LEVEL_INC

	if [[ `docker ps -a |grep ${pContainer}|wc -l` -eq "0" ]]
	then
		LOG_DBG "No container to be removed."
	else
		LOG_DBG "Stop the container..."
		docker stop \
			--time 1 \
			${pContainer}

		LOG_DBG "Remove the container..."
		docker rm \
			${pContainer}
	fi

	LOG_LEVEL_DEC
}

# ##############################################################################
# ##############################################################################
#
##  @brief  Simple function to create a directory if it doesn't exist.
#
function	F_createDirIfNotExists()
{
	pDir="$1"

	if [[ -d "${pDir}" ]]
	then
		LOG_INFO "Dir exists: '${pDir}'."
	else
		LOG_INFO "Dir will be created: '${pDir}'."
		# sudo mkdir -pv "${pDir}"
		mkdir -pv "${pDir}"
	fi
}

# ##############################################################################
# ##############################################################################
