build:
	x86_64-w64-mingw32-g++ src/main.cpp -o main.exe -std=c++14 -lWinmm -lntdll -static