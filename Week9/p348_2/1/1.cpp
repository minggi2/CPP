#include <iostream>
using namespace std;

class MyTime {
private:
    int h, m, s, ms;

public:
    // 기본 생성자
    MyTime() {
        h = m = s = ms = 0;
    }

    // convert 함수 (초 → 시간 변환)
    void convert(double duration) {
        int total_ms = (int)(duration * 1000);

        h = total_ms / (1000 * 60 * 60);
        total_ms %= (1000 * 60 * 60);

        m = total_ms / (1000 * 60);
        total_ms %= (1000 * 60);

        s = total_ms / 1000;
        ms = total_ms % 1000;
    }

    // (2번 핵심) double 생성자
    MyTime(double duration) {
        convert(duration);
    }

    void print() {
        cout << h << ":" << m << ":" << s << ":" << ms << endl;
    }
};

int main() {
    MyTime t(3661.789);
    t.print();

    return 0;
}