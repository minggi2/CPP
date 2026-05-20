#include <iostream>
#include <ctime>
#include <cstdlib>
using namespace std;

class Monster {
protected:
    string name, icon;
    int x, y, nItem;

    void clip(int maxx, int maxy) {
        if (x < 0) x = 0;
        if (y < 0) y = 0;
        if (x >= maxx) x = maxx - 1;
        if (y >= maxy) y = maxy - 1;
    }

    void eat(int** map) {
        if (map[y][x] == 1) {
            nItem++;
            map[y][x] = 0;
        }
    }

public:
    Monster(string n = "몬스터", string i = "M",
        int px = 0, int py = 0)
        : name(n), icon(i), x(px), y(py), nItem(0) {
    }

    virtual void move(int** map, int maxx, int maxy) {}

    void print() {
        cout << name << " : ";
        cout << icon << "(" << x << "," << y << ")";
        cout << " 아이템=" << nItem << endl;
    }
};

class Smombi : public Monster {
public:
    Smombi(string n = "스몸비", string i = "S",
        int x = 0, int y = 0)
        : Monster(n, i, x, y) {
    }

    void move(int** map, int maxx, int maxy) {

        int dir = rand() % 4;

        if (dir == 0) {
            x++;
            y++;
        }
        else if (dir == 1) {
            x--;
            y--;
        }
        else if (dir == 2) {
            x++;
            y--;
        }
        else {
            x--;
            y++;
        }

        clip(maxx, maxy);
        eat(map);
    }
};

int main() {

    srand((unsigned)time(NULL));

    const int WIDTH = 10;
    const int HEIGHT = 10;

    int** map = new int* [HEIGHT];

    for (int i = 0; i < HEIGHT; i++) {
        map[i] = new int[WIDTH];

        for (int j = 0; j < WIDTH; j++) {
            map[i][j] = rand() % 2;
        }
    }

    Smombi s("스몸비", "S", 5, 5);

    for (int i = 0; i < 10; i++) {
        s.move(map, WIDTH, HEIGHT);
        s.print();
    }

    return 0;
}