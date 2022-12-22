#include<iostream>
#include"symbolic.h"
#include"main.h"

extern "C" int LLVMFuzzerTestOneInput(const uint8_t *Data, size_t Size) {
	
    if(Size < 1000) return 1;
	
    fuzzindex = 0;
    for(int i = 1; i < 1000; i++)
        globalbyteread[i] = Data[i];

    man();
	
    return 0;
}
