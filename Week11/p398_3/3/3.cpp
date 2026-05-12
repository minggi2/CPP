#include <iostream>
#include <string>
using namespace std;

class Monster {
    string name;
    int nEnergy;

public:
    Monster(string n = "도깨비")
    {
        name = n;
        nEnergy = 3;
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
             << " 에너지 : "
             << nEnergy << endl;
    }
};

class MonsterWorld {
    Monster* pMon[10];
    int nMon;

public:
    MonsterWorld()
    {
        nMon = 0;
    }

    void add(Monster* m)
    {
        pMon[nMon++] = m;
    }

    void moveAll()
    {
        for (int i = 0; i < nMon; i++)
            pMon[i]->move();
    }

    void checkStarvation()
    {
        for (int i = 0; i < nMon; i++)
        {
            if (pMon[i]->getEnergy() <= 0)
            {
                delete pMon[i];

                pMon[i] = pMon[nMon - 1];
                nMon--;

                i--;
            }
        }
    }

    void print()
    {
        for (int i = 0; i < nMon; i++)
            pMon[i]->print();

        cout << "현재 몬스터 수 : "
             << nMon << endl;
    }
};

int main()
{
    MonsterWorld game;

    game.add(new Monster("도깨비"));
    game.add(new Monster("고스트"));

    for (int i = 0; i < 5; i++)
    {
        game.moveAll();
        game.checkStarvation();
        game.print();

        cout << endl;
    }

    return 0;
}