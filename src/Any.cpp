#include <string>
#include <type_traits>

#include "Any.h"

Any::Any(const Any& other): _val_ptr(other._val_ptr) {

}

Any& Any::operator=(const Any& rhs) {
    if (this == &rhs) return *this; // handle self assignment
    this->_val_ptr.reset();
    this->_val_ptr = rhs._val_ptr;
    return *this;
}

template<typename T>
T& Any::get_value() {
    T* p = dynamic_cast<T*>(this->_val_ptr.get());
    if(p != nullptr) {
        return p;
    } else {
        throw std::bad_cast((std::string("Cannot convert value to ") + typeid(T).name()).c_str());
    }
}

