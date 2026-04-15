#include <iostream>
#include <vector>
#include <queue>
#include <cstring>

using namespace std;

vector<int> vec[101];
int visited[101];

void bfs(int st) {
    queue<int> q;
    q.push(st);
    visited[st] = 1;

    while(!q.empty()) {
        int cur = q.front();
        q.pop();

        for (int i = 0; i < vec[cur].size(); i++) {
            int next = vec[cur][i];
            if (!visited[next]) {
                visited[next] = visited[cur] + 1;
                q.push(next);            
            }
        }
    }
}

int main() {
    // 무방향 그래프 방식으로
    // 최단 거리로 가는 경우니까
    // bfs로 이동해서 가면 되겠네.
    // 0based와 1based의 차이 명심해서 수정할 수 있도록 할 것

    vector<int> ans;
    int friends, edges;
    cin >> friends >> edges;

    for (int i = 0; i < edges; i++) {
        int fri1, fri2;
        cin >> fri1 >> fri2;
        
        vec[fri1].push_back(fri2);
        vec[fri2].push_back(fri1);
    }

    for (int i = 1; i <= friends; i++) { // 사람마다 bfs 돌아야하니까 
        int sum = 0;
        memset(visited, 0, sizeof(visited)); // visited 초기화 시켜주고
        bfs(i);
        for (int j = 1; j <= friends; j++) { // bfs 돌고 나온 값을 sum에 합해주고 각 몇번만에 갔는지 저장된 배열이니까.
            sum += visited[j];
        }
        ans.push_back(sum); 
    }

    int min = 999999, idx = 0;
    for (int i = 0; i < ans.size(); i++) { // 여기서 이제 ans를 돌면서 최소값의 인덱스를 찾아가는거지
        if (min > ans[i]) {
            min = ans[i];
            idx = i;
        }
    }
    cout << idx + 1;
    return 0;
}