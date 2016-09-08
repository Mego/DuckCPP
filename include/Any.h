#ifndef ANY_H
#define ANY_H

#include <memory>
#include <typeinfo>

class Any {
  public:
    template<typename T>
    Any(T value);
    template<typename T>
    Any(T* value);
    virtual ~Any() {
        _val_ptr.reset();
    }
    Any(const Any& other): _val_ptr(other._val_ptr), _val_type(other._val_type) {

    }
    Any& operator=(const Any& other) {
        if (this == &other) return *this; // handle self assignment
        this->_val_ptr.reset();
        this->_val_ptr = other._val_ptr;
        this->_val_type = other._val_type;
        return *this;
    }
    template<typename T>
    T get_value();

  protected:

  private:
    std::shared_ptr<void> _val_ptr;
    std::type_info* _val_type;
};

template<typename T>
Any::Any(T value) {
    this->_val_ptr.reset(new T(value));
    this->_val_type = const_cast<std::type_info*>(&typeid(T));
}

template<typename T>
Any::Any(T* value) {
    this->_val_ptr.reset(value);
    this->_val_type = const_cast<std::type_info*>(&typeid(typename std::remove_pointer<T>::type));
}

template<>
Any::Any<const char>(const char* value): Any(new std::string(value)) {

}

template<typename T>
T Any::get_value() {
    if(typeid(T) == *(this->_val_type)) {
        return *reinterpret_cast<T*>(this->_val_ptr.get());
    }
    else {
        throw std::bad_cast();
    }
}

#endif // ANY_H
