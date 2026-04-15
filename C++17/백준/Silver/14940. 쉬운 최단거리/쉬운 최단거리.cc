#include <iostream>
#include <queue>
#include <vector>
#include <cstring>

using namespace std;

int n, m;
int dp[1001][1001];
int ground[1001][1001];

int dx[] = {0, 0, 1, -1};
int dy[] = {1, -1, 0, 0};

void bfs (int x, int y) {
    queue<pair<int, int>> q;
    q.push({x, y});
    dp[x][y] = 0;

    while(!q.empty()) {
        int cx = q.front().first, cy = q.front().second;
        q.pop();

        for (int i = 0; i < 4; i++) {
            int nx = cx + dx[i], ny = cy + dy[i];

            if (nx < 0 || ny < 0 || nx >= n || ny >= m) {
                continue;
            }

            if (dp[nx][ny] == -1 && ground[nx][ny] == 1) { 
                dp[nx][ny] = dp[cx][cy] + 1;
                q.push({nx, ny});
            }
        }
    }
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);

    cin >> n >> m;

    int stX = 0, stY = 0;
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            cin >> ground[i][j];
            if (ground[i][j] == 2) {
                stX = i;
                stY = j;
            }
        }
    }
    memset(dp, -1, sizeof(dp));
    bfs(stX, stY);

    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            if (ground[i][j] == 0) {
                cout << 0 << ' ';
            }
            else {
                cout << dp[i][j] << ' ';
            }
        }
        cout << '\n';
    }
    return 0;
    /*
        2인 곳부터 시작
        DP 방식으로 ground를 계속 돌면서 거리 계산하기
        0인 바닥은 갈 수 없고, 완전히 갈 수 없는 곳은 -1로
        위와 아래에 +1씩해서 작은 거 선택하면 될듯
        어ㅏ 근데 이게 항상 끝에서 시작하는게 아니다 보니
        dx dy 배열이 필요할 것 같음
        지금 또 다른 생각은 그냥 i를 처음부터 끝까지 하고 목표 지점까지 bfs를 댕기는건데, 0이 아닐때 빼고. 이건 비효율이 커. dp가 맞는데 어떤 방식으로 해야하는걸까
    */

}
