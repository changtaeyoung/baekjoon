#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int main() {
    int n, cnt = 1;
    vector<pair<int, int>> vec;
    cin >> n;

    for (int i = 0; i < n; i++) {
        int start, end;
        cin >> start >> end;
        vec.push_back({end, start});
    }

    sort(vec.begin(), vec.end());

    int end_time = vec[0].first;

    for (int i = 0; i < vec.size() - 1; i++) {
        if(vec[i + 1].second >= end_time) {
            cnt++;
            end_time = vec[i + 1].first;
        }
    }

    cout << cnt << '\n';
}