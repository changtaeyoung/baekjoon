#include <iostream>
#include <algorithm>
#include <string>
#include <vector>

using namespace std;

int main(void) {
    string str;
    vector<int> vec(10, 0);
    int cnt = 0, cnt_sn = 0;

    cin >> str;

    for (char c : str) {
        vec[c - '0']++;
    }
    cnt_sn = (vec[6] + vec[9] + 1) / 2;
    vec[6] = cnt_sn;
    vec[9] = cnt_sn;

    cnt = *max_element(vec.begin(), vec.end());
    cout << cnt;
    return 0;
}