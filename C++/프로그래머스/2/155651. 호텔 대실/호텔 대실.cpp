#include <string>
#include <vector>
#include <algorithm>
#include <queue> // 우선순위 큐 사용을 위해 추가

using namespace std;
int timeToMin(string time) {
    int hour = stoi(time.substr(0, 2));
    int minute = stoi(time.substr(3, 2));
    return (hour * 60) + minute;
}

int solution(vector<vector<string>> book_time) {
    vector<pair<int, int>> times;
    
    for (int i = 0; i < book_time.size(); i++) {
        int start = timeToMin(book_time[i][0]);
        int end = timeToMin(book_time[i][1]) + 10; 
        times.push_back({start, end});
    }
    
    sort(times.begin(), times.end());
    
    // 현재 사용 중인 방들의 종료 시간을 담아둘 최소 힙 (가장 빨리 끝나는 방이 맨 위로 옴)
    priority_queue<int, vector<int>, greater<int>> pq;
    
    for (int i = 0; i < times.size(); i++) {
        // 큐가 비어있지 않고, 가장 빨리 끝나는 방의 시간이 현재 손님의 시작 시간보다 작거나 같으면
        if (!pq.empty() && pq.top() <= times[i].first) {
            pq.pop(); // 기존 손님을 방에서 뺌 (새 손님이 그 방을 쓸 거니까)
        }
        
        // 새 방을 파든, 기존 방을 이어서 쓰든 현재 손님의 종료 시간을 큐에 넣음
        pq.push(times[i].second);
    }
    
    // 모든 손님을 다 받았을 때, 큐에 남아있는 원소의 개수가 곧 필요한 최소 방의 개수
    return pq.size();
}