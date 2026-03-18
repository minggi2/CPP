#include <iostream>

using namespace std;

int main() {
    int n;
    cin >> n;

    if (n / 10000 > 1) cout << n / 10000;
    if (n / 10000 > 0) {
        cout << "만 ";
        n %= 10000;
    }

    if (n / 1000 > 1) cout << n / 1000;
    if (n / 1000 > 0) {
        cout << "천 ";
        n %= 1000;
    }

    if (n / 100 > 1) cout << n / 100;
    if (n / 100 > 0) {
        cout << "백 ";
        n %= 100;
    }

    if (n / 10 > 1) cout << n / 10;
    if (n / 10 > 0) {
        cout << "십 ";
        n %= 10;
    }

    if (n > 0) cout << n;

    cout << endl;

    return 0;
}