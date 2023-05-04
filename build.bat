@Echo off
title Construyendo distribuible
setlocal EnableDelayedExpansion enableextensions

for /F "tokens=1,2 delims=#" %%a in ('"prompt #$H#$E# & echo on & for %%b in (1) do     rem"') do (
  set "DEL=%%a"
)

set carpeta=dist

call :colorEcho 01 "Ejecutando MakeFile"
call make
echo.

if exist "%carpeta%" (
    call :colorEcho 04 "Carpeta %carpeta% existente"
    call :colorEcho 06 "Eliminando elementos..."
    del /Q "%carpeta%\*.*"
) else (
    call :colorEcho 06 "Creando carpeta..."
    mkdir "%carpeta%"
    call :colorEcho 02 "Se ha creado la carpeta %carpeta% satisfactoriamente"
)

set listaArchivos=cli.exe index.exe hasse.exe graphviz-install-8.0.3-win64.exe .\x64\Release\UPCalcula1.exe

set totalArchivos=0
for %%a in (%listaArchivos%) do (
    set /A totalArchivos+=1
)

set i=0
set /a step=100 / %totalArchivos%

call :colorEcho 06 "Copiando elementos"
for %%a in (%listaArchivos%) do (
    if not exist "%%a" (
        call :colorEcho 04 "El archivo %%a no existe."
        pause
        exit /b
    )

    xcopy /I "%%a" "%carpeta%\" >nul
    set /A i+=step
    call :drawProgressBar %%i ""
)
call :finalizeProgressBar 1

echo.
echo.
call :colorEcho 02 "Completado Satisfactoriamente"
pause

:drawProgressBar value [text]
    if "%~1"=="" goto :eof
    if not defined pb.barArea call :initProgressBar
    setlocal enableextensions enabledelayedexpansion
    set /a "pb.value=%~1 %% 101", "pb.filled=pb.value*pb.barArea/100", "pb.dotted=pb.barArea-pb.filled", "pb.pct=1000+pb.value"
    set "pb.pct=%pb.pct:~-3%"
    if "%~2"=="" ( set "pb.text=" ) else ( 
        set "pb.text=%~2%pb.back%" 
        set "pb.text=!pb.text:~0,%pb.textArea%!"
    )
    <nul set /p "pb.prompt=[!pb.fill:~0,%pb.filled%!!pb.dots:~0,%pb.dotted%!][ %pb.pct% ] %pb.text%!pb.cr!"
    endlocal
    goto :eof

:initProgressBar [fillChar] [dotChar]
    if defined pb.cr call :finalizeProgressBar
    for /f %%a in ('copy "%~f0" nul /z') do set "pb.cr=%%a"
    if "%~1"=="" ( set "pb.fillChar=#" ) else ( set "pb.fillChar=%~1" )
    if "%~2"=="" ( set "pb.dotChar=." ) else ( set "pb.dotChar=%~2" )
    set "pb.console.columns="
    for /f "tokens=2 skip=4" %%f in ('mode con') do if not defined pb.console.columns set "pb.console.columns=%%f"
    set /a "pb.barArea=pb.console.columns/2-2", "pb.textArea=pb.barArea-9"
    set "pb.fill="
    setlocal enableextensions enabledelayedexpansion
    for /l %%p in (1 1 %pb.barArea%) do set "pb.fill=!pb.fill!%pb.fillChar%"
    set "pb.fill=!pb.fill:~0,%pb.barArea%!"
    set "pb.dots=!pb.fill:%pb.fillChar%=%pb.dotChar%!"
    set "pb.back=!pb.fill:~0,%pb.textArea%!
    set "pb.back=!pb.back:%pb.fillChar%= !"
    endlocal & set "pb.fill=%pb.fill%" & set "pb.dots=%pb.dots%" & set "pb.back=%pb.back%"
    goto :eof

:finalizeProgressBar [erase]
    if defined pb.cr (
        if not "%~1"=="" (
            setlocal enabledelayedexpansion
            set "pb.back="
            for /l %%p in (1 1 %pb.console.columns%) do set "pb.back=!pb.back! "
            <nul set /p "pb.prompt=!pb.cr!!pb.back:~1!!pb.cr!"
            endlocal
        )
    )
    for /f "tokens=1 delims==" %%v in ('set pb.') do set "%%v="
    goto :eof

:colorEcho
    <nul set /p ".=%DEL%" > "%~2"
    findstr /v /a:%1 /R "^$" "%~2" nul
    del "%~2" > nul 2>&1i
    echo.
    goto :eof