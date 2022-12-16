




uint8_t readbytes() { 
	return (uint8_t)196; //read from llvm
}

void symbolize(void *begin, void *end) {
    uintptr_t begin_addr = (uintptr_t) begin;
    uintptr_t end_addr = (uintptr_t) end;

    if(begin_addr == end_addr) { return;}
    else {
        uint8_t *bytes = (uint8_t *) begin;
        for(uintptr_t i = 0, max_i = (end_addr - begin_addr); i < max_i; ++i) {
            bytes[i] = readbytes();
        }
    }
}

template <typename T>
class Symbolic {
    public:
        Symbolic(void) {
	    T *val_ptr = &value;
            symbolize(val_ptr, &(val_ptr[1]));
        } 
        
        void operator++() {value++;}  
        void operator++(int) {value++; } 

        operator T (void) const {
            return value;
        } 
    
        T value; 
};

template <typename T>
class SymbolicLinearContainer {
    public:

        SymbolicLinearContainer() {
	    value.reserve(32);
        }
        
        SymbolicLinearContainer(size_t len) : value(len) {
            symbolize(&(value.front()),&(value.back()));
            
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
    Symbolic<std::string>(size_t size) :  SymbolicLinearContainer<std::string>(size) {}
            
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
