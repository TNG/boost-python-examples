#!/bin/bash

set -x

cd ${0%%$(basename $0)}
mkdir build
cd build
cmake .. && make && make test

