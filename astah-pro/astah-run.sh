#!/bin/bash
# Shell script to run ASTAH on macOS

# Uncomment the following two lines to set JAVA_HOME manually.
# export JAVA_HOME=/Library/Java/JavaVirtualMachines/jdk1.7.0_45.jdk/Contents/Home
# export PATH=$JAVA_HOME/bin:$PATH

ASTAH_JAR=astah-pro.jar
INITIAL_HEAP_SIZE=16m
MAXIMUM_HEAP_SIZE=384m

USER_LANGUAGE=en
# USER_LANGUAGE=ja
# USER_LANGUAGE=en

USER_COUNTRY=
# USER_COUNTRY=JP
# USER_COUNTRY=US

# ASTAH_HOME should be this folder
ASTAH_HOME=$(dirname "$0")

if [ ! -f "$ASTAH_HOME/$ASTAH_JAR" ]; then
    echo "ASTAH_HOME is invalid. Please check your ASTAH_HOME."
    exit 1
fi

JAVA_OPTS="-Xms$INITIAL_HEAP_SIZE -Xmx$MAXIMUM_HEAP_SIZE -Dsun.java2d.d3d=false"
# JAVA_OPTS="$JAVA_OPTS -DrootLevel=DEBUG"

if [ ! -z "$USER_LANGUAGE" ]; then
    JAVA_OPTS="$JAVA_OPTS -Duser.language=$USER_LANGUAGE"
fi

if [ ! -z "$USER_COUNTRY" ]; then
    JAVA_OPTS="$JAVA_OPTS -Duser.country=$USER_COUNTRY"
fi

# Check if the JRE bundled version is being used
if [ -x "$ASTAH_HOME/jre/bin/java" ]; then
    PATH="$ASTAH_HOME/jre/bin:$PATH"
fi

# Run Astah
java $JAVA_OPTS -jar "$ASTAH_HOME/$ASTAH_JAR" "$@"
