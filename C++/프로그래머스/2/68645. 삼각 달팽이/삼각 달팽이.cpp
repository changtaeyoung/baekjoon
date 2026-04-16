#include <string>
#include <vector>

using namespace std;

/*
    idx: 0 1 3 6 7 8 9 5 2 4
    num: 1 2 3 4 5 6 7 8 9 10
    근데 그 n에 따라서 또 배열에 넣는 위치가 달라지는데..
    n일때마다 방향만 바꿔주면 되고, cnt 세면서, 어느 인덱스에 넣을지만 확인하면 될 듯
    2차원 배열 써서 넣는건가
    1
    2 9(1,1)
    3 10 8(2,2)
    4 5 6 7(3,3)
*/
int arr[1001][1001];
int dx[] = {1, 0, -1};
int dy[] = {0, 1, -1};

vector<int> solution(int n) {
    vector<int> answer;
    
    int num = 1, x = -1, y = 0; 
    for (int i = 0; i < n; i++) {
        int direction = i % 3;
        for (int j = i; j < n; j++) {
            x += dx[direction];
            y += dy[direction];
            
            arr[x][y] = num;
            num++;
        }
    }
    
    
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            if (arr[i][j] == 0) {
                break;
            }
            answer.push_back(arr[i][j]);
        }
    }
    return answer;
}