call "%VSConsole%"
devenv ..\WhitE.sln /Build Debug /Project Tests /ProjectConfig Tests
start  ..\testsFiles\testBin\bin\Tests.exe
PAUSE
