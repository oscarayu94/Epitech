#!/bin/bash

getDate() {
  d=$(date +%e)
  case $d in
      (1?) d=${d}th ;;
      (*1) d=${d}st ;;
      (*2) d=${d}nd ;;
      (*3) d=${d}rd ;;
      (*)  d=${d}th ;;
  esac

  DATE=$(date "+$d %B, %Y")
}

OUTPUT=$1
TITLE=$2

getDate
HEADER=$'###############################\n#\n'
if ! [[ "${OUTPUT}" = "false" ]]; then HEADER+='# '"${OUTPUT}"$'\n'; else HEADER+='# no filename'$'\n'; fi
HEADER+=$'#'" $DATE"$'\n'
if [[ "${TITLE:0:1}" = "#" ]]; then NAME="${TITLE:1}"; fi
NAME=`echo ${NAME} | sed 's/ *$//g'`
HEADER+=$'# '"$NAME"$'\n#'
HEADER+=$'\n###############################\n'
if ! [[ "${OUTPUT}" = "false" ]]; then echo -e ${HEADER} >> "${OUTPUT}"; else echo "$HEADER"; fi