#include <iostream>
#include <vector>
using namespace std;

int main() {
    int n, m;
    vector<int> vec(n);
    
    cin >> n >> m;
    for (int i = 0; i < n; i++) {
        cin >> vec[i];
    }
    
    int cnt = 0, left = 0, sum = 0;
    
    for (int right = 0; right < n; right++) {
        sum += vec[right];
        
        while (sum > m) {
            sum -= vec[left++];
        }
        
        if (sum == m) {
            cnt++;
        }
    }
    
    cout << cnt << endl;
    return 0;
}