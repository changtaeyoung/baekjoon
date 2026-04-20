#include <string>
#include <vector>
#include <algorithm>
#include <unordered_map>
#include <map>
#include <cmath>
#include <iostream>

using namespace std;

/*
    요금표인 fees 배열 
    0: 기본 시간, 1: 기본 요금, 2: 단위 시간, 3: 단위 요금
    입차 후 출차 기록이 없을 경우 23:59 출차
    누적 주차 시간 < fees[0] -> fees[1]
    누적 주차 시간 > fees[0] -> fees[1] + fees[3] * (누적 주차 시간 - 기본 시간) / fees[2]
    if 나누어 떨어지지 않으면 올림
*/

unordered_map<string, string> parking; // car number, TIME
map<string, int> sumTimes; // car number, cost

vector<int> solution(vector<int> fees, vector<string> records) {
    vector<int> answer;
    
    for (int i = 0; i < records.size(); i++) {
        string time = records[i].substr(0, 5);
        string carNum = records[i].substr(6, 4);
        string inOrOut = records[i].substr(11);
        
        if (inOrOut == "IN") {
            parking.insert({carNum, time});
        }
        else if (inOrOut == "OUT") {
            if (parking.find(carNum) != parking.end()) {
                int outHour = stoi(records[i].substr(0, 2));
                int outMin = stoi(records[i].substr(3, 2));
                int inHour = stoi(parking[carNum].substr(0, 2));
                int inMin = stoi(parking[carNum].substr(3, 2));
                
                sumTimes[carNum] += (outHour - inHour) * 60 + (outMin - inMin);
                
                parking.erase(carNum);
            }
        }
    }
    
    for (auto it : parking) {
        int inHour = stoi(it.second.substr(0, 2));
        int inMin = stoi(it.second.substr(3, 2));
        
        if(sumTimes.find(it.first) != sumTimes.end()) {
            sumTimes[it.first] += (23 - inHour) * 60 + (59 - inMin);
        }
        else {
            sumTimes[it.first] = (23 - inHour) * 60 + (59 - inMin);
        }
    }
    
    for (auto it : sumTimes) {
        int sumFees = 0;
        if (it.second <= fees[0]) {
            answer.push_back(fees[1]);
        }
        else {
            sumFees += fees[1];
            sumFees += (ceil((double)(it.second - fees[0]) / fees[2])) * fees[3];
            answer.push_back(sumFees);
        }
    }
    return answer;
}