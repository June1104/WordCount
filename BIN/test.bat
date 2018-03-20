echo off
start wc.exe wc.exe -l test.c
start wc.exe wc.exe -w test.c
start wc.exe wc.exe -c test.c
wc.exe -l -w test.c
wc.exe -c test.c -o output.txt
wc.exe -c -w -l test.c
wc.exe -c -w -l test.c -o outputl.txt
wc.exe -c -w -l test1.c
wc.exe -c -w -l test1.c -o output2.txt
wc.exe -c test2.c 