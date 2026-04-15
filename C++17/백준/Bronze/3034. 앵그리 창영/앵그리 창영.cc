#include <iostream>
#include <cmath>

using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);

    int n, w, h, len, min, max;
    
    cin >> n >> w >> h;

    min = (w < h) ? w : h;
    max = (w > h) ? w : h;

    for (int i = 0; i < n; i++) {
        cin >> len;
        if (len < min) {
            cout << "DA" << '\n';
        }
        else if (len > max) {
            double dir = sqrt(min * min + max * max);
            if ((double)len <= dir) {
                cout << "DA" << '\n';
            }
            else {
                cout << "NE" << '\n';
            }
        }
        else if (len >= min && len <= max) {
            cout << "DA" << '\n';
        }
    }
    return 0;
}