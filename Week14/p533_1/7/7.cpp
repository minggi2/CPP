#include <iostream>
using namespace std;

class TimeHMS {
    int hour, min, sec;

public:
    TimeHMS(int h=0, int m=0, int s=0)
        : hour(h), min(m), sec(s) {}

    operator int() {

        return hour * 3600 +
               min * 60 +
               sec;
    }
};

int main() {

    TimeHMS t1(1,20,30);

    int totalSec = (int)t1;

    cout << "전체 초 = "
         << totalSec << endl;

    return 0;
}