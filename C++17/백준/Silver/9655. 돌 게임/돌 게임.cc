#include <iostream>

using namespace std;

int main() {
    int num;
    cin >> num;
    
    if (num % 2 == 1) {
        cout << "SK" << '\n';
    }
    else if (num % 2 == 0) {
        cout << "CY" << '\n';
    }
}