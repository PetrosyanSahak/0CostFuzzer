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
class SymbolicLinearContainer {
    public:
        SymbolicLinearContainer(size_t len) : value(len) {
            if (!value.empty()) {
               // SymbolizeData(&(value.front()), &(value.back()));
            }
        }

        SymbolicLinearContainer() {
            value.reserve(32);
        //        value.resize(SizeInRange(0, 32));
        }

    operator T (void) const {
        return value;
    }

    T value = "sahak";
};
template <>
class Symbolic<std::string> : public SymbolicLinearContainer<std::string> {};
