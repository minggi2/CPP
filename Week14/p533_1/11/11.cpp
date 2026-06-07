#include <iostream>
using namespace std;

class TimeHMS {
    int hour, min, sec;

public:
    TimeHMS(int h=0, int m=0, int s=0)
        : hour(h), min(m), sec(s) {}

    TimeHMS operator+(const TimeHMS& t)
    {
        TimeHMS temp;

        temp.sec = sec + t.sec;
        temp.min = min + t.min;
        temp.hour = hour + t.hour;

        temp.min += temp.sec / 60;
        temp.sec %= 60;

        temp.hour += temp.min / 60;
        temp.min %= 60;

        return temp;
    }

    TimeHMS operator-(const TimeHMS& t)
    {
        int total1 = hour*3600 + min*60 + sec;
        int total2 = t.hour*3600 + t.min*60 + t.sec;

        int diff = total1 - total2;

        int h = diff / 3600;
        diff %= 3600;

        int m = diff / 60;
        int s = diff % 60;

        return TimeHMS(h,m,s);
    }

    bool operator==(const TimeHMS& t)
    {
        return hour==t.hour &&
               min==t.min &&
               sec==t.sec;
    }

    bool operator!=(const TimeHMS& t)
    {
        return !(*this == t);
    }

    TimeHMS& operator++()
    {
        hour++;
        return *this;
    }

    TimeHMS operator++(int)
    {
        TimeHMS temp=*this;
        sec++;
        return temp;
    }

    int operator[](int idx)
    {
        if(idx==0) return hour;
        if(idx==1) return min;
        if(idx==2) return sec;
        return -1;
    }

    operator int()
    {
        return hour*3600+min*60+sec;
    }

    operator double()
    {
        return hour +
               min/60.0 +
               sec/3600.0;
    }

    friend TimeHMS operator*(int n,
                             const TimeHMS& t);

    friend ostream& operator<<(ostream& os,
                               const TimeHMS& t);

    friend istream& operator>>(istream& is,
                               TimeHMS& t);
};

TimeHMS operator*(int n,
                  const TimeHMS& t)
{
    int total = n*(t.hour*3600+t.min*60+t.sec);

    int h = total/3600;
    total%=3600;

    int m = total/60;
    int s = total%60;

    return TimeHMS(h,m,s);
}

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
    is >> t.hour
       >> t.min
       >> t.sec;

    return is;
}

int main()
{
    TimeHMS t1(1,20,30);
    TimeHMS t2(4,35,46);
    TimeHMS t3;

    cout << "t1 = " << t1 << endl;
    cout << "t2 = " << t2 << endl;

    t3 = t1 + t2;
    cout << "t1+t2 = " << t3 << endl;

    t3 = t2 - t1;
    cout << "t2-t1 = " << t3 << endl;

    cout << (t1==t2) << endl;
    cout << (t1!=t2) << endl;

    ++t1;
    cout << t1 << endl;

    t1++;
    cout << t1 << endl;

    cout << t1[0] << endl;
    cout << t1[1] << endl;
    cout << t1[2] << endl;

    cout << (int)t1 << endl;
    cout << (double)t1 << endl;

    cout << 2*t1 << endl;

    cin >> t3;

    cout << t3 << endl;

    return 0;
}