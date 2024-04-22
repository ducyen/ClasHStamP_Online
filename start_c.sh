#!/bin/bash

WORKING_DIR=$(cd "$(dirname "$1")"; pwd -P)/$(basename "$1")
#WORKING_DIR=$(realpath "$1")
SAMPLE_DIR=$2
GEOMETRY=$3

echo "Working Directory: $WORKING_DIR"
echo "Sample Directory: $SAMPLE_DIR"
echo "Geometry: $GEOMETRY"

SAMPLE_HOME=samples/$SAMPLE_DIR
echo "Running command: ./astah-edu/astah-command.sh -f $SAMPLE_HOME/Design.asta -image -o $SAMPLE_HOME/Image -t png -dpi 72"
./astah-edu/astah-command.sh -f $SAMPLE_HOME/Design.asta -image -o $SAMPLE_HOME/Image -t png -dpi 72

# Example command
cd "$WORKING_DIR/samples/$SAMPLE_DIR/C" || exit
if ! make; then
    echo "Make command failed. Press any key to continue..."
    read -n 1 -s -r
    exit 1
fi
cd "$WORKING_DIR" || exit

# Execute my_program with arguments
PROGRAM_PATH="$WORKING_DIR/samples/$SAMPLE_DIR/C/my_program"
echo "Program Path: $PROGRAM_PATH"

if [ -f "$PROGRAM_PATH" ]; then
    echo "Executing program..."
    "$PROGRAM_PATH" "$WORKING_DIR/samples/$SAMPLE_DIR/Image/Design" "$WORKING_DIR/samples/$SAMPLE_DIR/TransImg/Design"
else
    echo "Error: Program not found at $PROGRAM_PATH"
fi

#sleep 5
