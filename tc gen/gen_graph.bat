@echo off

if [%1]==[] (set /A n = 10) else (set /A n = %1)
if [%2]==[] (set /A startTcNum = 1) else (set /A startTcNum = %2)

echo Start Compiling

echo Compiling gen, solution...

g++ -std=c++17 gen.cpp -o gen
g++ -std=c++17 main.cpp -o solution

echo Done compiling.

set /A endLoop = %startTcNum%+%n%-1
for /l %%x in (%startTcNum%, 1, %endLoop%) do (
    echo Generating test case #%%x
    ping 127.0.0.1 -n 2 > nul

    gen > %%x.txt

)

echo Start Transforming

g++ -std=c++17 transform.cpp -o trans

set /A endLoop = %startTcNum%+%n%-1
for /l %%x in (%startTcNum%, 1, %endLoop%) do (
    echo Transforming test case #%%x

    copy %%x.txt g_%%x.txt
    trans < g_%%x.txt > %%x.txt
    DEL g_%%x.txt

    solution < %%x.txt > %%x_ans.txt
)