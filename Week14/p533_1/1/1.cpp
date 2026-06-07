#include <iostream>
using namespace std;

class TimeHMS {
    int hour, min, sec;

public:
    TimeHMS(int h=0, int m=0, int s=0)
        : hour(h), min(m), sec(s) {}

    TimeHMS operator+(const TimeHMS& t) {
        TimeHMS temp;

        temp.sec = sec + t.sec;
        temp.min = min + t.min;
        temp.hour = hour + t.hour;

        temp.min += temp.sec / 60;
        temp.sec %= 60;

        temp.hour += temp.min / 60;
        temp.min %= 60;

        return temp;
    }

    void display() {
        cout << hour << "시 "
             << min << "분 "
             << sec << "초" << endl;
    }
};

int main() {
    TimeHMS t1(1,20,30);
    TimeHMS t2(4,35,46);

    TimeHMS t3 = t1 + t2;

    t3.display();

    return 0;
}