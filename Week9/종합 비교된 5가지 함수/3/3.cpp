#include <iostream>
using namespace std;

class Complex {
public:
    int real, imag;

    void add(Complex&, Complex&); 
};

void Complex::add(Complex &a, Complex &b) {
    real = a.real + b.real;
    imag = a.imag + b.imag;
}

int main() {
    Complex a = {1,2}, b = {3,4}, c;
    c.add(a, b);

    cout << c.real << " + " << c.imag << "i";
}