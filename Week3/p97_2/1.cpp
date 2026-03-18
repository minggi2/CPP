#include <iostream>

using namespace std;

int main() {
    int num;
    cin >> num;

    int man   = (num / 10000) % 10;
    int cheon = (num / 1000) % 10;
    int baek  = (num / 100) % 10;
    int sip   = (num / 10) % 10;
    int il    = num % 10;

    cout << man << "만 " << cheon << "천 " << baek << "백 " << sip << "십 " << il << endl;

    return 0;
}