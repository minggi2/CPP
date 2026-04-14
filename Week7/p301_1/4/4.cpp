#include <iostream>
#include <iomanip>
using namespace std;

class MyTime {
private:
    int hour, min, sec;

public:
    void read() {
        cout << "시 입력: ";
        cin >> hour;
        cout << "분 입력: ";
        cin >> min;
        cout << "초 입력: ";
        cin >> sec;
    }

    void print() {
        cout << setfill('0') << setw(2) << hour << ":"
             << setw(2) << min << ":"
             << setw(2) << sec << endl;
    }
};

int main() {
    MyTime t;
    t.read();
    t.print();

    return 0;
}