#include <string>
#include <vector>
#include <algorithm>
#include <cmath>

using namespace std;

/*
    트리 형태로 되어있대.
    일단 그 노드 연결되어있는 것을 알기 위해 adj를 알아야겠지.
    여기서 이제 어디서 끊을 건지? 를 알아야 할것인데.
    아니면 pair를 써서, {현 노드, 타고온 개수}? 타고온 개수가 거리를 말하는거야. 각 간선을 1로 두고,
    dfs로 연결되어있는 개수를 셀 수 있는데. 하나씩 끊어봐야하나?
    예를 들어서 2중 for문을 이용해 i = 0, 1, 2 ... wires.size를 끊어보는거지 내부 반복에서는 adj 연결을 하고.
*/

int visited[101];
int num;

void dfs (int node, vector<int> adj[]) { 
    visited[node] = 1;
    num++;
    
    for (int next : adj[node]) {
        if (!visited[next]) {
            dfs(next, adj);
        }
    }
}

int solution(int n, vector<vector<int>> wires) {
    int answer = 999999;
    vector<int> adj[n + 1];
    
    for (int i = 0; i < wires.size(); i++) { // 하나씩 여기서 끊어보는거야. 100 이하니까 가능할 것 같음

        for (int j = 0; j <= n; j++) { // adj 초기화 과정
            adj[j].clear();
        }
        fill(visited, visited + 101, 0);
        num = 0;
        
        for (int j = 0; j < wires.size(); j++) { // 여기서 노드 연결을 하고
            if (i != j) {
                adj[wires[j][0]].push_back(wires[j][1]);
                adj[wires[j][1]].push_back(wires[j][0]);
            }
        }
        
        dfs(1, adj);
        int diff = abs(n - 2 * num);
        
        if (answer > diff) {
            answer = diff;
        }
    }

    return answer;
}