#!/bin/bash

cd src
make
make clean
cd ..
mv src/main .
