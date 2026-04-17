#include <string>
#include <vector>
#include <stack>
#include <iostream>

using namespace std;

stack<int> basket;
int arr[30][30];

int solution(vector<vector<int>> board, vector<int> moves) {
    int answer = 0, now;
    
    for (int i = 0; i < board.size(); i++) {
        for (int j = 0; j < board[i].size(); j++) {
            arr[i][j] = board[i][j];
        }
    }
    
    for (int i = 0; i < moves.size(); i++) {
        int x = moves[i] - 1;
        now = 0;
        for (int j = 0; j < board.size(); j++) {
            if (arr[j][x] != 0) {
                now = arr[j][x];
                arr[j][x] = 0;
                break;
            }
        }
        
        if (!basket.empty() && basket.top() == now) {
            basket.pop();
            answer += 2;
        }
        else {
            if (now != 0) {
                basket.push(now);
            }
        }
    }
    return answer;
}