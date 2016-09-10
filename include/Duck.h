#ifndef DUCK_H
#define DUCK_H

#include <exception>
#include <map>
#include <string>

#include "Any.h"

typedef std::map<std::string, Any> AttributeDict;

class Duck : public Any {
  public:
    template<typename T>
    Duck(T value): Any(value) {}
    virtual ~Duck();
    Duck(const Duck& other);
    Any& getattr(const std::string name) {
        return this->_attrs.at(name);
    }
    Any& getattr(const char* name) {
        return this->getattr(std::string(name));
    }
    template<typename T>
    void setattr(const std::string name, T value) {
        this->_attrs[name] = Any(value);
    }
    template<typename T>
    void setattr(const char* name, T value) {
        this->setattr(std::string(name), value);
    }

  protected:

  private:
    AttributeDict _attrs;

};

template<>
inline void Duck::setattr<Any&>(const std::string name, Any& value) {
    _attrs[name] = value;
}

#endif // DUCK_H
