#include <iostream>

using namespace std;

int N, r, c;
int ans = 0;

void dividing (int size) { // 잠시만 3번째 행의 1열인 것을 보면..
    if (size == 1) {return;}
    if (c < size / 2) { // c열이 좌측에 있는가?
        if (r < size / 2) { // r행이 상단에 있는가 1

        }
        else { // r행이 하단에 있는가 3
            ans += (size/2) * (size/2) * 2;
            r -= (size / 2);
        }
    }
    else { // c열이 우측에 있는가?
        if (r < size / 2) { // r행이 상단에 있는가 2
            ans += (size/2) * (size/2);
            c -= (size / 2);
        }
        else { // 하단에 있는가 4
            ans += (size/2) * (size/2) * 3;
            r -= (size / 2); 
            c -= (size / 2);
        }
    }
    dividing(size / 2);
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);

    cin >> N >> r >> c; // r: 행, c: 열

    /*
        규칙을 알면 뭔가 쉽게 풀릴 것 같은 느낌?
        0,0 -> 1,0 -> 0,1 -> 1,1
        2,0 -> 3,0 -> 2,1 -> 3,1   
        0,2 -> 1,2 -> 0,3 -> 1,3
        divide&conquer 방식 인것 같은데.. 

        아니면 N/2씩 해서, 0보다 클 때 반복 시키고, 그 위치를 찾아.
        예를 보면, 2,3,1이면 4*4에서 3,1을 찾으라는거잖아.
        4개짜리 3번째잖아? 그럼 2개 제끼니까 8 + 4개 사이에서의 수를 더해주고 하면 답이잖아

        3,7,7이면 8*8이니까 반으로 계속 나누면서 위치 찾고, 16*3개 4*3개 48 + 12 = 60 + 몇번째인지 
    */

    // 뭐 만약 5가 나왔다면 32*32일텐데, 16*16으로 나눠지겠지. 어느 부분에 들어가는지 부터 확인하면 되잖아.
    // 30,22면, 2번째 부분이겠지? 그럼 16*16을 개수가 들어갈테니 더하고, 그 2번째 16*16에서 또 반 나눠 8*8 이런시긍로
    int width = 1;
    for (int i = 0; i < N; i++) {
        width *= 2;
    }

    dividing(width);
    cout << ans;
    return 0;
}