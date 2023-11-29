#!/bin/bash
exit 0
HEADER=src/headers/auto_h.h
echo "#ifndef AUTOC" > $HEADER
echo "#define AUTOC 1" >> $HEADER
for file in src/headers/files/*.h
do
    echo "#include \"${file##src/headers/}\"" >> $HEADER
done
echo "#endif" >> $HEADER