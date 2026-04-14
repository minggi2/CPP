#include <iostream>
#include <iomanip>
using namespace std;

class MyTime {
private:
    int hour, min, sec;

public:
    void convert(double duration) {
        int total = (int)duration;
        hour = total / 3600;
        total %= 3600;
        min = total / 60;
        sec = total % 60;
    }

    void print() {
        cout << setfill('0') << setw(2) << hour << ":"
             << setw(2) << min << ":"
             << setw(2) << sec << endl;
    }
};

int main() {
    MyTime t;
    t.convert(3661);
    t.print();

    return 0;
}
