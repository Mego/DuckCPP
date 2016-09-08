#include <iostream>
#include <string>

#include "Any.h"

using namespace std;

int main() {
    Any foo = 5;
    Any bar = string("bar");
    Any baz = "test";
    cout << foo.get_value<int>() << endl;
    try {
        cout << foo.get_value<double>() << endl;
    }
    catch(std::bad_cast e) {
        cout << "Failed to convert int Any to double" << endl;
    }
    cout << bar.get_value<string>() << endl;
    cout << baz.get_value<string>() << endl;
}
