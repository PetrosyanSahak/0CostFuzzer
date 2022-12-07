#include<iostream>
#include<typeinfo>
#include <random>
#include<time.h>
#define ALPHABET "`~1!2@3#4$5%6^7&8*9(0)-_=+]}[{pPoOiIuUyYtTrReEwWqQaAsSdDfFgGhHjJkKlL;:\"'\\zZxXcCvVbBnNmM,<.>/?"

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
class SymbolicLinearContainer {
    public:

        SymbolicLinearContainer() {
            std::string a = "";
            for(int i = 0; i < 1000; ++i)
                a += ALPHABET[rand() % 93];
            value = a;
        }
        
        SymbolicLinearContainer(int size, std::string allowed = ALPHABET ) {
            std::string a = "";
            for(int i = 0; i < size; ++i)
                a += allowed[rand() % size];
            value = a;
        }
    
    operator T (void) const {
        return value;
    }
    T value ;
};
template <>
class Symbolic<std::string> : public SymbolicLinearContainer<std::string> {
    public:
    Symbolic<std::string>() :  SymbolicLinearContainer<std::string>() {}
    Symbolic<std::string>(int size) :  SymbolicLinearContainer<std::string>(size) {}
    Symbolic<std::string>(int size, std::string allowed)
            : SymbolicLinearContainer<std::string>(size, allowed) {}
            
    std::string operator + ( Symbolic<std::string> const &obj) {
        return this->value + obj.value;
    }
    
};

std::ostream &operator<<(std::ostream &stream, const Symbolic<std::string>& obj) {
        
    return stream << obj.value;
    }

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

using symbolic_str = Symbolic<std::string>;

int main() {
    srand(time(NULL));
    
    symbolic_int gg;
    std::cout << gg << '\n';
    
    symbolic_str symstr(28);
    symbolic_str anoth(20);
    std::string a = symstr;
    std::string b = anoth;
    std::cout << a << '\n';
    std::cout << b << '\n';
    std::cout << symstr+anoth;
    std::cout << "this is overloaded" << symstr;
    return 0;

}
