#!/bin/bash

export WORKING_DIR=.

export ASTAH_HOME=$WORKING_DIR/astah-edu
export TOOL_DIR=$WORKING_DIR/release
export PROJECT=$WORKING_DIR/samples/AllNotations/Design.asta
export EXT_CODE_OPT=y
export ENCODING=UTF-8
export JAVA_TOOL_OPTIONS=-Dfile.encoding=UTF-8

export BAT_DIR=$WORKING_DIR
export BIN_DIR=$BAT_DIR/release/ClasHStamP.jar
export LIB_DIR=$BAT_DIR/lib

export ASTAH_COM_JAR=$ASTAH_HOME/astah-community.jar
export ASTAH_UML_JAR=$ASTAH_HOME/astah-uml.jar
export ASTAH_PRO_JAR=$ASTAH_HOME/astah-pro.jar
export ASTAH_JAR=$ASTAH_COM_JAR:$ASTAH_UML_JAR:$ASTAH_PRO_JAR
export API_JAR=$ASTAH_HOME/astah-api.jar

export CSV_JAR=$LIB_DIR/commons-csv-1.1.jar
export LOG_JAR=$LIB_DIR/logback-loader-1.0.9b.jar
export SLF_JAR=$LIB_DIR/slf4j-api-1.6.6.jar

# Set classpath separator based on the environment
if uname -a | grep -q "CYGWIN"; then
    export CLASSPATH_SEPARATOR=";"
    export BIN_DIR=`cygpath -w $BIN_DIR`
    export ASTAH_COM_JAR=`cygpath -w $ASTAH_COM_JAR`
    export ASTAH_UML_JAR=`cygpath -w $ASTAH_UML_JAR`
    export ASTAH_PRO_JAR=`cygpath -w $ASTAH_PRO_JAR`
    export API_JAR=`cygpath -w $API_JAR`
    export CSV_JAR=`cygpath -w $CSV_JAR`
    export LOG_JAR=`cygpath -w $LOG_JAR`
    export SLF_JAR=`cygpath -w $SLF_JAR`
    export ASTAH_JAR=$ASTAH_COM_JAR$CLASSPATH_SEPARATOR$ASTAH_UML_JAR$CLASSPATH_SEPARATOR$ASTAH_PRO_JAR
else
    export CLASSPATH_SEPARATOR=":"
fi

export CLASSPATH=$BIN_DIR$CLASSPATH_SEPARATOR$ASTAH_JAR$CLASSPATH_SEPARATOR$API_JAR$CLASSPATH_SEPARATOR$CSV_JAR$CLASSPATH_SEPARATOR$LOG_JAR$CLASSPATH_SEPARATOR$SLF_JAR

export INITIAL_HEAP_SIZE=16m
export MAXIMUM_HEAP_SIZE=256m

export JAVA_OPTS="-Xms$INITIAL_HEAP_SIZE -Xmx$MAXIMUM_HEAP_SIZE"
export JAVA_OPTS="$JAVA_OPTS -classpath $CLASSPATH"

export SAMPLE_HOME=`dirname $0`
export OUTPUT=$SAMPLE_HOME/C

export LANGUAGE=c
export SYNTAX=$TOOL_DIR/Syntax_CNew.csv
export SYNTAX_ABSTRACT=$TOOL_DIR/Syntax_CNew.csv
export SYNTAX_INTERFACE=$TOOL_DIR/Syntax_CNew.csv
export SYNTAX_BASECLASS=$TOOL_DIR/Syntax_CNew.csv

export PACKAGE=Model
echo "Running command: java $JAVA_OPTS stm.TMain %1 %2"
java $JAVA_OPTS stm.TMain %1 %2

export PACKAGE=Abstracts
java $JAVA_OPTS stm.TMain %1 %2

export PACKAGE=NonOOP
java $JAVA_OPTS stm.TMain %1 %2

export LANGUAGE=h
export SYNTAX=$TOOL_DIR/Syntax_HNew.csv
export SYNTAX_ABSTRACT=$TOOL_DIR/Syntax_HNew.csv
export SYNTAX_INTERFACE=$TOOL_DIR/Syntax_HNew.csv
export SYNTAX_BASECLASS=$TOOL_DIR/Syntax_HNew.csv

export PACKAGE=Model
java $JAVA_OPTS stm.TMain %1 %2

export PACKAGE=Interfaces
java $JAVA_OPTS stm.TMain %1 %2

export PACKAGE=Abstracts
java $JAVA_OPTS stm.TMain %1 %2

export PACKAGE=NonOOP
java $JAVA_OPTS stm.TMain %1 %2
