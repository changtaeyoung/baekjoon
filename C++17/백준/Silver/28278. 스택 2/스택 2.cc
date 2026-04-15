#include <iostream>
#include <string>
#include <stack>

using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);

    string str;
    int test, val;
    stack<int> st;

    cin >> test;
    cin.ignore();

    for (int i = 0; i < test; i++) {
        getline(cin, str);

        auto idx = str.find(" ");
        if (idx != string::npos) {
            val = stoi(str.substr(idx + 1));
            str = str.substr(0, idx);
        }

        if (str == "1") {
            st.push(val);
        }
        else if (str == "2") {
            if (st.empty()) {
                cout << -1 << '\n';
            }
            else {
                cout << st.top() << '\n';
                st.pop();
            }
        }
        else if (str == "3") {
            cout << st.size() << '\n';
        }
        else if (str == "4") {
            if (st.empty()) {
                cout << 1 << '\n';
            }
            else {
                cout << 0 << '\n';
            }
        }
        else if (str == "5") {
            if (st.empty()) {
                cout << -1 << '\n';
            }
            else {
                cout << st.top() << '\n';
            }
        }
    }

    return 0;
}