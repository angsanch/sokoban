#!/bin/bash

rm -f *.o libmy.a
gcc -c *.c
ar -rcs libmy.a *.o 
