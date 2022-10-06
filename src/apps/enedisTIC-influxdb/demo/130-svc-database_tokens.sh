#!/bin/bash

set -e
# set -x

source bash/functions.sh
source bash/log.bash

source variables.sh

# ##############################################################################
# ##############################################################################

function	F_influxdb_bucket_getId()
{
	local pBucketName="${1}"

	LOG_INFO "Get ID of bucket '${pBucketName}'..."

	docker exec \
		${SVC_DATABASE_CONTAINER_NAME} \
		influx bucket list\
		--org ${INFLUXDB_ORG} \
		--name ${pBucketName} \
	| tail -n 1 \
	| awk '{print $1}'

		#--username ${INFLUXDB_ADMIN_USERNAME} \
		#--password ${INFLUXDB_ADMIN_PASSWORD} \
		#--token ${INFLUXDB_ADMIN_TOKEN} \
		#--bucket ${INFLUXDB_PRIMARYBUCKET} \
}

# ##############################################################################
# ##############################################################################
#
##  @brief  This function calls the Influx CLI to create a token.
##
##  @see    https://docs.influxdata.com/influxdb/cloud/security/tokens/create-token/#create-a-token-using-the-influx-cli
#
function	F_influxdb_token_create()
{
	local pTokenName="${1}"
	shift
	local pTokenPermissions="${@}"

	LOG_INFO "Create InfluxDB token '${pTokenName}' with permissions '${pTokenPermissions}'..."
	LOG_LEVEL_INC

	LOG_DBG "Create the token..."
	local lOutput=`docker exec \
		${SVC_DATABASE_CONTAINER_NAME} \
		influx auth create\
		--org ${INFLUXDB_ORG} \
		--description "${pTokenName}" \
		${pTokenPermissions}`
	echo "${lOutput}" >&2

	LOG_DBG "Add the token to the file..."
	echo "${lOutput}" | tail -n 1 | awk '{print $2"="$3}' >> "${FILE_TOKENS}"


	LOG_INFO "Created InfluxDB token '${pTokenName}'."
	LOG_LEVEL_DEC
}

# ##############################################################################
# ##############################################################################

LOG_INFO "Retrieve InfluxDB buckets IDs."
LOG_LEVEL_INC

# lBucketId_primary_bucket=`F_influxdb_bucket_getId "${INFLUXDB_PRIMARYBUCKET}"`
# LOG_DBG "lBucketId_primary_bucket=$lBucketId_primary_bucket"

lBucketId_energy=`F_influxdb_bucket_getId "${SVC_TELEGRAF_INFLUXDB_BUCKET}"`
LOG_DBG "lBucketId_energy=$lBucketId_energy"

LOG_LEVEL_DEC


#
# Create access tokens
#
LOG_INFO "Create InfluxDB access tokens."
LOG_LEVEL_INC

# F_influxdb_token_create "GTW_INFLUXDB_TOKEN" --write-bucket ${lBucketId_energy}
F_influxdb_token_create "SVC_GRAFANA_INFLUXDB_TOKEN" --read-buckets #--read-bucket ${lBucketId_primary_bucket}
F_influxdb_token_create "SVC_TELEGRAF_INFLUXDB_TOKEN" --write-bucket ${lBucketId_energy}

LOG_INFO "InfluxDB tokens creation done."
LOG_LEVEL_DEC



exit $?

