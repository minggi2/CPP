#include "5.hpp"
#include <iomanip>
#include <iostream>

void MyTime::convert(double duration) {
    int total = (int)duration;

    hour = total / 3600;
    total %= 3600;

    min = total / 60;
    sec = total % 60;
}

void MyTime::print() {
    cout << setfill('0') << setw(2) << hour << ":"
         << setw(2) << min << ":"
         << setw(2) << sec << endl;
}

MyTime MyTime::add(MyTime t) {
    MyTime result;

    result.sec = sec + t.sec;
    result.min = min + t.min + result.sec / 60;
    result.sec %= 60;

    result.hour = hour + t.hour + result.min / 60;
    result.min %= 60;

    return result;
}

void MyTime::reset() {
    hour = 0;
    min = 0;
    sec = 0;
}

void MyTime::read() {
    cout << "시 입력: ";
    cin >> hour;
    cout << "분 입력: ";
    cin >> min;
    cout << "초 입력: ";
    cin >> sec;
}
