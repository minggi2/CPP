#include <iostream>
#include <cstring>
using namespace std;

class Sample {
    char* name;

public:
    Sample(const char* name) {

        this->name = new char[strlen(name) + 1];

        strcpy(this->name, name);
    }

    ~Sample() {

        delete[] name;

        cout << "메모리 해제 완료" << endl;
    }

    void show() {
        cout << name << endl;
    }
};

int main() {

    Sample a("sample");

    a.show();

    return 0;
}