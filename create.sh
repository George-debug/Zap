#!/bin/bash
echo "compililing zap"
mkdir build
cd src
yacc -d zap.y
lex zap.l
gcc -Wno-implicit-function-declaration *.c -o ../build/zap
