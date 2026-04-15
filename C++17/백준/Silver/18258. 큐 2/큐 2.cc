#include <iostream>
#include <queue>
#include <algorithm>
#include <string>

using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    
    int num, order_num = 0;
    string str, order;
    queue<int> q;

    cin >> num;
    cin.ignore();

    for (int i = 0; i < num; i++) {
        getline(cin, str);

        int idx = str.find(" ");

        if (idx != string::npos) { 
            order_num = stoi(str.substr(idx));
            str = str.substr(0, idx);
        }

        if (str == "push") {
            q.push(order_num);
        }
        else if (str == "pop") {
            if (q.empty()) {
                cout << -1 << '\n';
            }
            else {
                cout << q.front() << '\n';
                q.pop();
            }
        }
        else if (str == "size") {
            cout << q.size() << '\n';
        }
        else if (str == "empty") {
            if (q.empty()) {
                cout << 1 << '\n';
            }
            else {
                cout << 0 << '\n';
            }
        }
        else if (str == "front") {
            if (q.empty()) {
                cout << -1 << '\n';
            }
            else {
                cout << q.front() << '\n';
            }
        }
        else if (str == "back") {
            if (q.empty()) {
                cout << -1 << '\n';
            }
            else {
                cout << q.back() << '\n';
            }
        }
    }
    return 0;
}