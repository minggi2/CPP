#include <iostream>
#include <string>
using namespace std;

class Monster {
    string name;
    int nEnergy;

    static int count;

public:
    Monster(string n = "도깨비")
    {
        name = n;
        nEnergy = 100;

        count++;
    }

    ~Monster()
    {
        count--;
    }

    void move()
    {
        nEnergy--;
    }

    int getEnergy()
    {
        return nEnergy;
    }

    void print()
    {
        cout << name
             << " E:" << nEnergy << endl;
    }

    static void printCount()
    {
        cout << "전체 몬스터 수 : "
             << count << endl;
    }
};

int Monster::count = 0;

int main()
{
    Monster* m1 = new Monster("도깨비");
    Monster* m2 = new Monster("고스트");

    Monster::printCount();

    delete m1;

    Monster::printCount();

    delete m2;

    Monster::printCount();

    return 0;
}