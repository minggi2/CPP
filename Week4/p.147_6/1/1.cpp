#include <iostream>
#include <cstdlib>
#include <ctime>

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

    int digit;
    std::cout << "자리수 선택 (3~9): ";
    std::cin >> digit;

    switch (digit) {
        case 3: case 4: case 5: case 6: case 7: case 8: case 9:
            playAddition(digit);
            break;
        default:
            std::cout << "잘못된 입력입니다.\n";
    }

    return 0;
}