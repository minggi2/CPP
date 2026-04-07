#include <iostream>

struct MyTime {
    int hours;
    int minutes;
};

void addTime(MyTime t1, MyTime t2, MyTime* pt) {
    if (pt != nullptr) {
        int total = (t1.hours * 60 + t1.minutes) + (t2.hours * 60 + t2.minutes);
        pt->hours = total / 60;
        pt->minutes = total % 60;
    }
}

int main() {
    MyTime t1 = {1, 40}, t2 = {2, 30}, result;
    addTime(t1, t2, &result);
    std::cout << result.hours << "시간 " << result.minutes << "분" << std::endl;
    return 0;
}