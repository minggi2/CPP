#include <iostream>
using namespace std;

class TimeHMS {
    int hour, min, sec;

public:
    TimeHMS(int h=0, int m=0, int s=0)
        : hour(h), min(m), sec(s) {}

    friend ostream& operator<<(ostream& os,
                               const TimeHMS& t);

    friend istream& operator>>(istream& is,
                               TimeHMS& t);
};

ostream& operator<<(ostream& os,
                    const TimeHMS& t)
{
    os << t.hour << "시 "
       << t.min << "분 "
       << t.sec << "초";

    return os;
}

istream& operator>>(istream& is,
                    TimeHMS& t)
{
    cout << "시 분 초 입력 : ";
    is >> t.hour
       >> t.min
       >> t.sec;

    return is;
}

int main()
{
    TimeHMS t1;

    cin >> t1;

    cout << t1 << endl;

    return 0;
}