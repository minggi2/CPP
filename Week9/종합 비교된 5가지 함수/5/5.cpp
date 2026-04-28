#include <iostream>
using namespace std;

class Complex {
public:
    int real, imag;

    Complex operator+(Complex&);
};

Complex Complex::operator+(Complex &b) {
    Complex temp;
    temp.real = real + b.real;
    temp.imag = imag + b.imag;
    return temp;
}

int main() {
    Complex a = {1,2}, b = {3,4};
    Complex c = a + b;

    cout << c.real << " + " << c.imag << "i";
}