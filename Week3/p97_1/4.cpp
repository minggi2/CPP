#include <iostream>

int main() 
{
    for (int i = 1; i <= 5; i++) 
    {
        for (int k = 5; k > i; k--) 
        {
            std::cout << "  "; 
        }

        for (int s = i; s >= 1; s--) 
        {
            std::cout << s << " ";
        }

        for (int j = 2; j <= i; j++) 
        {
            std::cout << j << " ";
        }

        std::cout << "\n";
    }

    return 0;
}