#include <iostream>
using namespace std;

class TimeHMS {
    int hour, min, sec;

public:
    TimeHMS(int h=0, int m=0, int s=0)
        : hour(h), min(m), sec(s) {}

    TimeHMS operator++(int) {
        TimeHMS temp = *this;

        sec++;

        if(sec >= 60) {
            sec = 0;
            min++;

            if(min >= 60) {
                min = 0;
                hour++;
            }
        }
        return temp;
    }

    TimeHMS operator--(int) {
        TimeHMS temp = *this;

        sec--;

        if(sec < 0) {
            sec = 59;
            min--;

            if(min < 0) {
                min = 59;
                hour--;
            }
        }
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

    t1++;
    t1.display();

    t1--;
    t1.display();

    return 0;
}