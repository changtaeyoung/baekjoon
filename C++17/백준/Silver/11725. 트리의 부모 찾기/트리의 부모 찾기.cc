#include <iostream>
#include <vector>

using namespace std;

vector<int> adj[100001];
int parent[100001];

void dfs(int par) {
    if (par == 1) parent[par] = 1;
    for (int i = 0; i < adj[par].size(); i++) {
        if (parent[adj[par][i]] == 0) {
            parent[adj[par][i]] = par;
            dfs(adj[par][i]);
        }
    }
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);

    int n;
    cin >> n;

    for (int i = 0; i < n - 1; i++) {
        int node1, node2;
        cin >> node1 >> node2;

        adj[node1].push_back(node2);
        adj[node2].push_back(node1);
    }

    dfs(1);

    for (int i = 2; i <= n; i++) {
        cout << parent[i] << '\n';
    }
    return 0;
}