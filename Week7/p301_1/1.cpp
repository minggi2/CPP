#include <iostream>
using namespace std;

class MyTime {
private:
    int hour;
    int min;
    int sec;

public:
    void convert(double duration) {
        int total = (int)duration;

        hour = total / 3600;
        total %= 3600;

        min = total / 60;
        sec = total % 60;
    }

    void print() {
        cout << hour << ":" << min << ":" << sec << endl;
    }

    MyTime add(MyTime t) {
        MyTime result;

        result.sec = sec + t.sec;
        result.min = min + t.min + result.sec / 60;
        result.sec %= 60;

        result.hour = hour + t.hour + result.min / 60;
        result.min %= 60;

        return result;
    }

    void reset() {
        hour = 0;
        min = 0;
        sec = 0;
    }
};

int main() {
    MyTime t1, t2, t3;

    t1.convert(3661);
    t2.convert(59);

    t3 = t1.add(t2);
    t3.print();

    return 0;
}