#include <iostream>

struct MyTime {
    int hours;
    int minutes;
};

MyTime addTime(MyTime t1, MyTime t2) {
    MyTime sum;
    int total = (t1.hours * 60 + t1.minutes) + (t2.hours * 60 + t2.minutes);
    sum.hours = total / 60;
    sum.minutes = total % 60;
    return sum;
}

int main() {
    MyTime t1 = {1, 40}, t2 = {2, 30};
    MyTime result = addTime(t1, t2);
    std::cout << result.hours << "시간 " << result.minutes << "분" << std::endl;
    return 0;
}