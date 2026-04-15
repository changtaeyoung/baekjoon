#include <iostream>

using namespace std;

int nodes;
int edges[101][101];
int visited[101][101];

void dfs(int st, int cur) { // 맨 처음에 시작한 위치 , 현재 도착한 위치

    for (int i = 0; i < nodes; i++) {
        if (!visited[st][i] && edges[cur][i] == 1) {
            visited[st][i] = 1;
            dfs(st, i);
        }
    }
}

int main() {
    /*
    방향 그래프
    인접 행렬로 줬다
    i 번째 i 원소는 항상 0
    i - j 의 원소가 1이면 간선이 존재한다. 결국 간선이 존재하느냐 존재하지 않느냐를 따져야할 것 같네

    결국 이 문제를 해결하려면 노드들 간에 간선이 존재하느냐를 알아야하기 때문에 dfs를 이용해야할 것 같은데
    0base와 1base 헷갈리지마라.
    */
    ios::sync_with_stdio(false);
    cin.tie(NULL);

    cin >> nodes;

    for (int i = 0; i < nodes; i++) {
        for (int j = 0; j < nodes; j++) {
            cin >> edges[i][j];
        }
    }
    // edges에 다 들어갔어.

    for (int i = 0; i < nodes; i++) { // 맨 처음에 출발한 노드, 현재 도착한 노드
        dfs(i, i);
    }
    // 그렇다면 하나마다 dfs를 걸어준다?
    // 그렇다기 보다 그냥 visited 배열을 보내주면 될 것 같은데
    // visited 배열을 2차원으로 만들 순 없을 것 같기도 하고. [시작위치, 도착위치] 이런식으로 해야하나?

    for (int i = 0; i < nodes; i++) {
        for (int j = 0; j < nodes; j++) {
            cout << visited[i][j] << ' ';
        }
        cout << '\n';
    }
    return 0;
}