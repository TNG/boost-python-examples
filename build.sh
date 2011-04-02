#!/bin/bash

set -x

mkdir build
cd build
cmake .. && make && make test

