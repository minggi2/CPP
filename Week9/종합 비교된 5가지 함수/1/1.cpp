#include <iostream>
using namespace std;

class Complex {
public:
    int real, imag;
};

void add(Complex &a, Complex &b, Complex &c) {
    c.real = a.real + b.real;
    c.imag = a.imag + b.imag;
}

int main() {
    Complex a = {1, 2}, b = {3, 4}, c;
    add(a, b, c);

    cout << c.real << " + " << c.imag << "i";
}