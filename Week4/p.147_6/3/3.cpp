#include <iostream>
#include <cstdlib>
#include <ctime>

// 구구단
void playGuguOnce() {
    int a = rand() % 9 + 1;
    int b = rand() % 9 + 1;

    int answer;
    std::cout << a << " x " << b << " = ";
    std::cin >> answer;

    if (answer == a * b)
        std::cout << "정답!\n";
    else
        std::cout << "오답! 정답: " << a * b << "\n";
}

// 두 자리 곱셈
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

// n자리 덧셈
void playAddition(int digit) {
    int min = 1;
    for (int i = 1; i < digit; i++) min *= 10;
    int max = min * 10 - 1;

    int a = rand() % (max - min + 1) + min;
    int b = rand() % (max - min + 1) + min;

    int answer;
    std::cout << a << " + " << b << " = ";
    std::cin >> answer;

    if (answer == a + b)
        std::cout << "정답!\n";
    else
        std::cout << "오답! 정답: " << a + b << "\n";
}

int main() {
    srand(time(0));

    int choice;
    std::cout << "게임 선택\n";
    std::cout << "1: 구구단\n";
    std::cout << "2: 두 자리 수 곱셈\n";
    std::cout << "3~9: n자리 수 덧셈\n";
    std::cout << "선택: ";
    std::cin >> choice;

    switch (choice) {
        case 1:
            playGuguOnce();
            break;
        case 2:
            playTwoDigitMultiply();
            break;
        case 3: case 4: case 5: case 6: case 7: case 8: case 9:
            playAddition(choice);
            break;
        default:
            std::cout << "잘못된 입력입니다.\n";
    }

    return 0;
}