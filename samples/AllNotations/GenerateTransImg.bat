set ASTAH_HOME=..\..\astah-com\
set PROJECT_HOME=.\
%ASTAH_HOME%astah-command.bat -f %PROJECT_HOME%Design.asta -image -o %PROJECT_HOME%Image -t png || echo Astah command failed, continuing...


echo %CD%

echo Running Java command...
start java TransImg.ImageLoader TransImg 2>error.log
echo Java command finished.




