@echo off
setlocal enabledelayedexpansion
set choice=1
:res
cls
set /P keyword="enter keyword "
set /P begin_of="enter begin "
set /P end_of="enter end "
set /P pos_neg="1 - for positive tests, 0 - for negative tests"
set /a current=0
set output_file=abs
if %pos_neg% EQU 1 (
	set pos_neg="pos"
) else (
	set pos_neg="neg"
)
for /R %%i in (%pos_neg%*in.txt) DO (
	cls
	set /a current+=1
	if !current! GEQ !begin_of! if !current! LEQ !end_of! (
		set output_file=%%i
		set output_file=!output_file:~0,-6!
		REM a.exe < %%i > !output_file!out.txt если ввод не через параметр
		a.exe %%i !output_file!out.txt %keyword%
		if !choice! EQU 1 (echo %pos_neg% input test && type %%i && echo.)
		echo __________RESULT__________
		type !output_file!out.txt
		echo.
		echo __________________________
		pause
	)
)

set /P after_all="Press 1 to restart"
if %after_all% EQU 1 (goto :res)