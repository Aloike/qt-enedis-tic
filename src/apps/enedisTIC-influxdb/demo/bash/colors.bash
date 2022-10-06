#!/bin/bash

# ##############################################################################
##  @file   colors.bash
##  @brief  Defines control sequence to display colors in a Bash shell.
##
##  @note   How to set RGB values
##  There is a way to use RGB values in some terminals:
##  + For the background color, the sequence is `\033[48;2;R;G;Bm` (e.g.
##    `\033[48;2;255;64;0m Hello \033[0m`).
##  + For the foreground color, the sequence is `\033[38;2;R;G;Bm` (e.g.
##    `\033[38;2;255;64;0m Hello \033[0m`).
##
##  @see
##  + http://www.perbang.dk/rgb/ : Color picker.
##  + https://en.wikipedia.org/wiki/Web_colors : Color names and values.
# ##############################################################################


# ------------------------------------------------------------------------------
#   Bash control chars definitions
# ------------------------------------------------------------------------------

ESC_CHAR="\\e"	# Default is Linux definition.
# From https://stackoverflow.com/a/12099167
#ifeq ($(OS),Windows_NT)
#	echo "Windows not supported !"
#	exit 1
#else
	UNAME_S="$(uname -s)"
	if [[ "${UNAME_S}" == "Linux" ]]
	then
		ESC_CHAR="\\e"
	elif [[ "${UNAME_S}" == "Darwin" ]]
	then
		ESC_CHAR="\\033"
	fi
#endif


# Bash format definitions
FMT_CLR="${ESC_CHAR}[0m"	# Clear formatting
FMT_STD="${FMT_CLR}"		# Default format - Same as "Clear formatting".
FMT_BLD="${ESC_CHAR}[1m"	# Bold
FMT_UDL="${ESC_CHAR}[4m"	# Underline
FMT_BLI="${ESC_CHAR}[5m"	# Blink

##  @brief  Control char to fill a line.
CLREOL="${ESC_CHAR}[K"


# ------------------------------------------------------------------------------
#   Colors definitions
# ------------------------------------------------------------------------------

declare g_color_codes=("
	# Greyscales
	BLK    0   0   0
	GRY  128 128 128
	SVR  192 192 192
	WHT  255 255 255

	# Basic colors
	MRN  128   0   0	# maroon
	RED  255   0   0	# red
	ORG  255 165   0	# orange
	OLI  128 128   0	# olive
	YLW  255 255   0	# yellow
	LIM    0 128   0	# green
	GRN    0 255   0	# lime
	CYN    0 255 255	# cyan
	BLU    0   0 255	# blue
	NAV    0   0 128	# navy
	MAG  255   0 255	# magenta
	PPL  128   0 128	# purple
	BLU    0   0 255	# blue

	# Extended colors
	LGRY 211 211 211	# LightGray
")


function	_F_color_getRGB()
{
	pCode="${1}"


	lRetVal=`echo "${g_color_codes[@]}" \
		| sed -n \
		-e 's@#.*@@; s@[[:space:]]*'"${pCode}"'[[:space:]]\+\([0-9]\+\)[[:space:]]\+\([0-9]\+\)[[:space:]]\+\([0-9]\+\)@\1 \2 \3@p'`


	if [ -z "${lRetVal}" ]
	then
		echo "[${FUNCNAME[0]}: Unknown color code '${pCode}']" 1>&2
		return 1
	else
		echo "${lRetVal}"
		return 0
	fi
}

function	F_COL()
{
	# Retrieve args
	# if [[ $# > 1 ]]
	# then
	pCode="${1:-WHT}"
	shift

	pType="${1:-FG}"


	F_COL_RGB "$pType" $(_F_color_getRGB ${pCode})
	return $?
}

##  @brief  This function generates the sequence to be echoed to colorize the
##          Bash output with an RGB value. It can be used to generate either the
##          background or the foreground color code.
##
##  @par    1   The color type:
##              - `BG` for background,
##              - `FG` for foreground.
##  @par    2   The Red component. Range: [0-255].
##  @par    3   The Green component. Range: [0-255].
##  @par    4   The Blue component. Range: [0-255].

function	F_COL_RGB()
{
	pType="${1}"
	shift

	pR="${1}"
	pG="${2}"
	pB="${3}"

	local lTypeCode
	case "${pType}" in
		"BG")	# Background color
			lTypeCode="48"
			;;

		"FG")	# Foreground color
			lTypeCode="38"
			;;

		*)
			echo "[${FUNCNAME[0]}: Unknown pType '${pType}']"
			return 1
			;;
	esac

	echo "${ESC_CHAR}[${lTypeCode};2;${pR};${pG};${pB}m"
}


#
# Background colors list
#
# Greyscales
COL_BG_BLK=`	F_COL	BLK		BG`	# Background black
COL_BG_GRY=`	F_COL	GRY		BG`	# Background gray 50%
COL_BG_SVR=`	F_COL	SVR		BG`	# Background silver (gray 75%)
COL_BG_WHT=`	F_COL	WHT		BG`	# Background white

# Basic colors
COL_BG_MRN=`	F_COL	MRN		BG`	# Background maroon
COL_BG_RED=`	F_COL	RED		BG`	# Background red
COL_BG_ORG=`	F_COL	ORG		BG`	# Background orange
COL_BG_OLI=`	F_COL	OLI		BG`	# Background olive
COL_BG_YLW=`	F_COL	YLW		BG`	# Background yellow
COL_BG_LIM=`	F_COL	LIM		BG`	# Background green
COL_BG_GRN=`	F_COL	GRN		BG`	# Background lime
COL_BG_CYN=`	F_COL	CYN		BG`	# Background cyan
COL_BG_BLU=`	F_COL	BLU		BG`	# Background blue
COL_BG_NAV=`	F_COL	NAV		BG`	# Background navy
COL_BG_MAG=`	F_COL	MAG		BG`	# Background magenta
COL_BG_PPL=`	F_COL	PPL		BG`	# Background purple
COL_BG_BLU=`	F_COL	BLU		BG`	# Background blue



#
# Foreground colors list
#
# Greyscales
COL_FG_BLK="$(	F_COL_RGB	FG     0   0   0)"	# Foreground black
COL_FG_GRY="$(	F_COL_RGB	FG   127 127 127)"	# Foreground gray 50%
COL_FG_SVR="$(	F_COL_RGB	FG   191 191 191)"	# Foreground silver (gray 75%)
COL_FG_LGRY="$(	F_COL_RGB	FG   211 211 211)"	# Foreground light gray
COL_FG_WHT="$(	F_COL_RGB	FG   255 255 255)"	# Foreground white

# Basic colors
COL_FG_MRN=`	F_COL	MRN		FG`	# Foreground maroon
COL_FG_RED=`	F_COL	RED		FG`	# Foreground red
COL_FG_ORG=`	F_COL	ORG		FG`	# Foreground orange
COL_FG_OLI=`	F_COL	OLI		FG`	# Foreground olive
COL_FG_YLW=`	F_COL	YLW		FG`	# Foreground yellow
COL_FG_LIM=`	F_COL	LIM		FG`	# Foreground green
COL_FG_GRN=`	F_COL	GRN		FG`	# Foreground lime
COL_FG_CYN=`	F_COL	CYN		FG`	# Foreground cyan
COL_FG_BLU=`	F_COL	BLU		FG`	# Foreground blue
COL_FG_NAV=`	F_COL	NAV		FG`	# Foreground navy
COL_FG_MAG=`	F_COL	MAG		FG`	# Foreground magenta
COL_FG_PPL=`	F_COL	PPL		FG`	# Foreground purple
COL_FG_BLU=`	F_COL	BLU		FG`	# Foreground blue


# Extended colors
COL_FG_LRED="${ESC_CHAR}[91m"	# Foreground light red
COL_FG_LMAG="${ESC_CHAR}[95m"	# Foreground light magenta



# Bash "assembled colors" list
COL_CYN="${ESC_CHAR}[30;46m"
COL_GRE="${ESC_CHAR}[47m"
COL_GRN="${ESC_CHAR}[30;42m"
COL_ORG="${ESC_CHAR}[30;43m"
COL_MAG="${ESC_CHAR}[30;45m"
COL_YLW="${ESC_CHAR}[30;103m"
