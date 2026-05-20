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

class FastGhost : public Monster {
public:
    FastGhost(string n = "빠른유령", string i = "F",
        int x = 0, int y = 0)
        : Monster(n, i, x, y) {
    }

    void move(int** map, int maxx, int maxy) {

        int dir = rand() % 4;

        if (dir == 0) x += 2;
        else if (dir == 1) x -= 2;
        else if (dir == 2) y += 2;
        else y -= 2;

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

    FastGhost g("빠른유령", "F", 5, 5);

    for (int i = 0; i < 10; i++) {
        g.move(map, WIDTH, HEIGHT);
        g.print();
    }

    return 0;
}