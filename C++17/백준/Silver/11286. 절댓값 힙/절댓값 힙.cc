#include <iostream>
#include <queue>

using namespace std;

int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL);

	int tc;
	cin >> tc;

	priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> pq;

	for (int i = 0; i < tc; i++) {
		int num = 0;
		cin >> num;

		if (num != 0) { // push
			if (num < 0) { // 음수
				pq.push({ -1 * num, num });
			}
			else { //양수
				pq.push({ num, num });
			}
		}
		else if (num == 0) { // pop 및 출력
			// pq가 일단 비었는지 확인해야 segementation fault가 안나오니까
			if (pq.empty()) {
				cout << 0 << '\n';
			}
			else { // 안 비어있으면 절댓값 제일 작은 거에서 실제로 작은 값을 pop 및 출력
				cout << pq.top().second << '\n';
				pq.pop();
			}
		}
	}

	return 0;
	/*
	0이 아닌 값이 들어온다, 저장
	0이 들어오면 절댓값 중 가장 작은 값 출력 및 값 제거
	절댓값에서도 작은 수를 제거 (ex. 3 -> 3, -3 중 -3 먼저 제거)
	priority_queue 에서 pair를 써서 앞은 절댓값 뒤는 원래 값 저장해서 제거하면 될 것 같은데?
	아니면, priority_queue에서 절댓값을 오름차순으로 만들고, 최소힙으로
	그 다음에 맵에서 찾아서, second가 2개인가? 를 판별하면 될 것 같은데? 예를 들어서 (1,1) (1, -1)이 있다면
	second를 비교하면 될 것 같음..... 그럴거면 priority pair를 쓰는게 맞지.... 후자로 가보자
	*/
}