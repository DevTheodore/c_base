#!/bin/bash

#Store the number of arguments

len=$#
echo "=========== Start make clean =========="
echo ""
make clean
echo ""
echo "============ End make clean ==========="
echo ""
echo "============ Start compile ============"
echo ""
make
echo ""
echo "============= End compile ============="
echo ""
echo "============ Start program ============"
echo ""
compiled/prog $@
echo ""
echo "============= End program ============="