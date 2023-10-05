#!/bin/sh
g++ -g $(find . -type f -iregex ".*\.cpp") -o test
./test