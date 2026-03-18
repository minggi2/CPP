#include <iostream>

int main() {
    int n;
    double pi = 0.0;
    double sign = 1.0;

    std::cin >> n;

    for (int i = 0; i <= n; i++) {
        pi += sign / (2 * i + 1);
        sign = -sign;
    }

    std::cout << pi * 4 << std::endl;

    return 0;
}