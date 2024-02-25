#!/bin/bash

WORKING_DIR=$(dirname "$0")

# Check if XWin is running
#if pgrep -x "XWin" > /dev/null
#then
#    echo "XWin server is already running."
#else
#    echo "Starting XWin server..."
#    nohup startxwin &
#    sleep 2 # Wait a bit to ensure the X server starts
#fi

# Set the DISPLAY environment variable
export DISPLAY=:0.0

# Start xterm
xterm -e "$WORKING_DIR/samples/$1/C/my_program" "$WORKING_DIR/samples/$1/Image/Design" "$WORKING_DIR/samples/$1/TransImg/Design"
