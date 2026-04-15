#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);

    int n, m, num, cnt = 0;
    vector<int> vec;
    cin >> n >> m;

    for (int i = 0; i < n; i++) { 
        cin >> num;
        vec.push_back(num);
    }
    
    sort(vec.begin(), vec.end());  // 오름차순 정렬
    int left = 0, right = n - 1;

    while (left < right) {
        int sum = vec[left] + vec[right];
        if (sum == m) {
            cnt++;
            left++;
            right--;
        } else if (sum < m) {
            left++;
        } else {
            right--;
        }
    }

    cout << cnt;
    return 0;
}