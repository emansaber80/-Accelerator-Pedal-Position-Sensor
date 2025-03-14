
set MATLAB=D:\Programs\Matlab

cd .

if "%1"=="" ("D:\Programs\Matlab\bin\win64\gmake"  -f APP.mk all) else ("D:\Programs\Matlab\bin\win64\gmake"  -f APP.mk %1)
@if errorlevel 1 goto error_exit

exit /B 0

:error_exit
echo The make command returned an error of %errorlevel%
exit /B 1