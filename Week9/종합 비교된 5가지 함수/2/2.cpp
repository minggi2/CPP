#include <iostream>
using namespace std;

class Complex {
public:
    int real, imag;
};

Complex add(Complex a, Complex b) {
    Complex c;
    c.real = a.real + b.real;
    c.imag = a.imag + b.imag;
    return c;
}

int main() {
    Complex a = {1, 2}, b = {3, 4};
    Complex c = add(a, b);

    cout << c.real << " + " << c.imag << "i";
}
