#!/bin/bash

echo "do you want compile dynamic lib or main[d/m]?"

read choice

if [ "$choice" = "m" ]; then
    gcc -L./ -Wall -o start main.c -lbasics -lmatrix
elif [ "$choice" = "d" ]; then
    gcc -c -Wall -fpic basics.c
    gcc -shared -o libbasics.so basics.o

    gcc -c -Wall -fpic matrix.c
    gcc -shared -o libmatrix.so matrix.o
else
    echo "Not supported"
fi

exit 0