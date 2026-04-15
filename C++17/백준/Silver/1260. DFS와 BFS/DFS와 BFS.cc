#include <iostream>
#include <algorithm>
#include <queue>

using namespace std;

bool visited[1001];
int arr[1001][1001] = { 0, };
int n, m, v;

void dfs(int v) {
	visited[v] = true;
	cout << v << " ";
	for (int i = 0; i <= n; i++) {
		if (!visited[i] && arr[v][i] == 1) {
			dfs(i);
		}
		if (i == n) {
			return;
		}
	}
}

void bfs(int v) {
	queue<int> bfs_help;
	bfs_help.push(v);

	while (!bfs_help.empty()) {
		int temp = bfs_help.front();
		visited[temp] = true;
		bfs_help.pop();
		cout << temp << " ";
		for (int i = 0; i <= n; i++) {
			if (!visited[i] && arr[temp][i] == 1) {
				bfs_help.push(i);
				visited[i] = true;
			}
		}
	}

}

int main() {
	int p1, p2;
	cin >> n >> m >> v;

	for (int i = 0; i < m; i++) {
		cin >> p1 >> p2;
		arr[p1][p2] = 1;
		arr[p2][p1] = 1;
	}

	dfs(v);
	cout << "\n";
	fill(visited, visited + 1001, false);

	bfs(v);
	return 0;
}

