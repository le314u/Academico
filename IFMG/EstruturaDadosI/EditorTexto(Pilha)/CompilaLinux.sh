#!/bin/bash
gcc -c pilha.c
gcc editor.c pilha.o -lm  -o exe
./exe
