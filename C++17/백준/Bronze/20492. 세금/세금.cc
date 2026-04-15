#include <iostream>

using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    int price;

    cin >> price;

    cout << (int)(price * 0.78) << " " << (int)(price * 0.8 + (price * 0.2) * 0.78);
}