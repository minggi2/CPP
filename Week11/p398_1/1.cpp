#include <iostream>
using namespace std;

class Sample {
    char* name;
    static int count;

public:
    Sample() {
        count++;
    }

    static void printCount() {
        cout << "객체 수 : " << count << endl;
    }
};

int Sample::count = 0;

int main() {

    Sample a;
    Sample b;

    Sample::printCount();

    return 0;
}