#include <vector>
#include <algorithm>
#include <queue>
#include <iostream>
#define INF 999999999

using namespace std;

vector<pair<int, int>> adj[51];
int dist[51];

void ds(int start, int N) {
    
    for (int i = 1; i <= N; i++) dist[i] = INF;

    // c++은 priority_queue의 기본이 최소힙
    priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> pq;
    
    pq.push({0, start});
    dist[start] = 0;
    
    while (!pq.empty()) {
        int curDist = pq.top().first;
        int curIdx = pq.top().second;
        pq.pop();
        
        if (dist[curIdx] < curDist) continue;
        
        for (auto& next : adj[curIdx]) {
            int nextIdx = next.first;
            int cost = next.second;
            
            if (dist[nextIdx] > curDist + cost) {
                dist[nextIdx] = curDist + cost;
                pq.push({dist[nextIdx], nextIdx});
            }
        }
    }
}

int solution(int N, vector<vector<int>> road, int K) {
    int answer = 0;
    
    for(int i=0; i<=50; i++) adj[i].clear();

    for (int i = 0; i < road.size(); i++) {
        adj[road[i][0]].push_back({road[i][1], road[i][2]});
        adj[road[i][1]].push_back({road[i][0], road[i][2]});
    }
    
    ds(1, N);
    
    for (int i = 1; i <= N; i++) { 
        if (dist[i] <= K) {
            answer++;
        }
    }
    
    return answer;
}