build:
	g++ src/main.cpp -o bin/main.exe -static -DCURL_STATICLIB  -lwinmm -lntdll -lstdc++ -lcurl -lnghttp2 -lssh2 -lssh2 -lpsl -lbcrypt -ladvapi32 -lcrypt32 -lbcrypt -lssl -lcrypto -lssl -lcrypto -lgdi32 -lwldap32 -lzstd -lzstd -lbrotlidec -lbrotlidec -lz -lws2_32 -lbrotlidec -lbrotlicommon -lidn2 -L/mingw64/lib -liconv -L/mingw64/lib -lunistring -lole32 -loleaut32 -std=c++17