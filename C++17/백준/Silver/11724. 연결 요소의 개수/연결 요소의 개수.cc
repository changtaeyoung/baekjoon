#include <iostream>
#include <vector>

using namespace std;

vector<int> graph[1001];
int visited[1001] = { 0, };

void dfs(int v) {
	visited[v] = 1;
	for (int i = 0; i < graph[v].size(); i++) {
		int idx = graph[v][i];
		if (visited[idx] == 0) {
			dfs(idx);
		}
	}
}

int main(void) {
	int vertexs, edges, v1, v2, cnt = 0;
	cin >> vertexs >> edges;

	for (int i = 0; i < edges; i++) {
		cin >> v1 >> v2;
		graph[v1].push_back(v2);
		graph[v2].push_back(v1);
	}

	for (int i = 1; i <= vertexs; i++) {
		if (visited[i] == 0) {
			cnt++;
			dfs(i);
		}
	}
	cout << cnt;
}