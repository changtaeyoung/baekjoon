#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int n, sum = 0;
char maze[26][26];
int dist[26][26];
vector<int> counting;

int dx[] = {0, 0, 1, -1};
int dy[] = {1, -1, 0, 0};

void dfs(int startX, int startY) {
    dist[startX][startY] = 1;
    sum++;

    for (int i = 0; i < 4; i++) {
        int nx = startX + dx[i];
        int ny = startY + dy[i];

        if (nx < 0 || nx >= n || ny < 0 || ny >= n) {
            continue;
        }

        if (maze[nx][ny] == '1' && dist[nx][ny] == 0) { 
            dfs(nx, ny);
        }
    }
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);

    cin >> n;
    for (int i = 0; i < n; i++) {
        string str;
        cin >> str;
        for (int j = 0; j < str.length(); j++) {
            maze[i][j] = str[j];
        }
    }

    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            if (maze[i][j] == '1' && dist[i][j] == 0) { 
                sum = 0;
                dfs(i, j);
                counting.push_back(sum);
            }
        }
    }

    sort(counting.begin(), counting.end()); 
    cout << counting.size() << '\n';
    for (int i = 0; i < counting.size(); i++) {
        cout << counting[i] << '\n';
    }
}