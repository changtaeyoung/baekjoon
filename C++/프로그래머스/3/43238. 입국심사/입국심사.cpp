#include <string>
#include <vector>

using namespace std;
/*
    times 배열의 값은 고정, n은 사람 수도 고정이고
    1분 이상부터, 10억 이하니까, 거기서 이분탐색을 해보는거지.
    나눈 mid값에서 times 배열 값들로 나눈 합이 사람 수일테니, 그 합을 다 더해서 n보다 큰지 작은지 같은지.
    근데 시간의 최솟값이니까 더 낮을 수 있으니 적립하는 방식으로 해보면 좋을 거 같음
*/

long long answer = 1e18;

long long solution(int n, vector<int> times) {
    long long minTime = 1, maxTime = 1e18; 
    
    while (minTime <= maxTime) {
        long long averTime = (minTime + maxTime) / 2;
        long long sumPerson = 0;
        
        // 각 심사관이 몇명을 심사하는가?
        for (int i = 0; i < times.size(); i++) {
            sumPerson += (averTime / times[i]);
        }
        
        // averTime 동안 심사받는 사람 수가 n보다 크면
        // averTime이 줄어야하니 maxTime - 1
        // n명 이상이니까 answer를 갱신하는 곳은 어디여야하는가?
        if (sumPerson >= n) {
            if (answer > averTime) {
                answer = averTime;
            }
            maxTime = averTime - 1;
        }
        else {
            minTime = averTime + 1;
        }
    }
    
    return answer;
}