#include <iostream>

int main() {
    for (int i = 1; i <= 5; i++) 
    {
        for (int j = 5; j > i; j--) 
        {
            std::cout << "  ";
        }
        for (int k = i; k >= 1; k--) 
        {
            std::cout << k << " ";
        }
        std::cout << "\n";
    }
    return 0;
}