#include <iostream>
#include <string>

using namespace std;

string cAlpha[8] = { "c=", "c-", "dz=", "d-", "lj", "nj", "s=", "z=" };

int main(void) {
    string term;
    cin >> term;
    int cnt = 0;

    for (int i = 0; i < term.length(); i++) {
        bool isCroatian = false;
        for (int j = 0; j < 8; j++) {
            if (term.substr(i, cAlpha[j].length()) == cAlpha[j]) {
                cnt++;
                i += cAlpha[j].length() - 1; // 해당 크로아티아 알파벳을 건너뜀
                isCroatian = true;
                break;
            }
        }
        if (!isCroatian) {
            cnt++;
        }
    }

    cout << cnt;
    return 0;
}
