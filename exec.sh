#!/bin/bash
G_DIR="$( cd -- "$( dirname -- "${BASH_SOURCE[0]}" )" &> /dev/null && pwd )"
ACT_DIR=$(exec pwd)
cd "$G_DIR"
if [ $# -eq 0 ] || [ $1 != 'run' ]; then
    {   sh/gen_auto_h.sh
        (make clean)
    } &> /dev/null
    echo "Make Cleaned"
    echo ""
    if [ "$1" != "stable" ]; then
        make -s
    else 
        make -s stable
    fi
    retVal=$?
    if [ $retVal -ne 0 ]; then
        exit $retVal
    fi
fi
if [ $# -eq 0 ] || [ "$1" != "stable" -a "$1" != "gdb" ]; then
    cd env_of_ex
    "../compiled/prog.comp" ${@}
fi
if [ "$1" == "gdb" ]; then
    cd env_of_ex
    gdb --args "../compiled/prog.comp" "${@:2}"
fi
cd "$ACT_DIR"
exit $?