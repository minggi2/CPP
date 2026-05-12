#include <iostream>
#include <string>
using namespace std;

class Monster {
    string name;
    string icon;
    int x, y;
    int nItem;
    int nEnergy;

public:
    Monster(string n = "도깨비", string i = "§", int px = 0, int py = 0)
    {
        name = n;
        icon = i;
        x = px;
        y = py;
        nItem = 0;
        nEnergy = 100;
    }

    void move()
    {
        nEnergy--;
    }

    void eat(int food)
    {
        nEnergy += food;
        nItem++;
    }

    int getEnergy()
    {
        return nEnergy;
    }

    void print()
    {
        cout << name
             << " 에너지 : "
             << nEnergy << endl;
    }
};

int main()
{
    Monster m;

    m.move();
    m.move();

    cout << "현재 에너지 : "
         << m.getEnergy() << endl;

    return 0;
}