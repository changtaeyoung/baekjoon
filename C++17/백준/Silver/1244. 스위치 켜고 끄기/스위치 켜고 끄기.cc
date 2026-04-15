#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);

    int switches, students, state, gender, place;
    vector<int> swit;

    cin >> switches;

    for (int i = 0; i < switches; i++) {
        cin >> state;
        swit.push_back(state);
    }

    cin >> students;

    for (int i = 0; i < students; i++) {
        cin >> gender >> place;
        if (gender == 1) {
            for (int j = 1; ; j++) {
                if (place * j <= swit.size()) {
                    swit[place * j - 1] = 1 - swit[place * j - 1];
                }
                else {
                    break;
                }
            }
        }
        else if (gender == 2) {
            swit[place - 1] = 1 - swit[place - 1];
            for (int j = 1; ; j++) {
                
                if (place - 1 - j < 0 || place - 1 + j >= swit.size()) { // 배열 초과 시 break;
                    break;
                }
                else if (swit[place - j - 1] == swit[place + j - 1]) {
                    swit[place - j - 1] = 1 - swit[place - j - 1];
                    swit[place + j - 1] = 1 - swit[place + j - 1];
                }
                else { // 값이 다를 때
                    break;
                }
            }
        }
    }

    for (int i = 0; i < swit.size(); i++) {
        cout << swit[i] << " ";
        if ((i + 1) % 20 == 0) {
            cout << '\n';
        }
    }

    return 0;
}