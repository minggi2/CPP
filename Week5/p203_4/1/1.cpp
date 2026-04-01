#include <iostream>
#include <cstdlib>
#include <ctime>
#include <cstdio> 

using namespace std;

#define MAX 5

// 게임 데이터를 저장할 구조체
struct GameData {
    int size;               
    char board[MAX][MAX];   
    char startMap[MAX][MAX]; 
    int x, y;               
    int moveCount;          
    time_t startTime;       
    char history[1000];     
    int hIdx;
};

// 랭킹 정보를 담을 구조체
struct Rank {
    int moves;
    double playTime;
};

// (1) 크기 확장 및 (5) 문자 퍼즐 초기화
void init(GameData &g, int n) {
    g.size = n;
    g.moveCount = 0;
    g.hIdx = 0;
    g.startTime = time(NULL);
    char alpha = 'A';

    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            if (i == n - 1 && j == n - 1) g.board[i][j] = ' ';
            else g.board[i][j] = alpha++;
        }
    }
    g.x = n - 1; g.y = n - 1;
}

void print(GameData &g) {
    cout << "\n[Move: " << g.moveCount << "]\n";
    for (int i = 0; i < g.size; i++) {
        for (int j = 0; j < g.size; j++) cout << g.board[i][j] << " ";
        cout << "\n";
    }
}

void move(GameData &g, char d, bool record = true) {
    int nx = g.x, ny = g.y;
    if (d == 'w') nx--; if (d == 's') nx++;
    if (d == 'a') ny--; if (d == 'd') ny++;

    if (nx >= 0 && nx < g.size && ny >= 0 && ny < g.size) {
        g.board[g.x][g.y] = g.board[nx][ny];
        g.board[nx][ny] = ' ';
        g.x = nx; g.y = ny;
        if (record) {
            g.history[g.hIdx++] = d; // (2) 움직임 저장
            g.moveCount++;
        }
    }
}

// (3) 게임 저장 - 4.7절의 이진 모드 활용
void saveGame(GameData &g) {
    FILE* fp = fopen("game.dat", "wb");
    if (fp) {
        fwrite(&g, sizeof(GameData), 1, fp); 
        fclose(fp);
        cout << "게임이 이진 파일로 저장되었습니다.\n";
    }
}

// (4) 이어하기 - 4.7절의 이진 모드 활용
int loadGame(GameData &g) {
    FILE* fp = fopen("game.dat", "rb"); 
    if (!fp) return 0;
    fread(&g, sizeof(GameData), 1, fp);
    fclose(fp);
    return 1;
}

// (2) 리플레이 기능
void replay(GameData g) {
    cout << "\n--- 리플레이를 시작합니다 ---\n";
    for(int i=0; i<g.size; i++) 
        for(int j=0; j<g.size; j++) g.board[i][j] = g.startMap[i][j];
    
    for (int i = 0; i < g.hIdx; i++) {
        print(g);
        move(g, g.history[i], false);
    }
    print(g);
}

// (6) 랭킹 저장 - 이진 모드 활용
void saveRank(int m, time_t start) {
    Rank r = { m, difftime(time(NULL), start) };
    FILE* fp = fopen("rank.dat", "ab"); 
    if (fp) {
        fwrite(&r, sizeof(Rank), 1, fp);
        fclose(fp);
    }
}

int main() {
    GameData g;
    srand(time(0));

    int m;
    cout << "1. 새게임  2. 이어하기(4): "; cin >> m;

    if (m == 2 && loadGame(g)) {
        cout << "저장된 시각: " << ctime(&g.startTime);
    } else {
        int s; cout << "크기(3/5): "; cin >> s;
        init(g, s);
        for (int i = 0; i < 50; i++) move(g, "wasd"[rand() % 4], false);
        // (2) 섞인 직후 초기 상태 보관
        for(int i=0; i<s; i++) 
            for(int j=0; j<s; j++) g.startMap[i][j] = g.board[i][j];
    }

    while (1) {
        print(g);
        char c; cout << "w/a/s/d (r:저장종료, q:그냥종료): "; cin >> c;
        if (c == 'q') break;
        if (c == 'r') { saveGame(g); break; }
        move(g, c);

        // 승리 판정 (생략 가능)
        if (g.moveCount > 0 && g.board[g.size-1][g.size-1] == ' ') {
            cout << "성공!\n";
            saveRank(g.moveCount, g.startTime); // (6) 랭킹 저장
            replay(g); // (2) 리플레이
            break;
        }
    }
    return 0;
}