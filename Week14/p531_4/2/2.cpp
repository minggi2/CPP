#include <iostream>
#include <cstdlib>
#include <ctime>
using namespace std;

class SampleList {
    int list[100];

public:
    SampleList() {
        for (int x = 0; x < 100; x++)
            list[x] = rand() % 1000;
    }

    // 함수 호출 연산자 중복
    int& operator()(int index) {
        return list[index];
    }
};

int main() {
    srand((unsigned)time(0));

    SampleList s;

    cout << "s(10) = " << s(10) << endl;

    s(10) = 500;
    cout << "변경 후 s(10) = " << s(10) << endl;

    return 0;
}