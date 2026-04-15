#include <iostream>
#include <algorithm>
#include <queue>

using namespace std;

int subin_loc, bro_loc;
bool visited[100001] = {};

void bfs(int v) {
	queue<pair<int, int>> q;
	q.push(make_pair(v, 0)); // v에 있을 때, 시간 0
	while (!q.empty()) {
		int x = q.front().first;
		int cnt = q.front().second;
		q.pop();
		if (x == bro_loc) {
			cout << cnt;
			break;
		}
		if (x + 1 >= 0 && x + 1 < 100001) {
			if (!visited[x + 1]) {
				visited[x + 1] = true;
				q.push(make_pair(x + 1, cnt + 1));
			}
		}
		if (x - 1 >= 0 && x - 1 < 100001) {
			if (!visited[x - 1]) {
				visited[x - 1] = true;
				q.push(make_pair(x - 1, cnt + 1));
			}
		}
		if (2 * x >= 0 && 2 * x < 100001) {
			if (!visited[2 * x]) {
				visited[2 * x] = true;
				q.push(make_pair(2 * x, cnt + 1));
			}
		}
	}
}

int main(void) {
	cin >> subin_loc >> bro_loc;
	bfs(subin_loc);
	return 0;
}