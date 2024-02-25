#!/bin/bash

WORKING_DIR=$(dirname "$0")

# Set the DISPLAY environment variable
export DISPLAY=:0.0

# Start xterm in the background and get its PID
xterm -geometry $2 -e "$WORKING_DIR/samples/$1/C/my_program" "$WORKING_DIR/samples/$1/Image/Design" "$WORKING_DIR/samples/$1/TransImg/Design" &
PID=$!

# Store the PID in a file
echo $PID > "$WORKING_DIR/xterm.pid"

# Wait for my_program to finish
wait $PID
