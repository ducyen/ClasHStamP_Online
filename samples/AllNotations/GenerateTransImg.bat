rem @echo off
set ASTAH_HOME=..\..\astah-com\
set PROJECT_HOME=.\
start %ASTAH_HOME%astah-command.bat -f %PROJECT_HOME%Design.asta -image -o %PROJECT_HOME%Image -t png
start %ASTAH_HOME%astah-command.bat -f %PROJECT_HOME%Design.asta -image -o %PROJECT_HOME%TransImg -t png

