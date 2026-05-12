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
        nEnergy = 5;

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

                cout << "Monster 하나가 굶어죽습니다" << endl;

                i--;
            }
        }
    }

    void print()
    {
        for (int i = 0; i < nMon; i++)
            pMon[i]->print();

        Monster::printCount();

        cout << endl;
    }
};

int main()
{
    MonsterWorld game;

    game.add(new Monster("도깨비"));
    game.add(new Monster("고스트"));
    game.add(new Monster("아수라"));

    for (int i = 0; i < 7; i++)
    {
        game.moveAll();
        game.checkStarvation();
        game.print();
    }

    return 0;
}