#include <iostream>
#include <string>
#include <vector>

using namespace std;

int main() {
    string str;
    vector<string> strArr;

    while (getline(cin, str)) {
        strArr.push_back(str);
    }

    for (int i = 0; i < strArr.size(); i++) {
        while (strArr[i].find("BUG") != string::npos) {
            auto idx = strArr[i].find("BUG");
            strArr[i].erase(idx, 3);
        }

        cout << strArr[i] << '\n';
    }

    return 0;
}