int fuzzindex;
uint8_t globalbyteread[1000]; // fuzzeri inputy sra mej a pahvum

uint8_t readbytes() {
 if(fuzzindex > 999) return 0;
	
 return globalbyteread[fuzzindex++];
} //read byte from LLVM

void symbolize(void *begin, void *end) {
    uintptr_t begin_addr = (uintptr_t) begin;
    uintptr_t end_addr = (uintptr_t) end;

    if(begin_addr == end_addr) { return; }
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
	explicit Symbolic(T new_val) {
		value = new_val;
	}
	operator T (void) const {return value;}
        T value; 

        friend std::ostream &operator<<(std::ostream &stream, const Symbolic<T> &obj) {
		return stream << obj.value;
	}
        //overloading unary operators
        T operator++() {return ++value;}  
        T operator++(int) {return ++value;} 
        T operator--() {return --value;}  
        T operator--(int) {return --value;} 
        T operator+() {return value;}
        T operator-() {return -value;}
        T operator~() {return ~value;}
        int operator!() {
            if(value) return 0;
            else return 1;
        }

        //overloading binary operators
	T operator+(Symbolic const &obj) {
	    return this->value + obj.value;
	}

	T operator-(Symbolic const &obj) {
	    return this->value - obj.value;
	}

	T operator*(Symbolic const &obj) {
	    return this->value * obj.value;
	}

	T operator/(Symbolic const &obj) {
	    return this->value / obj.value;
	}

	T operator^(Symbolic const &obj) {
	    return this->value ^ obj.value;
	}

	T operator&(Symbolic const &obj) {
	    return this->value & obj.value;
	}

	T operator+=(Symbolic const &obj) {
	    this->value += obj.value;
            return this->value;
	}

	T operator-=(Symbolic const &obj) {
	    this->value -= obj.value;
            return this->value;
	}

	T operator*=(Symbolic const &obj) {
	    this->value *= obj.value;
            return this->value;
	}

	T operator/=(Symbolic const &obj) {
	    this->value /= obj.value;
            return this->value;
	}

	T operator%=(Symbolic const &obj) {
	    this->value %= obj.value;
            return this->value;
	}

	T operator^=(Symbolic const &obj) {
	    this->value ^= obj.value;
            return this->value;
	}

	T operator&=(Symbolic const &obj) {
	    this->value &= obj.value;
            return this->value;
	}

	T operator|=(Symbolic const &obj) {
	    this->value |= obj.value;
            return this->value;
	}

	bool operator==(Symbolic const &obj) {
	    return this->value == obj.value;
	}
        
	bool operator!=(Symbolic const &obj) {
	    return this->value != obj.value;
	}
        
	bool operator>(Symbolic const &obj) {
	    return this->value > obj.value;
	}
        
	bool operator>=(Symbolic const &obj) {
	    return this->value >= obj.value;
	}
        
	bool operator<(Symbolic const &obj) {
	    return this->value < obj.value;
	}
        
	bool operator<=(Symbolic const &obj) {
	    return this->value <= obj.value;
	}
        
};

template <typename T>
class SymbolicLinearContainer {
    public:

        //SymbolicLinearContainer() {
	//    value.reserve(32);
	//    value.resize(32);
        //    symbolize(&(value.front()), &(value.back()));
        //}
        
        SymbolicLinearContainer(size_t len = 32) {
	    value.reserve(len);
	    value.resize(len);
            symbolize(&(value.front()), &(value.back()));
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

template <typename T>
class Symbolic<std::vector<T>> : public SymbolicLinearContainer<std::vector<T>> {
    public:
        Symbolic<std::vector<T>>() : SymbolicLinearContainer<std::vector<T>>() {}
        Symbolic<std::vector<T>>(size_t size) : SymbolicLinearContainer<std::vector<T>>(size) {}

};

std::ostream &operator<<(std::ostream &stream, const Symbolic<std::string>& obj) {
    return stream << obj.value;
}

using symbolic_double = Symbolic<double>;
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





