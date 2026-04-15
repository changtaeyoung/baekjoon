#include <iostream>

using namespace std;

int computer[101][101] = { 0, };
bool virus[101];
int com, edges, cnt = 0;

void dfs(int v) {
	virus[v] = true;
	
	for (int i = 1; i <= com; i++) {
		if (!virus[i] && computer[v][i] == 1) {
			dfs(i);
			cnt++;
		}
	}
}

int main(void) {
	int c1, c2;
	cin >> com >> edges;

	for (int i = 0; i < edges; i++) {
		cin >> c1 >> c2;
		computer[c1][c2] = 1;
		computer[c2][c1] = 1;
	}

	dfs(1);
	cout << cnt;
}