#include "Duck.h"

Duck::~Duck() {
    //dtor
}

Duck::Duck(const Duck& other): Any(other) {

}
