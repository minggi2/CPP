#1

#include <iostream>

int main()
{
    for(int i= 1; i <=5; ++i)
    {

        for(int j = 1; j <= i; ++j)
       { 
        std:: cout << j;
       }
       std::cout << "\n";
    }
}

#2

#include <iostream>

int main() 
{
    for (int i = 1; i <= 5; ++i)
    {
        for (int j = 5; j >= i; --j)
        {
            std::cout << j;
        }
        std::cout << "\n";
    }

    return 0;
}

#3

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

#4
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