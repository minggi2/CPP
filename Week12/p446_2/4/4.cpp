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

    virtual ~Monster() {}

    virtual void move(int** map, int maxx, int maxy) {
    }

    void print() {
        cout << name << " : ";
        cout << icon << "(" << x << "," << y << ")";
        cout << " 아이템=" << nItem << endl;
    }
};

// 좀비
class Zombie : public Monster {
public:
    Zombie(string n = "좀비", string i = "Z",
        int x = 0, int y = 0)
        : Monster(n, i, x, y) {
    }

    void move(int** map, int maxx, int maxy) {

        int dx = rand() % 3 - 1;
        int dy = rand() % 3 - 1;

        x += dx;
        y += dy;

        clip(maxx, maxy);
        eat(map);
    }
};

// 뱀파이어
class Vampire : public Monster {
public:
    Vampire(string n = "뱀파이어", string i = "V",
        int x = 0, int y = 0)
        : Monster(n, i, x, y) {
    }

    void move(int** map, int maxx, int maxy) {

        int dir = rand() % 4;

        if (dir == 0) x--;
        else if (dir == 1) x++;
        else if (dir == 2) y--;
        else y++;

        clip(maxx, maxy);
        eat(map);
    }
};

// 강시
class Jiangshi : public Monster {
protected:
    bool bHori;

public:
    Jiangshi(string n = "강시", string i = "J",
        int x = 0, int y = 0)
        : Monster(n, i, x, y) {

        bHori = true;
    }

    void move(int** map, int maxx, int maxy) {

        int d = rand() % 2 + 1;

        if (bHori)
            x += d;
        else
            y += d;

        if (rand() % 2 == 0) {
            if (bHori)
                x -= 2 * d;
            else
                y -= 2 * d;
        }

        clip(maxx, maxy);
        eat(map);
    }
};

// 스몸비
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

// 슈퍼 강시
class Siangshi : public Jiangshi {
public:
    Siangshi(string n = "슈퍼강시", string i = "SS",
        int x = 0, int y = 0)
        : Jiangshi(n, i, x, y) {
    }

    void move(int** map, int maxx, int maxy) {

        // 방향 변경
        if (rand() % 3 == 0)
            bHori = !bHori;

        Jiangshi::move(map, maxx, maxy);
    }
};

// 나만의 몬스터
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

    // 맵 생성
    int** map = new int* [HEIGHT];

    for (int i = 0; i < HEIGHT; i++) {

        map[i] = new int[WIDTH];

        for (int j = 0; j < WIDTH; j++) {
            map[i][j] = rand() % 2;
        }
    }

    // 몬스터 객체 생성
    Monster* m[6];

    m[0] = new Zombie("좀비", "Z", 1, 1);
    m[1] = new Vampire("뱀파이어", "V", 2, 2);
    m[2] = new Jiangshi("강시", "J", 3, 3);

    // 추가된 클래스 객체
    m[3] = new Smombi("스몸비", "S", 4, 4);
    m[4] = new Siangshi("슈퍼강시", "SS", 5, 5);
    m[5] = new FastGhost("빠른유령", "F", 6, 6);

    // 이동 테스트
    for (int t = 0; t < 10; t++) {

        cout << "----- " << t + 1 << "번째 이동 -----" << endl;

        for (int i = 0; i < 6; i++) {
            m[i]->move(map, WIDTH, HEIGHT);
            m[i]->print();
        }

        cout << endl;
    }

    // 메모리 해제
    for (int i = 0; i < 6; i++)
        delete m[i];

    for (int i = 0; i < HEIGHT; i++)
        delete[] map[i];

    delete[] map;

    return 0;
}