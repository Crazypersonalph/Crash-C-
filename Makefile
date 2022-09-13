build:
	x86_64-w64-mingw32-g++ src/main.cpp -o main.exe -lwinmm -lntdll -lstdc++ -static -std=c++17