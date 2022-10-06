#!/bin/bash

# echo "+-- Loading $( basename ${BASH_SOURCE} )..."


if [ ! -v LOG_INC_SH_INCLUDED ]
then

declare -r LOG_INC_SH_INCLUDED=1


LOG_FEATURE_FILELOC_ENABLED=${LOG_FEATURE_FILELOC_ENABLED:-0}


declare -r c_colorDBG="${COL_FG_GRY}"
declare -r c_colorERR="${COL_FG_RED}"
#declare -r c_colorINFO="${COL_BG_BLK}${COL_FG_BLU}"
declare -r c_colorINFO="${COL_BG_BLK}${COL_FG_CYN}"
declare -r c_colorWARN="${COL_FG_ORG}"

declare _g_log_level=0


declare -r C_LOG_SEVERITYKEY_DEBUG=' debug'
declare -r C_LOG_SEVERITYKEY_INFO='  info'
declare -r C_LOG_SEVERITYKEY_WARNING='warn  '
declare -r C_LOG_SEVERITYKEY_ERROR='error '

# ##############################################################################
# ##############################################################################

function	LOG()
{
	local pKey="$1"
	shift
	local pColor="$1"
	shift
	local pMessage="$@"


	local lFileLoc=''
	if [[ "${LOG_FEATURE_FILELOC_ENABLED}" -eq "0" ]]
	then
		lFileLoc=''
	else
		local lFileName="$( basename ${BASH_SOURCE[2]} )"
		local lLineNbr="${BASH_LINENO[1]}"

		lFileLoc="[${lFileName} +${lLineNbr}]"
	fi


	local lSpacing=" \t$(_LOG_LEVEL_GET)"
	local lEOL="${CLREOL}${FMT_STD}"

	# echo -e "${COL_FG_LGRY}[${pKey}][${lFileName} +${lLineNbr}]${FMT_STD}${lSpacing}${pMessage}${lEOL}"
	# echo -e "${pColor}[${pKey}][${lFileName} +${lLineNbr}]${FMT_STD}${lSpacing}${pMessage}${lEOL}"
	echo -e "${pColor}[${pKey}]${lFileLoc}${lSpacing}${pMessage}${lEOL}" >&2
}

function	LOG_LEVEL_DEC()
{
	((_g_log_level--))
	if [ $_g_log_level -lt 0 ]
	then
		_g_log_level=0
	fi

	return 0
}

function	LOG_LEVEL_INC()
{
	_g_log_level=${_g_log_level}+1

	return 0
}

function	_LOG_LEVEL_GET()
{
	declare -r c_spacing="    "

	local lIt=0
	while (( $lIt < ($_g_log_level -1) ))
	do
		echo -en "${c_spacing}"
		((lIt++))
	done

	if (( $_g_log_level > 0 ))
	then
		echo -en '+-- '
	fi
}

# ##############################################################################
# ##############################################################################

function	LOG_DBG()
{
	LOG "${C_LOG_SEVERITYKEY_DEBUG}" "${c_colorDBG}" "$@"
}

# ##############################################################################
# ##############################################################################

function	LOG_ERR()
{
	LOG "${C_LOG_SEVERITYKEY_ERROR}" "${c_colorERR}" "$@"
}

# ##############################################################################
# ##############################################################################

function	LOG_INFO()
{
	LOG "${C_LOG_SEVERITYKEY_INFO}" "${c_colorINFO}" "$@"
}

# ##############################################################################
# ##############################################################################

function	LOG_WARN()
{
	LOG "${C_LOG_SEVERITYKEY_WARNING}" "${c_colorWARN}" "$@"
}

# ##############################################################################
# ##############################################################################

fi	#< LOG_INC_SH_INCLUDED
