#include <iostream>
#include <cstdlib>
#include <ctime>

using namespace std;

// 최대 크기 배열 (문제 조건)
static int MineMapMask[40][80];   // 0: 닫힘, 1: 열림, 2: 깃발
static int MineMapLabel[40][80];  // -1: 지뢰, 0~8: 주변 지뢰 개수

int main() {
    int w, h, m;

    srand(time(0)); // 랜덤 초기화

    // 맵 크기 입력
    cout << "가로 세로 입력: ";
    cin >> w >> h;

    // 지뢰 개수 입력
    cout << "지뢰 개수 입력: ";
    cin >> m;

    // 배열 초기화
    for (int i = 0; i < h; i++) {
        for (int j = 0; j < w; j++) {
            MineMapMask[i][j] = 0;
            MineMapLabel[i][j] = 0;
        }
    }

    // 지뢰 랜덤 배치
    int count = 0;
    while (count < m) {
        int r = rand() % h;
        int c = rand() % w;

        if (MineMapLabel[r][c] != -1) { // 이미 지뢰가 아니면
            MineMapLabel[r][c] = -1;
            count++;
        }
    }

    // 각 칸의 숫자 계산 (주변 지뢰 개수)
    for (int i = 0; i < h; i++) {
        for (int j = 0; j < w; j++) {
            if (MineMapLabel[i][j] == -1) continue;

            int cnt = 0;

            for (int di = -1; di <= 1; di++) {
                for (int dj = -1; dj <= 1; dj++) {
                    int ni = i + di;
                    int nj = j + dj;

                    // 배열 범위 체크
                    if (ni >= 0 && ni < h && nj >= 0 && nj < w) {
                        if (MineMapLabel[ni][nj] == -1)
                            cnt++;
                    }
                }
            }

            MineMapLabel[i][j] = cnt;
        }
    }

    // 게임 시작
    while (true) {

        // 맵 출력 (행/열 번호 포함)
        cout << "   ";
        for (int j = 0; j < w; j++) cout << j << " ";
        cout << endl;

        for (int i = 0; i < h; i++) {
            cout << i << " ";
            if (i < 10) cout << " "; 

            for (int j = 0; j < w; j++) {
                if (MineMapMask[i][j] == 0)
                    cout << "# ";   
                else if (MineMapMask[i][j] == 2)
                    cout << "P ";   
                else {
                    if (MineMapLabel[i][j] == -1)
                        cout << "* ";  
                    else
                        cout << MineMapLabel[i][j] << " "; 
                }
            }
            cout << endl;
        }

        // 사용자 입력
        cout << "입력 (예: 10 20 또는 p 10 20): ";
        char ch;
        cin >> ch;

        
        if (ch == 'p') {
            int x, y;
            cin >> x >> y;

            if (MineMapMask[y][x] == 0)
                MineMapMask[y][x] = 2;
            else if (MineMapMask[y][x] == 2)
                MineMapMask[y][x] = 0;
        }
        // 칸 열기
        else {
            int x = ch - '0'; // 첫 숫자 처리
            int y;
            cin >> y;

            // 지뢰면 게임 종료
            if (MineMapLabel[y][x] == -1) {
                cout << "게임 오버\n";
                break;
            }

            MineMapMask[y][x] = 1; 
        }
    }

    return 0;
}