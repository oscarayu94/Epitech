#!/bin/bash

usage() {
  echo "Usage: script_formatter.sh in [-h] [-s] [-i nb_char] [-e] [-o out]"
  echo "      in                              input file"
  echo "     -h, --header                     header generation"
  echo "     -s, --spaces                     force spaces instead of tabulations for indentation"
  echo "     -i, --indentation=nb_char        number of characters for indentation (8 by default)"
  echo "     -e, --expand                     force do and then keywords on new lines"
  echo "     -o, --output=out                 output file (stdout by default)"
}



if [[ $# -eq 0 ]]; then exit 84
elif [[ "$1" = "-help" ]]; then usage; exit 0
fi

options=$(getopt -o hsi:eo: --long header --long spaces --long expand --long output: --long indentation: -- "$@")

HEADER=false
SPACES=false
INDENTATION=false
EXPAND=false
OUTPUT=false

# eval expression
eval set -- "${options}"
    while true; do
        case "$1" in
        (-h | --header) HEADER=true ;;
        (-s | --spaces) SPACES=true ;;
        (-i | --indentation) INDENTATION=$2; shift ;;
        (-e | --expand) EXPAND=true ;;
        (-o | --output) OUTPUT=$2; shift ;;
        (\?) exit 84 ;;  # getopts already reported the illegal option
        (--) shift; break ;;
        esac
        shift
    done

#echo "header $HEADER"
#echo "spaces $SPACES"
#echo "indentation $INDENTATION"
#echo "expand $EXPAND"
#echo "output $OUTPUT"

FUNCTION_CHECK=0
STRING=""
FILE=""
FILE2=""
FILE3=""
FILE31=""
FILE4=""

function shebang_detection() {
    BASH="#!/bin/sh"
    if [[ "$OUTPUT" = "false" ]]; then echo -e "${BASH}\n"; else echo -e "$BASH\n" > "$OUTPUT"; fi  
}

function insert_header() {
    TITLE=$(sed -n 2p "$1")
    if [[ "$HEADER" = true ]]; then ./header.sh "$OUTPUT" "$TITLE"; fi
}

function open_brackets() {
  local string=""
  los=1
  local lastCharacter=""
    while read -r -n 1 character_1
      do
      if [[ "$character_1" = '{' ]] && [[ "$lastCharacter" = '$' ]] || [ $los -eq 0 ]
          then
            if [[ "$lastCharacter" != '}' ]]
              then
                los=0
              else
                los=1
              fi
        fi
        if [[ "$character_1" = "{" ]] && ! [[ "$lastCharacter" = 'n' ]] && [[ $los -eq 1 ]] ; then string+="\n"; fi;
        if ! [[ "$character_1" = "\\" ]] &&  [[ "$lastCharacter" = '{' ]] && [[ $los -eq 1 ]] ; then string+="\n"; fi;
        if [[ "$lastCharacter" = "" ]] && [[ "$character_1" = "" ]]; then continue; fi;
        lastCharacter="$character_1"
        if [[ "$lastCharacter" = "" ]]; then string+=" "; else string+="$lastCharacter"; fi;
      done < <(echo "$text")
      FILE+="$string\n"
}

function close_brackets() {
  local string=""
  los=1
  local previous_los=1
  local lastCharacter=""
    while read -r -n 1 character_1
      do
        if [[ "$character_1" = '{' ]] && [[ "$lastCharacter" = '$' ]] || [[ ${los} -eq 0 ]]
          then
            if [[ "$lastCharacter" != '}' ]]
              then
                los=0
              else
                previous_los=0
                los=1
              fi
        fi
        if [[ "$character_1" = "}" ]] && ! [[ "$lastCharacter" = 'n' ]] && [[ ${los} -eq 1 ]] ; then string+="\n"; fi;
        if ! [[ "$character_1" = "\\" ]] &&  [[ "$lastCharacter" = '}' ]] && [[ ${los} -eq 1 ]] && [[ ${previous_los} -eq 1 ]] ; then string+="\n"; fi;
        if [[ "$lastCharacter" = "" ]] && [[ "$character_1" = "" ]]; then continue; fi;
        lastCharacter="$character_1"
        if [[ "$lastCharacter" = "" ]]; then string+=" "; else string+="$lastCharacter";fi;
        previous_los=1

      # shellcheck disable=SC2039
      done < <(echo "$FILE")
      FILE2+="$string\n"
}


function format_then() {
    local line=""
    local firstLineString=""
    local lastLineString=""
    local saveIf=""
    local saveThen=""

    while read -r line; do
        firstLineString=`echo "$line" | awk '{print $1}'`
        lastLineString=${line##* }
        saveThen=${line#* }
        if [[ "${EXPAND}" = false ]]; then
            if [[ ${firstLineString} = "if" && ${lastLineString} != "then" ]]; then saveIf=${line};
            elif [[ ${firstLineString} = "then" && ${lastLineString} = "then" ]]; then FILE3+="${saveIf}; then\n"; saveIf="";
            elif [[ ${firstLineString} = "then" ]]; then FILE3+="${saveIf}; then\n${saveThen}\n"; saveIf="";
            else FILE3+="${line}\n"; fi
        else
            if [[ ${firstLineString} = "if" && ${lastLineString} = "then" ]]; then b="${line% *}"
                if [[ "${b:${#b}-1:1}" = ";" ]]; then line="${line% *}"; FILE3+="${line::-1}\nthen\n"; else FILE3+="${line% *}\nthen\n";fi
            elif [[ ${firstLineString} = "then" && ${lastLineString} = "then" ]]; then FILE3+="then\n"
            elif [[ ${firstLineString} = "then" ]]; then FILE3+="then\n${line#* }\n"
            else FILE3+="${line}\n"; fi
        fi
    done < <(echo -e "$FILE2")
}

function format_do() {
    local line=""
    local firstLineString=""
    local lastLineString=""
    local saveWhile=""
    local saveThen=""

    while read -r line; do
        firstLineString=`echo "$line" | awk '{print $1}'`
        lastLineString=${line##* }
        saveThen=${line#* }
        if [[ "${EXPAND}" = false ]]; then
            if [[ ${firstLineString} = "while" && ${lastLineString} != "do" ]]; then saveWhile=${line};
            elif [[ ${firstLineString} = "do" && ${lastLineString} = "do" ]]; then FILE31+="${saveWhile}; do\n"; saveWhile="";
            elif [[ ${firstLineString} = "do" ]]; then FILE31+="${saveWhile}; do\n${saveThen}\n"; saveWhile="";
            else FILE31+="${line}\n"; fi
        else
            if [[ ${firstLineString} = "while" && ${lastLineString} = "do" ]]; then b="${line% *}"
                if [[ "${b:${#b}-1:1}" = ";" ]]; then line="${line% *}"; FILE31+="${line::-1}\ndo\n"; else FILE31+="${line% *}\ndo\n";fi
            elif [[ ${firstLineString} = "do" && ${lastLineString} = "do" ]]; then FILE31+="do\n"
            elif [[ ${firstLineString} = "do" ]]; then FILE31+="do\n${line#* }\n"
            else FILE31+="${line}\n"; fi
        fi
    done < <(echo -e "$FILE3")
}

space=1
to_reach=8
line=""
prev_line=""
keep_inted=0
sline=""
string_space=""

function do_tabs() {
  local first_parameter=`echo -e "$1" | awk '{print $1}'`
  local Lcinted=0
  local count=1
  local word=`echo -e "$sline" | awk '{print $1}'`
    if ! [[ "$INDENTATION" = "false" ]]; then tabs ${INDENTATION}; else tabs 8; fi;
    if [[ "$first_parameter" = "if" ]] || [[ "$first_parameter" = "while" ]] || [ "$first_parameter" = "for" ] || [ "$first_parameter" = '{' ] && [ "${@: -1}" != "fi" ] && [ "${@: -1}" != "done" ]; then (( keep_inted++ )); fi;
    if [[ "$first_parameter" = "fi" ]] || [[ "$first_parameter" = "done" ]] || [[ "$first_parameter" = '}' ]]; then (( keep_inted-- )); fi;
    if [[ "$word" = "else" ]] || [[ "$word" = "elif" ]] || [[ "$word" = "fi" ]] || [[ "$word" = "done" ]] || [[ "$word" = '}' ]] || [[ "$word" = 'then' ]] || [[ "$word" = 'do' ]]; then Lcinted=$(( $keep_inted -1)) ; else  Lcinted=$keep_inted; fi;
    while [ $count -le $Lcinted ]; do sline="\t$sline"; (( count++ )); done;

}

function do_space() {

  local first_parameter=`echo -e "$1" | awk '{print $1}'`
  local Lcinted=0
  local count=1

  local word=`echo -e "$sline" | awk '{print $1}'`

  if  [[ "$INDENTATION" = "false" ]]; then to_reach=8; else to_reach=$INDENTATION; fi;
     while [ $space -le $to_reach ]; do
     string_space+=" "
     (( space++ ))
     done
    if [[ "$first_parameter" = "if" ]] || [[ "$first_parameter" = "while" ]] || [ "$first_parameter" = "for" ] || [ "$first_parameter" = '{' ] && [ "${@: -1}" != "fi" ] && [ "${@: -1}" != "done" ]; then (( keep_inted++ )); fi;
    if [[ "$first_parameter" = "fi" ]] || [[ "$first_parameter" = "done" ]] || [[ "$first_parameter" = '}' ]]; then (( keep_inted-- )); fi;
    if [[ "$word" = "else" ]] || [[ "$word" = "elif" ]] || [[ "$word" = "fi" ]] || [[ "$word" = "done" ]] || [[ "$word" = '}' ]]  || [[ "$word" = 'then' ]] || [[ "$word" = 'do' ]]; then Lcinted=$(( $keep_inted -1)) ; else  Lcinted=$keep_inted; fi;
    while [ $count -le $Lcinted ]; do sline="$string_space$sline"; (( count++ )); done;
}


text=""

if ! [[ "$1" ]]; then exit 84; fi
while read -r line; do text+="$line\n"; done < "$1";
shebang_detection $1
insert_header $1
open_brackets
close_brackets
format_then
format_do

if [ "$SPACES" = "false" ]; then
while read -r sline; do do_tabs ${prev_line}; FILE4+="$sline\n"; prev_line="$sline"; done < <( echo -e "$FILE31"); do_tabs ${prev_line}; FILE4+="$sline";
else
while read -r sline; do do_space ${prev_line}; FILE4+="$sline\n"; prev_line="$sline"; done < <( echo -e "$FILE31"); do_space ${prev_line}; FILE4+="$sline";
fi;

if [[ "$OUTPUT" = false ]]; then echo -e "$FILE4" | sed '/^\#!\/bin\/sh$/d' | sed '/^\#/d' | head -n -6 ; else echo -e "$FILE4" | sed '/^\#!\/bin\/sh$/d' | sed '/^\#/d' | head -n -6 >> "$OUTPUT"; fi