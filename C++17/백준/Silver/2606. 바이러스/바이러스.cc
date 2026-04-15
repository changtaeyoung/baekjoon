#include <iostream>
#include <vector>

using namespace std;

vector<int> adj[101];
bool virus[101] = {false,};
int cnt = 0;

void dfs(int v) {
    virus[v] = true;
    for (int next : adj[v]) {
        if (!virus[next]) {
            cnt++;
            dfs(next);
        }
    }
}

int main() {
    int vertex_num, edge_num;
    cin >> vertex_num >> edge_num;

    for (int i = 0; i < edge_num; i++) {
        int v1, v2;
        cin >> v1 >> v2;
        adj[v1].push_back(v2);
        adj[v2].push_back(v1);
    }

    dfs(1);
    cout << cnt;
}
