#include <iostream>
#include <string>
#include <map>
#include <algorithm>

using namespace std;

int main() {
    int books, max = 0;
    string str, res;
    map<string, int> sold;

    cin >> books;

    for (int i = 0; i < books; i++) {
        cin >> str;
        sold[str]++;
    }

    for (auto cur : sold) {
        if (cur.second > max) {
            max = cur.second;
            res = cur.first;
        }
    }
    cout << res;
    return 0;
}