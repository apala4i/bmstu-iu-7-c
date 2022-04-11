@echo off
setlocal enabledelayedexpansion
set /a current=0
for /R %%i in (*in.txt) DO (
	cls
	set /a current+=1
	set output_file=%%i
	set output_file=!output_file:~0,-6!
	a.exe %%i check.txt
	if !current! EQU 5 ( a.exe %%i check.txt f)
	FC  check.txt !output_file!out.txt f
	pause
	)

)
del check.txt