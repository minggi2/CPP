#include <iostream>
using namespace std;

class TimeHMS {
    int hour, min, sec;

public:
    TimeHMS(int h=0, int m=0, int s=0)
        : hour(h), min(m), sec(s) {}

    operator double() {

        return hour +
               min / 60.0 +
               sec / 3600.0;
    }
};

int main() {

    TimeHMS t1(1,20,30);

    double h = (double)t1;

    cout << "시간 = "
         << h << endl;

    return 0;
}