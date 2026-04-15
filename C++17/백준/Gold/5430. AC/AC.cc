#include <iostream>
#include <deque>
#include <string>

using namespace std;

int tc;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);

    /*
        R, D만 쓴다. 내가 들었던 생각은... 
        뒤집기인 R은 배열이든 큐를 하나 만들어서 넣고, 스택에다가 넣고 스택에서 다시 빼서 넣는 역할을 하면 되긴함
        그래서 처음에 queue에 넣고, [~,~,~] 이런식의 형식으로 준대. 그러면 넌 어떻게 할꺼야? split? 아니면 그냥 숫자일 때만 
        아니면 deque이나 vector를 써서, R이 몇번 나왔는지 체크해서 그냥 앞을 ㄷ빼든 뒤를 빼든 해주는 게 나아보이는데?
    */
   
    cin >> tc;

    for (int i = 0; i < tc; i++) {
        string order, arr, str = "";
        int arrSize, cntR = 0, isValid = 1;
        cin >> order >> arrSize >> arr;

        deque<int> arrV;
        
        for (char c : arr) {
            if (c >= '0' && c <= '9') {
                str += c;
            }
            else {
                if (str != "") {
                    arrV.push_back(stoi(str));
                    str = "";
                }
            }
        }

        // cntR 홀수면 뒤에꺼 빼고 짝수면 앞에꺼 빼
        for (char c : order) {
            if (c == 'R') {
                cntR++;
            }
            else if (c == 'D') {
                if (arrV.empty()) {
                    cout << "error" << '\n';
                    isValid = 0;
                    break;
                }
                
                if (cntR % 2 == 1) {
                    arrV.pop_back();
                }
                else {
                    arrV.pop_front();
                }
            }
        }

        if (isValid) {
            string ansArr = "[";
            // cntR이 이제 홀 짝에 따라 달라지지. 뒤에서부터 읽을 것이냐 앞에서부터 읽을것이냐.
            if (cntR % 2 == 1) {

                while (!arrV.empty()) {
                    int cur = arrV.back();
                    if (arrV.size() > 1) {
                        ansArr += to_string(cur) + ",";
                    }
                    else {
                        ansArr += to_string(cur);
                    }
                    arrV.pop_back();
                }
                ansArr += "]";
            }
            else {

                while (!arrV.empty()) {
                    int cur = arrV.front();
                    if (arrV.size() > 1) {
                        ansArr += to_string(cur) + ",";
                    }
                    else {
                        ansArr += to_string(cur);
                    }
                    arrV.pop_front();
                }
                ansArr += "]";
            }
            cout << ansArr << '\n';
        }
    }

    return 0;
}