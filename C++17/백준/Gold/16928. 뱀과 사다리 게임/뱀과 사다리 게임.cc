#include <iostream>
#include <queue>
#include <unordered_map>
#include <algorithm>

using namespace std;

int n, m;
unordered_map<int, int> map;
int visited[101];

void bfs(int start) {
    queue<int> q;
    q.push(start);
    visited[start] = 1;

    while (!q.empty()) {
        int now = q.front();
        q.pop();

        if (now == 100) {
            break;
        }

        for (int i = 1; i <= 6; i++) {
            int next = now + i;
            if (next > 100) {
                continue;
            }

            if (map.find(next) != map.end()) {
                next = map[next];
            }

            if (!visited[next]) {
                q.push(next);
                visited[next] = visited[now] + 1;
            }
        }
    }
}

int main() {

    /*
        뱀과 사다리인 경우는 간선이 0인 순간이동 노드라고 생각하면 돼
        나머지 1~6까지 주사위로 갈 수 있는 곳이 있다면 그건 간선이 1인 노드인거고
        for문을 이용해서 1~6까지 더하고, 그 map에 있는 값을 이용해 순간이동
    */
   ios::sync_with_stdio(false);
   cin.tie(NULL);
   
   cin >> n >> m;
   for (int i = 0; i < (n + m); i++) {
        int u, v;
        cin >> u >> v;
        map.insert({u, v});
   }

   bfs(1);
   cout << visited[100] - 1;
   return 0;
}