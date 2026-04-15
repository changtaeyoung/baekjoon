#include <iostream>
#include <string>
#include <cctype>

using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);

    int test;
    string str;

    cin >> test;
    cin.ignore();

    for (int i = 0; i < test; i++) {
        getline(cin, str);
        bool flag = true;

        for (int j = 0; j < str.length(); j++) {
            str[j] = tolower(str[j]);
        }

        for (int j = 0; j < str.length() / 2; j++) {
            if (str[j] != str[str.length() - 1 - j]) {
                flag = false;
                break;
            }
        }
        if (flag) {
            cout << "Yes" << '\n';
        }
        else {
            cout << "No" << '\n';
        }
    }
    return 0;
}