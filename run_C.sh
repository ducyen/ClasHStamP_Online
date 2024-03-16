#!/bin/bash

WORKING_DIR=`dirname $0`

ASTAH_HOME=$WORKING_DIR/astah-edu
TOOL_DIR=$WORKING_DIR/release
export PROJECT=$WORKING_DIR/samples/$1/Design.asta
export EXT_CODE_OPT=y
export ENCODING=UTF-8
JAVA_TOOL_OPTIONS=-Dfile.encoding=UTF-8

BAT_DIR=$WORKING_DIR
BIN_DIR=$BAT_DIR/release/ClasHStamP.jar
LIB_DIR=$BAT_DIR/lib

ASTAH_COM_JAR=$ASTAH_HOME/astah-community.jar
ASTAH_UML_JAR=$ASTAH_HOME/astah-uml.jar
ASTAH_PRO_JAR=$ASTAH_HOME/astah-pro.jar
ASTAH_JAR=$ASTAH_COM_JAR:$ASTAH_UML_JAR:$ASTAH_PRO_JAR
API_JAR=$ASTAH_HOME/astah-api.jar

CSV_JAR=$LIB_DIR/commons-csv-1.1.jar
LOG_JAR=$LIB_DIR/logback-loader-1.0.9b.jar
SLF_JAR=$LIB_DIR/slf4j-api-1.6.6.jar

# Set classpath separator based on the environment
if uname -a | grep -q "CYGWIN"; then
    CLASSPATH_SEPARATOR=";"
    BIN_DIR=`cygpath -w $BIN_DIR`
    ASTAH_COM_JAR=`cygpath -w $ASTAH_COM_JAR`
    ASTAH_UML_JAR=`cygpath -w $ASTAH_UML_JAR`
    ASTAH_PRO_JAR=`cygpath -w $ASTAH_PRO_JAR`
    API_JAR=`cygpath -w $API_JAR`
    CSV_JAR=`cygpath -w $CSV_JAR`
    LOG_JAR=`cygpath -w $LOG_JAR`
    SLF_JAR=`cygpath -w $SLF_JAR`
    ASTAH_JAR=$ASTAH_COM_JAR$CLASSPATH_SEPARATOR$ASTAH_UML_JAR$CLASSPATH_SEPARATOR$ASTAH_PRO_JAR
else
    CLASSPATH_SEPARATOR=":"
fi

CLASSPATH=$BIN_DIR$CLASSPATH_SEPARATOR$ASTAH_JAR$CLASSPATH_SEPARATOR$API_JAR$CLASSPATH_SEPARATOR$CSV_JAR$CLASSPATH_SEPARATOR$LOG_JAR$CLASSPATH_SEPARATOR$SLF_JAR

INITIAL_HEAP_SIZE=16m
MAXIMUM_HEAP_SIZE=256m

JAVA_OPTS="-Xms$INITIAL_HEAP_SIZE -Xmx$MAXIMUM_HEAP_SIZE"
JAVA_OPTS="$JAVA_OPTS -classpath $CLASSPATH"

SAMPLE_HOME=$WORKING_DIR/samples/$1

echo "Running command: ./astah-edu/astah-command.sh -f $SAMPLE_HOME/Design.asta -image -o $SAMPLE_HOME/Image -t png"
./astah-edu/astah-command.sh -f $SAMPLE_HOME/Design.asta -image -o $SAMPLE_HOME/Image -t png

export OUTPUT=$SAMPLE_HOME/C

export LANGUAGE=c
export SYNTAX=$TOOL_DIR/Syntax_CNew.csv
export SYNTAX_ABSTRACT=$TOOL_DIR/Syntax_CNew.csv
export SYNTAX_INTERFACE=$TOOL_DIR/Syntax_CNew.csv
export SYNTAX_BASECLASS=$TOOL_DIR/Syntax_CNew.csv

export PACKAGE=Model
#echo "Running command: java $JAVA_OPTS stm.TMain"
java $JAVA_OPTS stm.TMain

PACKAGE=Abstracts
java $JAVA_OPTS stm.TMain

PACKAGE=NonOOP
java $JAVA_OPTS stm.TMain

PACKAGE=Design
java $JAVA_OPTS stm.TMain

LANGUAGE=h
SYNTAX=$TOOL_DIR/Syntax_HNew.csv
SYNTAX_ABSTRACT=$TOOL_DIR/Syntax_HNew.csv
SYNTAX_INTERFACE=$TOOL_DIR/Syntax_HNew.csv
SYNTAX_BASECLASS=$TOOL_DIR/Syntax_HNew.csv

PACKAGE=Model
java $JAVA_OPTS stm.TMain

PACKAGE=Interfaces
java $JAVA_OPTS stm.TMain

PACKAGE=Abstracts
java $JAVA_OPTS stm.TMain

PACKAGE=NonOOP
java $JAVA_OPTS stm.TMain

PACKAGE=Design
java $JAVA_OPTS stm.TMain

echo "Building Code"

cd $SAMPLE_HOME/C
make clean
cd $WORKING_DIR

echo "Code Generation Finished"
