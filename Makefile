build:
	x86_64-w64-mingw32-g++ src/main.cpp -o main.exe -std=c++17 -lWinmm -lntdll -lstdc++ -static