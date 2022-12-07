#include<iostream>
#include<typeinfo>
#include <random>
#include<time.h>
template <typename T>
class Symbolic {
    public:
        Symbolic(void) {
            srand(time(NULL));
            T value = 5;
        }   

        operator T (void) const {
            return value;
        } 
    
        T value = rand() % 100; 
};

template <typename T>
class Symbolic {
    public:
        Symbolic(void) {
            T *val_ptr = &value;
  //          SymbolizeData(val_ptr, &(val_ptr[1]));
        }
        operator T (void) const {
            return value;
        }
        T value;
};



template <typename T>
class Symbolic {
    public:
        Symbolic(void) {
            T *val_ptr = &value;
            std::cout << " in the symbolic constructor " ;
  //          SymbolizeData(val_ptr, &(val_ptr[1]));
        }
        operator T (void) const {
            return value;
        }
        T value;
};



template <typename T>
class SymbolicLinearContainer {
    public:
        SymbolicLinearContainer(size_t len) : value(len) {
            if (!value.empty()) {
               // SymbolizeData(&(value.front()), &(value.back()));
            }
        }

        SymbolicLinearContainer() {
            //std::cout << "in the linearcontainer constructor " ;
            //std::cout << value << std::endl;
            //value.reserve(32);
            //    value.resize(SizeInRange(0, 32));
            std::string a = "";
            for(int i = 0; i < 10; ++i)
                a += "abcdef01234567890"[rand() % 16];
            value = a;
            //std::cout << value << std::endl;
        }

        SymbolicLinearContainer(int size, std::string allowed) {
            //std::cout << "in the linearcontainer constructor " ;
            //std::cout << value << std::endl;
            //value.reserve(32);
            //    value.resize(SizeInRange(0, 32));
            std::string a = "";
            for(int i = 0; i < num; ++i)
                a += allowed[rand() % 16];
            value = a;
            //std::cout << value << std::endl;
        }
    
    operator T (void) const {
        return value;
    }
    T value ;
};
template <>
class Symbolic<std::string> : public SymbolicLinearContainer<std::string> {};


using symbolic_char = Symbolic<char>;
using symbolic_short = Symbolic<short>;
using symbolic_int = Symbolic<int>;
using symbolic_unsigned = Symbolic<unsigned>;
using symbolic_long = Symbolic<long>;

using symbolic_int8_t = Symbolic<int8_t>;
using symbolic_uint8_t = Symbolic<uint8_t>;
using symbolic_int16_t = Symbolic<int16_t>;
using symbolic_uint16_t = Symbolic<uint16_t>;
using symbolic_int32_t = Symbolic<int32_t>;
using symbolic_uint32_t = Symbolic<uint32_t>;
using symbolic_int64_t = Symbolic<int64_t>;
using symbolic_uint64_t = Symbolic<uint64_t>;

using symolic_str = Symbolic<std::string>;
