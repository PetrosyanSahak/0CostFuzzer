#include<iostream>
#include"newsymb.h"
#include"ggg.h"
extern "C" int LLVMFuzzerTestOneInput(const uint8_t *Data, size_t Size) {
    if(Size < 1000) return 1;
    fuzzindex = 0;
    for(int i = 1; i < 1000; i++)
        globalbyteread[i] = Data[i];

    //stexic main funkcian piti liner
    //symbolic_int a, b;
    //std::cout << "\n\n";
    //std::cout << "symbolic a is : " << a << '\n';
    //std::cout << "symbolic b is : " << b << '\n';
    //std::cout << "symbolic a + b is : " << a + b << '\n';
    //symbolic_double d;
    //std::cout << "symbolic double d is : " << d << '\n';
    //std::cout << " d + b is : " << d + b << '\n';
    //std::cout << " d + a is : " << d + a << '\n';
    //int f = 7;
    //std::cout << "f is a standard integer: " << f << '\n';
    //std::cout << "f + symbolic a is : " << f +a << '\n';
    //std::cout << "assigning f to symbolic a + symbolic b: " << '\n';
    //f = a + b;
    //std::cout << "f now is : " << f << '\n';
    //std::cout << "assigning f to symbolic a + symbolic d: " << '\n';
    //f = a + d;
    //std::cout << "f now is : " << f << '\n';
    //std::cout << "\n\n";
    //// minchev stex
    man();
	
   
    return 0;
}
