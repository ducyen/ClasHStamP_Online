#!/bin/sh
# Shell file to run a sample of Astah API on Linux/Mac OS X

# Remove # from following two lines, if you'd like to use jdk.
# JAVA_HOME=/usr/lib/java7
# PATH=$JAVA_HOME/bin:$PATH

SH_DIR=$(dirname $(readlink -f $0))
ASTAH_HOME=$SH_DIR/../../..
# ASTAH_HOME="/Applications/astah professional/astah professional.app/Contents/Java"
ASTAH_COM_JAR="$ASTAH_HOME/astah-community.jar"
ASTAH_UML_JAR="$ASTAH_HOME/astah-uml.jar"
ASTAH_PRO_JAR="$ASTAH_HOME/astah-pro.jar"
ASTAH_JAR=$ASTAH_COM_JAR:$ASTAH_UML_JAR:$ASTAH_PRO_JAR
API_JAR="$ASTAH_HOME/astah-api.jar"
CLASSPATH="$SH_DIR":$ASTAH_JAR:$API_JAR
LIBPATH="$ASTAH_HOME/lib/rlm"

# run
java -classpath $CLASSPATH -Djava.library.path=$LIBPATH APIForCreatingPresentationsSample $1 $2