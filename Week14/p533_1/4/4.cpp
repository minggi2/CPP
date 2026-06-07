#include <iostream>
using namespace std;

class TimeHMS {
    int hour, min, sec;

public:
    TimeHMS(int h=0, int m=0, int s=0)
        : hour(h), min(m), sec(s) {}

    TimeHMS& operator++() {
        hour++;
        return *this;
    }

    TimeHMS& operator--() {
        hour--;
        return *this;
    }

    void display() {
        cout << hour << "시 "
             << min << "분 "
             << sec << "초" << endl;
    }
};

int main() {

    TimeHMS t1(1,20,30);

    ++t1;
    t1.display();

    --t1;
    t1.display();

    return 0;
}