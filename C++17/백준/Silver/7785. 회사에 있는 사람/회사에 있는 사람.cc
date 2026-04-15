#include <iostream>
#include <set>
#include <algorithm>
#include <string>

using namespace std;
int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int n; cin >> n;
    set<string> cur; // 기본 오름차순
    for (int i = 0; i < n; ++i) {
        string name, cmd; cin >> name >> cmd;
        if (cmd == "enter") cur.insert(name);
        else cur.erase(name);
    }
    for (auto it = cur.rbegin(); it != cur.rend(); ++it)
        cout << *it << '\n';
}
