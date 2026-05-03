#include <string>
#include <vector>
#include <deque>

using namespace std;

/*
    꼭 정사각형은 아님.
    중간 애들은 빠지고 돌리는 거임
    여러번 돌릴 수 있는데, 그 전 턴에 돌린 결과는 유지되어야함.
    그래서 그 범위 내에 있는 최솟값을 원하는 것
    
    1자 배열이라고 생각하고 돌린 다음에 넣으면 되지 않을까?
    예를 들어서 8, 9, 10, 16, 22, 28, 27, 26, 20, 14를 돌리는거 잖아
    (2,2) ~  (5,4) 2와 5만을 포함하고 3,4는 제껴야지. 더해서  2와 4는 포함하고 3은 제껴.
    그러면 (3,3), (4,3)을 제낄 수 있지.
*/

int arr[100][100];

vector<int> solution(int rows, int columns, vector<vector<int>> queries) {
    vector<int> answer;
    
    // arr 채우기 (0base)
    int num = 1;
    for (int i = 0; i < rows; i++) {
        for (int j = 0; j < columns; j++) {
            arr[i][j] = num;
            num++;
        }
    }
    
    // vector 추출하기 (1base니까 바꿔줘야함)
    for (int i = 0; i < queries.size(); i++) {
        int min = 1e9;
        int stX = queries[i][0] - 1, stY = queries[i][1] - 1;
        int endX = queries[i][2] - 1, endY = queries[i][3] - 1;
        
        deque<int> temp;
        
        for (int j = stY; j < endY; j++) {
            temp.push_back(arr[stX][j]);
        }
        
        for (int j = stX; j < endX; j++) {
            temp.push_back(arr[j][endY]);
        }
        
        for (int j = endY; j > stY; j--) {
            temp.push_back(arr[endX][j]);
        }
        
        for (int j = endX; j > stX; j--) {
            temp.push_back(arr[j][stY]);
        }
        
        // 위치 변환
        // 맨 뒤의 요소를 빼서 맨 앞으로 넣는다. (시계 방향 1칸 회전)
        temp.push_front(temp.back());
        temp.pop_back();
        
        int idx = 0; // temp를 앞에서부터 순서대로 꺼낼 인덱스

        // 위쪽 가로
        for (int j = stY; j < endY; j++) arr[stX][j] = temp[idx++];

        // 오른쪽 세로
        for (int i = stX; i < endX; i++) arr[i][endY] = temp[idx++];

        // 아래쪽 가로
        for (int j = endY; j > stY; j--) arr[endX][j] = temp[idx++];

        // 왼쪽 세로
        for (int i = endX; i > stX; i--) arr[i][stY] = temp[idx++];
        
        for (int j = 0; j < temp.size(); j++) {
            if (min > temp[j]) {
                min = temp[j];
            }
        }
        answer.push_back(min);
    }
    
    return answer;
}