#!/usr/bin/env bash 
source ./config.sh

COMMAND="$COMPILATOR -g $FILES -o compiled/prog.comp -Wall $@"
echo "Commande de compilation : \"$COMMAND\""
echo ""
eval "$COMMAND"

{
    eval "$COMPILATOR $FILES -E -Wall $@ > $SRC_OUT"
} > /dev/null