#!/bin/bash

##  @file   variables.sh
##  @brief  This file contains various environment variables definitions used by
##          the deployment scripts.


DEMO_NAME='demo-enedis_tic-influxdb'

FILE_TOKENS=influxdb-tokens.env


# ------------------------------------------------------------------------------
# Variables related to the Docker daemon itself.
# ------------------------------------------------------------------------------
##  @brief  Root path of where to create docker volumes for this project.
DOCKER_VOLUMES_ROOTDIR="$(pwd)/.demo-data"


# ------------------------------------------------------------------------------
# Related to the Docker network.
# ------------------------------------------------------------------------------
DOCKER_NETWORK_NAME="net-${DEMO_NAME}"


# ------------------------------------------------------------------------------
# Related to the gateway instance that collects metrics.
# ------------------------------------------------------------------------------
# GTW_ATOME_INFLUXDB2_
# GTW_CONTAINER_NAME="${DEMO_NAME}-gtw"
# GTW_INFLUXDB_BUCKET="energy"

# GTW_DIR_DATA="${DOCKER_VOLUMES_ROOTDIR}/gtw/workdir"



# ------------------------------------------------------------------------------
# Related to the Database container.
# ------------------------------------------------------------------------------

##  @brief  The name of the InfluxDB container.
SVC_DATABASE_CONTAINER_NAME=${DEMO_NAME}-svc-database
SVC_DATABASE_CONTAINER_IMAGENAME=influxdb
SVC_DATABASE_CONTAINER_IMAGEVERSION=2.2
SVC_DATABASE_HTTPSERVICE_PORT=8086

SVC_DATABASE_CONFDIR_DOCKERVOLUME_LOCALDIR="${DOCKER_VOLUMES_ROOTDIR}/influxdb2/conf"
SVC_DATABASE_DATADIR_DOCKERVOLUME_LOCALDIR="${DOCKER_VOLUMES_ROOTDIR}/influxdb2/data"


INFLUXDB_ADMIN_USERNAME=username
INFLUXDB_ADMIN_PASSWORD=password
INFLUXDB_ADMIN_TOKEN=INFLUXDB_ADMIN_TOKEN
INFLUXDB_HOST=${SVC_DATABASE_CONTAINER_NAME}
INFLUXDB_PORT=${SVC_DATABASE_HTTPSERVICE_PORT}
INFLUXDB_ORG=example.org
INFLUXDB_PRIMARYBUCKET=primary_bucket


# ------------------------------------------------------------------------------
# Related to the Grafana Web visualisation service.
# ------------------------------------------------------------------------------
SVC_GRAFANA_CONTAINER_IMAGENAME=grafana/grafana
SVC_GRAFANA_CONTAINER_IMAGEVERSION=8.2.5
SVC_GRAFANA_CONTAINER_NAME=${DEMO_NAME}-svc-grafana
SVC_GRAFANA_PORT_WEBUI=3000

SVC_GRAFANA_ADMIN_USER=username
SVC_GRAFANA_ADMIN_PASSWORD=password

SVC_GRAFANA_DIR_PERSISTENTDATA="${DOCKER_VOLUMES_ROOTDIR}/svc-grafana/data"


# ------------------------------------------------------------------------------
# Related to the container used for sending Influx commands to the database
# through command-line.
# ------------------------------------------------------------------------------
SVC_INFLUXUTILITY_CONTAINER_NAME=${DEMO_NAME}-svc-influxdb-utility
SVC_INFLUXUTILITY_CONTAINER_IMAGENAME=influxdb
SVC_INFLUXUTILITY_CONTAINER_IMAGEVERSION=2.2


# ------------------------------------------------------------------------------
# Related to the Telegraf container.
# ------------------------------------------------------------------------------
SVC_TELEGRAF_CONTAINER_NAME=${DEMO_NAME}-svc-telegraf
SVC_TELEGRAF_CONTAINER_IMAGENAME=telegraf
SVC_TELEGRAF_CONTAINER_IMAGEVERSION=1.22
SVC_TELEGRAF_PORT_LISTEN_INFLUXDB=8186
SVC_TELEGRAF_INFLUXDB_BUCKET="energy"