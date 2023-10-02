/*
    In the greet.cpp
    Algorithm: Recursion
    yu.shao@amd.com

    Note of development:
*/
#include <iostream>
#include <string>

using std::cout;
using std::endl;

void greet2(std::string name) {
    cout << "How are you, " + name + "?" << endl;
}

void bye() {
    cout << "ok, bye" << endl;
}

void greet(std::string name) {
    cout << "Hello, " + name + "!" << endl;
    greet2(name);
    cout << "Getting ready to say bye..." << endl;
    bye();
}

int main() {
    greet("Adit");

    return 0;
}