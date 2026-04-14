#include <iostream>
using namespace std;

class MyTime {
private:
    int hour;
    int min;
    int sec;
    int msec;

public:
    void convert(double duration);
    void print();
    MyTime add(MyTime t);
    void resert();
    void read();

};
    