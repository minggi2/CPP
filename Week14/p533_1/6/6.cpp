#include <iostream>
using namespace std;

class TimeHMS {
    int hour, min, sec;

public:
    TimeHMS(int h=0, int m=0, int s=0)
        : hour(h), min(m), sec(s) {}

    int operator[](int index) {

        if(index == 0) return hour;
        if(index == 1) return min;
        if(index == 2) return sec;

        return -1;
    }
};

int main() {

    TimeHMS t1(1,20,30);

    cout << "Hour : " << t1[0] << endl;
    cout << "Min  : " << t1[1] << endl;
    cout << "Sec  : " << t1[2] << endl;

    return 0;
}