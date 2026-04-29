#pragma once
#include "Canvas.h"
#include <iostream>
#include <string>

using namespace std;

class Monster 
{
    string name, icon;
    int x, y, nItem;
    int nEnergy; // (1) 몬스터의 체력(에너지)을 저장하는 변수

public:
    // (2) 생성자: 처음 만들 때 에너지를 100으로 설정
    Monster(string n = "나괴물", string i = "*", int px = 0, int py = 0)
        : name(n), icon(i), x(px), y(py), nItem(0), nEnergy(100) {}

    ~Monster() { cout << "\t" << name << icon << " 물러갑니다~~~" << endl; }

    void clip(int maxx, int maxy) {
        // 맵 밖으로 나가지 않도록 위치를 제한
        if (x < 0) x = 0;
        if (x >= maxx) x = maxx - 1;
        if (y < 0) y = 0;
        if (y >= maxy) y = maxy - 1;
    }

    // (3) 먹기 기능
    void eat(int map[40][40])
    {
        if (map[y][x] == 1) {
            // 아이템이 있으면 먹고 에너지 증가
            map[y][x] = 0;
            nItem++;
            nEnergy += 8;
        } else {
            // 아이템이 없으면 에너지 감소
            nEnergy -= 1;
            if (nEnergy < 0) nEnergy = 0; // 에너지는 0 밑으로 안 내려감
        }
    }

    void draw(Canvas &canvas) { canvas.draw(x, y, icon); }

    void move(int map[40][40], int maxx, int maxy)
    {
        // 8방향 중 하나로 랜덤 이동
        switch (rand() % 8) {
            case 0: y--; break;
            case 1: x++; y--; break;
            case 2: x++; break;
            case 3: x++; y++; break;
            case 4: y++; break;
            case 5: x--; y++; break;
            case 6: x--; break;
            case 7: x--; y--; break;
        }
        clip(maxx, maxy); // 맵 범위 체크
        eat(map);         // 이동 후 먹기 시도
    }

    // (4) 현재 상태 출력
    void print()
    { 
        cout << "\t" << name << icon << " E:" << nEnergy << endl; 
    }
};