#include <iostream>
using namespace std;

class TimeHMS {
    int hour, min, sec;

public:
    TimeHMS(int h=0, int m=0, int s=0)
        : hour(h), min(m), sec(s) {}

    operator int() {
        return hour * 3600 + min * 60 + sec;
    }

    friend TimeHMS operator*(int n, const TimeHMS& t);

    void display() {
        cout << hour << "시 "
             << min << "분 "
             << sec << "초" << endl;
    }
};

TimeHMS operator*(int n, const TimeHMS& t)
{
    int total = n * (t.hour * 3600 + t.min * 60 + t.sec);

    int h = total / 3600;
    total %= 3600;

    int m = total / 60;
    int s = total % 60;

    return TimeHMS(h, m, s);
}

int main()
{
    TimeHMS t1(1,20,30);

    TimeHMS t2 = 2 * t1;

    t2.display();

    return 0;
}