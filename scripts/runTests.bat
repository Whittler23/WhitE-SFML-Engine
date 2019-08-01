call "%VSConsole%"
devenv ..\WhitE.sln /Build Tests /Project Tests /ProjectConfig Tests
start  /D ..\..\ /B ..\testsFiles\testBin\bin\Tests.exe
PAUSE
