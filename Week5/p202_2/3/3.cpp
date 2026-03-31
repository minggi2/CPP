#include <iostream>

using namespace std;

void checkMap(int map[5][5]);

int main() {
    int map[5][5] = {
        {1,1,1,1,1},
        {0,1,0,1,0},
        {1,0,1,0,1},
        {0,1,0,1,0},
        {1,1,1,1,1}
    };

    checkMap(map);

    return 0;
}

void checkMap(int map[5][5]) {
    for (int i = 0; i < 5; i++) {
        for (int j = 0; j < 5; j++) {
            cout << map[i][j] << " ";
        }
        cout << endl;
    }
    cout << endl;

    for (int i = 0; i < 5; i++) {
        bool same = true;
        for (int j = 1; j < 5; j++) {
            if (map[i][j] != map[i][0]) {
                same = false;
                break;
            }
        }
        if (same)
            cout << "가로 " << i << " 동일 (" << map[i][0] << ")" << endl;
    }

    for (int j = 0; j < 5; j++) {
        bool same = true;
        for (int i = 1; i < 5; i++) {
            if (map[i][j] != map[0][j]) {
                same = false;
                break;
            }
        }
        if (same)
            cout << "세로 " << j << " 동일 (" << map[0][j] << ")" << endl;
    }

    bool same = true;
    for (int i = 1; i < 5; i++) {
        if (map[i][i] != map[0][0]) {
            same = false;
            break;
        }
    }
    if (same)
        cout << "주 대각선 동일 (" << map[0][0] << ")" << endl;

    same = true;
    for (int i = 1; i < 5; i++) {
        if (map[i][4 - i] != map[0][4]) {
            same = false;
            break;
        }
    }
    if (same)
        cout << "부 대각선 동일 (" << map[0][4] << ")" << endl;
}