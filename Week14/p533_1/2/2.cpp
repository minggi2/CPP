#include <iostream>
using namespace std;

class TimeHMS {
    int hour, min, sec;

public:
    TimeHMS(int h=0, int m=0, int s=0)
        : hour(h), min(m), sec(s) {}

    TimeHMS operator-(const TimeHMS& t) {

        int total1 = hour*3600 + min*60 + sec;
        int total2 = t.hour*3600 + t.min*60 + t.sec;

        int diff = total1 - total2;

        int h = diff / 3600;
        diff %= 3600;

        int m = diff / 60;
        int s = diff % 60;

        return TimeHMS(h,m,s);
    }

    void display() {
        cout << hour << "시 "
             << min << "분 "
             << sec << "초" << endl;
    }
};

int main() {

    TimeHMS t1(4,35,46);
    TimeHMS t2(1,20,30);

    TimeHMS t3 = t1 - t2;

    t3.display();

    return 0;
}