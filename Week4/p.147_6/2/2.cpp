#include <iostream>
#include <cstdlib>
#include <ctime>

void playTwoDigitMultiply() {
    int a = rand() % 90 + 10;
    int b = rand() % 90 + 10;

    int answer;
    std::cout << a << " x " << b << " = ";
    std::cin >> answer;

    if (answer == a * b)
        std::cout << "정답!\n";
    else
        std::cout << "오답! 정답: " << a * b << "\n";
}

int main() {
    srand(time(0));

    int choice;
    std::cout << "1: 두 자리 곱셈\n선택: ";
    std::cin >> choice;

    switch (choice) {
        case 1:
            playTwoDigitMultiply();
            break;
        default:
            std::cout << "잘못된 입력입니다.\n";
    }

    return 0;
}