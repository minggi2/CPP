#include <iostream>
#include <string>
using namespace std;

#define MAXWORDS 100  // 최대 단어 개수

// 단어 쌍 구조체 
struct WordPair {
    string eng;
    string kor;
};

// 단어장 클래스
class MyDic {
    WordPair words[MAXWORDS]; // 단어 배열
    int nWords;               // 현재 단어 수

public:
    // 생성자: 단어 수 0으로 초기화
    MyDic() {
        nWords = 0;
    }

    // 단어 추가
    void add(string eng, string kor) {
        if (nWords < MAXWORDS) {
            words[nWords].eng = eng;
            words[nWords].kor = kor;
            nWords++;
        }
    }

    // (미구현) 파일 읽기
    void load(string filename) {
        cout << "파일 기능 미구현" << endl;
    }

    // (미구현) 파일 저장
    void store(string filename) {
        cout << "파일 기능 미구현" << endl;
    }

    // 전체 출력
    void print() {
        for (int i = 0; i < nWords; i++) {
            cout << i << ": "
                 << words[i].eng << " - "
                 << words[i].kor << endl;
        }
    }

    // 영어 반환
    string getEng(int id) {
        if (id >= 0 && id < nWords)
            return words[id].eng;
        return "";
    }

    // 한글 반환
    string getKor(int id) {
        if (id >= 0 && id < nWords)
            return words[id].kor;
        return "";
    }
};
