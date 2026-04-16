#include <string>
#include <vector>
#include <unordered_map>
#include <iostream>

using namespace std;

unordered_map<long long, long long> map;

long long solution(vector<int> weights) {
    long long answer = 0;
    /*
        map에 각 몸무게당 몇명이 있는지 확인해
        그리고 1:1, 1:2, 2:3, 3:4 위치에 놓을 수 있음
        그러면 iterator 돌릴 때 
        2명 이상인가? 하면 2명일 경우 1개, 3명일 경우 2개 이런식으로 적용 가능하지. 즉 인원수 - 1하면 되고
        1:2일 경우, 그 위치에서 2배인 놈이 map에 존재하는가? 그리고 인원수 - 1
        없으면 2:3 것도 확인 자신의 2배한 것 나누기 3한 애가 map에 있는가
        3배 한것 나누기 4한 애가 map에 있는가
        여기서 근데 if-else문이 아닌 if문으로 하는 것이 좋아보임.
    */
    
    for (int i = 0; i < weights.size(); i++) {
        map[weights[i]]++;
    }
    
    for (auto it : map) {
        if (it.second > 1) {
            answer += ((it.second) * (it.second - 1) / 2);
        }
        
        if (map.find(it.first * 2) != map.end()) {
            answer += ((it.second) * map[it.first * 2]);
        }
        
        if (it.first * 2 % 3 == 0 && map.find(it.first * 2 / 3) != map.end()) {
            answer += ((it.second) * map[it.first * 2 / 3]);
        }
        
        if (it.first * 3 % 4 == 0 && map.find(it.first * 3 / 4) != map.end()) {
            answer += ((it.second) * map[it.first * 3 / 4]);
        }
    }
    return answer;
}