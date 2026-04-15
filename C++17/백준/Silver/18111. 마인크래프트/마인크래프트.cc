#include <iostream>
#include <vector>

using namespace std;

int n, m, b, min_time = 2147483647, tar_ground = 0;
int ground_height[257] = { 0, };

int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL);

	cin >> n >> m >> b;

	for (int i = 0; i < n; i++) {
		for (int j = 0; j < m; j++) {
			int height;
			cin >> height;
			ground_height[height]++;
		}
	}
	
	for (int target = 0; target < 257; target++) {
		int build = 0, remove = 0;

		for (int h = 0; h < 257; h++) {
			int count = ground_height[h];

			if (h > target) {
				remove += (h - target) * count;
			}
			else if (h < target) {
				build += (target - h) * count;
			}
		}

		if (b + remove >= build) {
			int time = remove * 2 + build * 1;

			if (time <= min_time) {
				min_time = time;
				tar_ground = target;
			}
		}
	}

	cout << min_time << ' ' << tar_ground;
}