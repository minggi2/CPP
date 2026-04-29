#include <iostream>
using namespace std;

class MyTime {
private:
    int h, m, s, ms;

public:
    // 기본 생성자 (모두 0)
    MyTime() {
        h = 0;
        m = 0;
        s = 0;
        ms = 0;
    }

    // (방법1) 초기화 리스트 사용 X
    MyTime(int h, int m, int s, int ms) {
        this->h = h;
        this->m = m;
        this->s = s;
        this->ms = ms;
    }

    // (방법2) 초기화 리스트 사용 O
    /*
    MyTime(int h, int m, int s, int ms)
        : h(h), m(m), s(s), ms(ms) {}
    */

    void print() {
        cout << h << ":" << m << ":" << s << ":" << ms << endl;
    }
};

int main() {
    MyTime t1;
    MyTime t2(1, 2, 3, 400);

    t1.print();
    t2.print();

    return 0;
}