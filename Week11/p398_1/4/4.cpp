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

    Sample(const Sample& s) {

        name = new char[strlen(s.name) + 1];

        strcpy(name, s.name);
    }

    void show() {
        cout << name << endl;
    }
};

int main() {

    Sample a("sample");

    Sample b(a);

    b.show();

    return 0;
}