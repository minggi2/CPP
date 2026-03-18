#include <iostream>

using namespace std;

int main() {
    int n;
    cin >> n;

    if (n / 10000 > 0) {
        cout << n / 10000 << "만 ";
        n %= 10000;
    }

    if (n / 1000 > 0) {
        cout << n / 1000 << "천 ";
        n %= 1000;
    }

    if (n / 100 > 0) {
        cout << n / 100 << "백 ";
        n %= 100;
    }

    if (n / 10 > 0) {
        cout << n / 10 << "십 ";
        n %= 10;
    }

    if (n > 0) {
        cout << n;
    }

    cout << endl;

    return 0;
}