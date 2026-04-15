#include <iostream>
#include <vector>

using namespace std;

string isbn;
int sum = 0;

int main()
{
    ios::sync_with_stdio(0), cin.tie(0);

    cin >> isbn; //isbn 받고

    bool isStarEven; //*가 짝수인가 홀수인가

    for (int i = 0; i < 13; ++i) //string 돌기
    {
        bool isEven = i % 2; //홀,짝 판별

        if (isbn[i] == '*') //* 판별
        {
            isStarEven = isEven; //*가 홀인지 짝인지
        }
        else
        {
            sum += (isbn[i] - '0') * (isEven ? 3 : 1); //*가 아닐 때 짝수면 가중치 곱해서
        }
    }

    sum %= 10; //10으로 나눠서 나머지 구해

    if (isStarEven) //짝수일 경우
    {
        for (int i = 0; i < 10; ++i)
        {
            if ((sum + i * 3) % 10 == 0)
            {
                cout << i;
                break;
            }
        }
    }
    else
    {
        cout << (10 - sum) % 10;
    }
    return 0;
}