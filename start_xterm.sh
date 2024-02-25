#!/bin/bash

WORKING_DIR=`dirname $0`

# Set the DISPLAY environment variable
export DISPLAY=:0.0

# Start xterm
xterm -e $WORKING_DIR/samples/$1/C/my_program $WORKING_DIR/samples/$1/Image/Design $WORKING_DIR/samples/$1/TransImg/Design

