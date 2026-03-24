#include <algorithm>
#include <iostream>


std:: string reverse(std::string s);

int main()
{
    std::string s;
    std::cin >> s;

    std::cout << reverse(s) << std::endl;
}

std::string reverse(std::string s)
{
    reverse(s.begin(), s.end());
    return s;
}