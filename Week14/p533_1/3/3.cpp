#include <iostream>
using namespace std;

class TimeHMS {
    int hour, min, sec;

public:
    TimeHMS(int h=0, int m=0, int s=0)
        : hour(h), min(m), sec(s) {}

    bool operator==(const TimeHMS& t) {
        return hour==t.hour &&
               min==t.min &&
               sec==t.sec;
    }

    bool operator!=(const TimeHMS& t) {
        return !(*this == t);
    }
};

int main() {

    TimeHMS t1(1,20,30);
    TimeHMS t2(1,20,30);
    TimeHMS t3(4,35,46);

    cout << (t1==t2) << endl;
    cout << (t1!=t3) << endl;

    return 0;
}