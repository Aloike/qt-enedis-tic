#!/bin/bash

set -e

source bash/colors.bash
source bash/log.bash

SCRIPTS_LIST=`find . -iname '*.sh'|sed --quiet -e '/^\.\/[0-9]\{3\}.*\.sh$/p'|sort`

LOG_INFO "Scripts list: \n${SCRIPTS_LIST}"


while read -r lScript
do
	LOG_INFO "Calling ${lScript}"
	LOG_LEVEL_INC

	(source "${lScript}")

	LOG_LEVEL_DEC
done <<< "${SCRIPTS_LIST}"

exit $?
