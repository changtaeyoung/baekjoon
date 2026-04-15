#include <iostream>
#include <algorithm>
#include <vector>

using namespace std;

int main(void) {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int n, m, num1, num2, left, right, mid;
    vector<int> has;

    cin >> n;
    for(int i = 0; i < n; i++) {
        cin >> num1;
        has.push_back(num1);
    }
    sort(has.begin(), has.end());

    cin >> m;
    for (int i = 0; i < m; i++) {
        cin >> num2;

        int res = 0;
        left = 0;
        right = has.size() - 1;

        while (left <= right) {
            mid = (left + right) / 2;
            
            if (num2 < has[mid]) {
                right = mid - 1;
            }
            else if (num2 > has[mid]) {
                left = mid + 1;
            }
            else if (num2 == has[mid]) {
                res = 1;
                break;
            }
        }
        cout << res << " ";
    }
    return 0;
}