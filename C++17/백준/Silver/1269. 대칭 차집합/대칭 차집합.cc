#include <iostream>
#include <set>
#include <algorithm>

using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);

    int a, b, num;
    set<int> aset, bset, total;

    cin >> a >> b;

    for (int i = 0; i < a; i ++) {
        cin >> num;
        aset.insert(num);
    }

    for (int i = 0; i < b; i++) {
        cin >> num;
        bset.insert(num);
    }
    
    set_difference(aset.begin(), aset.end(), bset.begin(), bset.end(), inserter(total, total.begin()));
    set_difference(bset.begin(), bset.end(), aset.begin(), aset.end(), inserter(total, total.begin()));

    cout << total.size();
    return 0;
}