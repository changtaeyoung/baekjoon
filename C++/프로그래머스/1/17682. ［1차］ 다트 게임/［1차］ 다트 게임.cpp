#include <string>
#include <cmath>
#include <vector>
#include <iostream>

using namespace std;

/*
    S, D, T -> 1, 2, 3제곱
    * -> 해당 점수, 바로 전에 얻은 점수 각 2배 
    (처음에서도 나옴, 첫번째 점수만 2배)
    다른 *과 효과 중첨 가능 (점수 4배)
    # -> 해당 점수 -
    *효과는 #와 중첩되면 -2배
    *, #는 점수마다 하나만 존재. (점수마다 S,D,T 하나씩 존재)
    
    1번 예시
    -> (1^1 + 2^2) * 2 + 3^3
    4번 예씨
    -> ((1^1*2) + 2^3) * 2 + 3
*/

int solution(string dartResult) {
    int answer = 0;
    
    vector<int> arr;
    string num = "";
    bool isMinus = false;
    int number = 0;
    for (int i = 0; i < dartResult.length(); i++) {
        bool isNum = false;
        
        // 여기서 숫자 판별해야하는데, 10일 경우 뒤에 거를 하나 더 추가해야하니까 continue 해줘야함
        // 아니 여기서 근데 숫자는 어차피 length -2까지 밖에 안나옴. 마지막은 S 또는 # 이런 문자들이니까
        if (dartResult[i] >= '0' && dartResult[i] <= '9') {
            if (dartResult[i + 1] >= '0' && dartResult[i + 1] <= '9') {
                isNum = true;
            }
            num += dartResult[i];
            continue; // 숫자일 때는 아래 식이 필요 없으니 넘겨
        }
        
        if (!isNum) { // 다음 수가 num이 아닐 경우 (ex. 1의자리 수)
            
            if (dartResult[i] == 'S') { // 1제곱
                number = stoi(num);
                arr.push_back(number);
                
            }
            else if (dartResult[i] == 'D') { // 2제곱
                number = stoi(num);
                arr.push_back(pow(number, 2));
            }
            else if (dartResult[i] == 'T') { // 3제곱
                number = stoi(num);
                arr.push_back(pow(number, 3));
            }
            
            if (dartResult[i] == '*') { // 2배
                arr[arr.size() - 1] *= 2; // 전과 현재만 두배
                arr[arr.size() - 2] *= 2;
            }
            else if (dartResult[i] == '#') { // -
                arr[arr.size() - 1] *= -1; // 앞에 있는거에서 -1배
            }
            num = ""; // num 초기화 시켜주고
        }
    }
    
    for (int i = 0; i < arr.size(); i++) {
        cout << arr[i] << '\n';
        answer += arr[i];
    }
    return answer;
}