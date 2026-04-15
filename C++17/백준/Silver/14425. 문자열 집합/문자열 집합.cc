#include <iostream>
#include <string>
#include <vector>
#include <algorithm>

using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);

    int n, m, cnt = 0;
    string str;
    vector<string> list;

    cin >> n >> m;
    for (int i = 0; i < n; i++) {
        cin >> str;
        list.push_back(str);
    }
    sort(list.begin(), list.end());

    for (int i = 0; i < m; i++) {
        cin >> str;
        if (binary_search(list.begin(), list.end(), str)) {
            cnt++;
        }
    }
    cout << cnt;
    return 0;
}