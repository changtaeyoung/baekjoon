#include <iostream>

using namespace std;

int paper[128][128];
int cnt_white = 0, cnt_blue = 0;

// 부분이 0또는 1로 칠해져 있는가 확인
void check(int st_wid, int st_hei, int len) {

	int start = paper[st_wid][st_hei];
	for (int i = st_wid; i < st_wid + len; i++) {
		for (int j = st_hei; j < st_hei + len; j++) {
			if (start != paper[i][j]) { // 하나라도 틀리면 4등분
				check(st_wid, st_hei, len / 2);
				check(st_wid, st_hei + len / 2, len / 2);
				check(st_wid + len / 2, st_hei, len / 2);
				check(st_wid + len / 2, st_hei + len / 2, len / 2);
				return;
			}
		}
	}
	if (start == 0) { // 흰 색종이
		cnt_white++;
	}
	else if (start == 1) { // 파란 색종이
		cnt_blue++;
	}
}

// 메인
int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL);

	int n;
	cin >> n;

	for (int i = 0; i < n; i++) {
		for (int j = 0; j < n; j++) {
			cin >> paper[i][j];
		}
	}

	check(0, 0, n);
	cout << cnt_white << '\n' << cnt_blue;
	return 0;
}