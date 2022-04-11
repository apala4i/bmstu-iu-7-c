@echo off
set /P neg_pos="neg-0 pos-1 "
if %neg_pos% EQU 0 (
	set neg_pos="neg"
) else (
	set neg_pos="pos"
)
for /R %%i in (%neg_pos%*in.txt) do (
	cls
	echo %%i
	echo.
	type %%i
	pause
)
pause