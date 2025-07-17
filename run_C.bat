@echo off
setlocal

:: Set working directories and initial paths
set "WORKING_DIR=%~dp0"
set "ASTAH_HOME=%WORKING_DIR%astah-uml"
set "TOOL_DIR=%WORKING_DIR%release"
set "PROJECT=%WORKING_DIR%samples\%1\Design.asta"
set "EXT_CODE_OPT=y"
set "ENCODING=UTF-8"
set "NEWLINE_LF=1"
set "JAVA_TOOL_OPTIONS=-Dfile.encoding=UTF-8"

set "BAT_DIR=%WORKING_DIR%"
set "BIN_DIR=%BAT_DIR%release\ClasHStamP.jar"
set "LIB_DIR=%BAT_DIR%lib"

set "ASTAH_COM_JAR=%ASTAH_HOME%\astah-community.jar"
set "ASTAH_UML_JAR=%ASTAH_HOME%\astah-uml.jar"
set "ASTAH_PRO_JAR=%ASTAH_HOME%\astah-pro.jar"
set "ASTAH_JAR=%ASTAH_COM_JAR%;%ASTAH_UML_JAR%;%ASTAH_PRO_JAR%"
set "API_JAR=%ASTAH_HOME%\astah-api.jar"

set "CSV_JAR=%LIB_DIR%\commons-csv-1.1.jar"
set "LOG_JAR=%LIB_DIR%\logback-loader-1.0.9b.jar"
set "SLF_JAR=%LIB_DIR%\slf4j-api-1.6.6.jar"

:: Set classpath
set "CLASSPATH=%BIN_DIR%;%ASTAH_JAR%;%API_JAR%;%CSV_JAR%;%LOG_JAR%;%SLF_JAR%"

set "INITIAL_HEAP_SIZE=16m"
set "MAXIMUM_HEAP_SIZE=256m"

set "JAVA_OPTS=-Xms%INITIAL_HEAP_SIZE% -Xmx%MAXIMUM_HEAP_SIZE% -classpath %CLASSPATH%"

set "SAMPLE_HOME=%WORKING_DIR%samples\%1"
set "OUTPUT=%SAMPLE_HOME%\C"
set "LANGUAGE=c"
set "SYNTAX=%TOOL_DIR%\Syntax_CNew.csv"
set "SYNTAX_ABSTRACT=%TOOL_DIR%\Syntax_CNew.csv"
set "SYNTAX_INTERFACE=%TOOL_DIR%\Syntax_CNew.csv"
set "SYNTAX_BASECLASS=%TOOL_DIR%\Syntax_CNew.csv"
set "PACKAGE=Model"

:: Execute Java commands
java %JAVA_OPTS% stm.TMain

set "PACKAGE=Abstracts"
java %JAVA_OPTS% stm.TMain

set "PACKAGE=NonOOP"
java %JAVA_OPTS% stm.TMain

set "PACKAGE=Design"
java %JAVA_OPTS% stm.TMain

set "LANGUAGE=h"
set "SYNTAX=%TOOL_DIR%\Syntax_HNew.csv"
set "SYNTAX_ABSTRACT=%TOOL_DIR%\Syntax_HNew.csv"
set "SYNTAX_INTERFACE=%TOOL_DIR%\Syntax_HNew.csv"
set "SYNTAX_BASECLASS=%TOOL_DIR%\Syntax_HNew.csv"

set "PACKAGE=Model"
java %JAVA_OPTS% stm.TMain

set "PACKAGE=Interfaces"
java %JAVA_OPTS% stm.TMain

set "PACKAGE=Abstracts"
java %JAVA_OPTS% stm.TMain

set "PACKAGE=NonOOP"
java %JAVA_OPTS% stm.TMain

set "PACKAGE=Design"
java %JAVA_OPTS% stm.TMain

set "LANGUAGE=c"
set "SYNTAX=%TOOL_DIR%\Syntax_CTst.csv"
set "SYNTAX_ABSTRACT=%TOOL_DIR%\Syntax_CTst.csv"
set "SYNTAX_INTERFACE=%TOOL_DIR%\Syntax_CTst.csv"
set "SYNTAX_BASECLASS=%TOOL_DIR%\Syntax_CTst.csv"

set "PACKAGE=Model"
java %JAVA_OPTS% stm.TMain

echo "Building Code"
cd "%SAMPLE_HOME%\C"
make clean
cd "%WORKING_DIR%"

echo "Code Generation Finished"
endlocal
