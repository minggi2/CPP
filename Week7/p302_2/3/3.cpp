#include <iostream> 
#include <string>   
using namespace std;

// 영어 단어와 한국어 뜻을 한 쌍으로 묶기 위한 구조체
struct WordPair {
    string eng; 
    string kor; 
};

// 사전 기능을 담당하는 클래스
class MyDic {
    WordPair words[100]; 
    int nWords;          

public:
    // 생성자: 객체가 생성될 때 단어 개수를 0으로 초기화
    MyDic() { 
        nWords = 0; 
    }

    // 사전에 새로운 단어 쌍을 추가하는 함수
    void add(string eng, string kor) {
        words[nWords].eng = eng; 
        words[nWords].kor = kor; 
        nWords++;               
    }

    // 저장된 모든 단어 목록을 출력하는 함수
    void print() {
        for (int i = 0; i < nWords; i++) {
            cout << words[i].eng << " - " << words[i].kor << endl;
        }
    }

    // 특정 인덱스(id)에 해당하는 영어 단어를 반환하는 함수
    string getEng(int id) {
        return words[id].eng;
    }

    // 특정 인덱스(id)에 해당하는 한국어 뜻을 반환하는 함수
    string getKor(int id) {
        return words[id].kor;
    }
};

int main() {
    MyDic dic; // MyDic 클래스의 인스턴스(객체) 생성

    
    dic.add("apple", "사과");

    dic.print();
    
    cout << dic.getEng(0) << endl;

    return 0;
}