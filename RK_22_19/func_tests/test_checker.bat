@echo off
cls
setlocal enabledelayedexpansion
set current_test=C:\Users\chel\Desktop\te\neg_02_in.txt
set num=1
echo _______________________POSITIVE_TEST_CHECK_______________________
for /R %%i in (pos*in.bin) DO (
	cls
	a.exe %%i > output.txt
	set current_test=%%i
	set current_test=!current_test:~0,-6!
	echo _________________________________________________________________
	echo positive test number: !num! 
	set /A num+=1
	fc !current_test!out.txt output.txt
	echo _________________________________________________________________
	pause
)
set num=1
echo _______________________NEGATIVE_TEST_CHECK_______________________
for /R %%i in (neg*in.bin) DO (
	cls
	a.exe %%i > output.txt
	set current_test=%%i
	set current_test=!current_test:~0,-6!
	echo _________________________________________________________________
	echo negative test number: !num! 
	set /A num+=1
	fc !current_test!out.txt output.txt
	echo _________________________________________________________________
	pause
)
del output.txt
pause