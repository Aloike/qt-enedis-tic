#!/bin/bash

source bash/colors.bash
source bash/functions.sh
source bash/log.bash

source variables.sh


# set -e
# set -x


# ------------------------------------------------------------------------------
# Prompt a warning
# ------------------------------------------------------------------------------

echo ''
echo '!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!'
echo "WARNING: IT WILL REMOVE ALL LOCAL DATA FROM THE DISK!!!"
echo '!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!'
echo ''
while true; do
	read -p 'Do you *really* want to flush this project? [y/N]: ' yn
	case $yn in
		[Yy]* )	echo "OK, let's go.";
			break
			;; #< Stop the while loop.

		[Nn]* )	exit
			;;

		* )	echo "Please answer yes or no.";;
	esac
done


# ------------------------------------------------------------------------------
# Clean Docker environment
# ------------------------------------------------------------------------------
LOG_INFO "Clean Docker environment..."
LOG_LEVEL_INC

bash clean.sh

LOG_LEVEL_DEC


# ------------------------------------------------------------------------------
# Remove persistent data
# ------------------------------------------------------------------------------
LOG_INFO "Remove persistent data..."
LOG_LEVEL_INC

LOG_INFO "Prune Docker volumes..."
docker volume prune --force

LOG_INFO "Remove persistent volumes rootdir..."
rm -rvf "${DOCKER_VOLUMES_ROOTDIR}"

LOG_LEVEL_DEC


# ------------------------------------------------------------------------------
# Reset local files
# ------------------------------------------------------------------------------
LOG_INFO "Reset local files..."
LOG_LEVEL_INC

git checkout -- influxdb-tokens.env

LOG_LEVEL_DEC


exit $?
