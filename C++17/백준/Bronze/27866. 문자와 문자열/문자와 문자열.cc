#include <iostream>
#include <string>

using namespace std;

int main() {
    string str;
    int num;
    char c;

    cin >> str;
    cin >> num;

    for (int i = 0; i < str.size(); i++) {
        if (i == num - 1) {
            c = str[i];
        }
    }
    cout << c << endl;
    return 0;
}