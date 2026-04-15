#include <iostream>
#include <queue>

using namespace std;
int n, m, k;
int ground[51][51] = { 0, };
bool visited[51][51];

int dirX[4] = { 0,0,1,-1 };
int dirY[4] = { 1,-1,0,0 };

void dfs(int y, int x) {
	for (int i = 0; i < 4; i++) {
		int nextX = x + dirX[i];
		int nextY = y + dirY[i];

		if (nextY < 0 || nextY >= n || nextX< 0 || nextX >= m) {
			continue;
		}
		if (ground[nextY][nextX] && !visited[nextY][nextX]) {
			visited[nextY][nextX] = true;
			dfs(nextY, nextX);
		}
	}
}

int main(void) {
	int test, p1, p2;
	cin >> test;

	for (int i = 0; i < test; i++) {
		int cnt = 0;
		cin >> m >> n >> k;
		for (int j = 0; j < k; j++) {
			cin >> p1 >> p2;
			ground[p2][p1] = 1;
		}

		for (int l = 0; l < n; l++) {
			for (int h = 0; h < m; h++) {
				if (ground[l][h] == 1 && !visited[l][h]) {
					dfs(l, h);
					cnt++;
				}
			}
		}
		cout << cnt << "\n";

		for (int l = 0; l < n; l++) {
			fill(ground[l], ground[l] + m, 0);
			fill(visited[l], visited[l] + m, false);
		}
	}
}