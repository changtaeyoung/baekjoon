#include <iostream>
#include <string>
#include <vector>
#include <algorithm>

using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);

    string str;
    vector<string> vec;

    cin >> str;
    int len = str.length(); 

    for (int i = 0; i < len; i++) { 
        vec.push_back(str.substr(i, len - i));
    }

    sort(vec.begin(), vec.end());

    for (int i = 0; i < vec.size(); i++) {
        cout << vec[i] << '\n';
    }
    return 0;
}
