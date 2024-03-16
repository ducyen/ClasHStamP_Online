#!/bin/bash

WORKING_DIR=$(dirname "$0")

# Set the DISPLAY environment variable
export DISPLAY=:0.0

# Start xterm in the background and get its PID
xterm -geometry "$2" -e "$WORKING_DIR/start_c.sh" "$WORKING_DIR" "$1" "$2" &
PID=$!

# Store the PID in a file
echo $PID > "$WORKING_DIR/xterm.pid"

# Wait for my_program to finish
wait $PID
