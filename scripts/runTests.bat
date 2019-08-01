call "%VSConsole%"
devenv ..\WhitE.sln /Build Debug /Project Tests /ProjectConfig Tests
start  /D ..\..\ /B ..\testsFiles\testBin\bin\Tests.exe
PAUSE
