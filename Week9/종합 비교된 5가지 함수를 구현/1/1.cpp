#include <iostream>
using namespace std;

class Complex {
public:
    int real, imag;

    Complex(int r = 0, int i = 0);
    void print();

    void add(Complex&, Complex&); 
    Complex add(Complex&);
    Complex operator+(Complex&);
};

Complex::Complex(int r, int i) {
    real = r;
    imag = i;
}

void Complex::print() {
    cout << real << " + " << imag << "i" << endl;
}

void Complex::add(Complex& a, Complex& b) {   // 3
    real = a.real + b.real;
    imag = a.imag + b.imag;
}

Complex Complex::add(Complex& b) {            // 4
    return Complex(real + b.real, imag + b.imag);
}

Complex Complex::operator+(Complex& b) {      // 5
    return Complex(real + b.real, imag + b.imag);
}

void add1(Complex& a, Complex& b, Complex& c) {   // 1
    c.real = a.real + b.real;
    c.imag = a.imag + b.imag;
}

Complex add2(Complex a, Complex b) {              // 2
    return Complex(a.real + b.real, a.imag + b.imag);
}

int main() {
    Complex a(1, 2), b(3, 4), c;

    add1(a, b, c);   // 1
    c.print();

    c = add2(a, b);  // 2
    c.print();

    c.add(a, b);     // 3
    c.print();

    c = a.add(b);    // 4
    c.print();

    c = a + b;       // 5
    c.print();

    return 0;
}