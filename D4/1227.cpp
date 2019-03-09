#include <iostream>

using namespace std;

int dir[4][2] = { { 1, 0 }, { -1, 0 }, { 0, 1 }, { 0, -1 } };

int arr[100][100] = { 0, };

int result = 0;

void dfs(int x, int y, int check[100][100])
{
    int nowX, nowY;

    for (int i = 0; i < 4; i++)
    {
        nowX = x + dir[i][0];
        nowY = y + dir[i][1];

        if (nowX < 0 || nowY < 0 || nowX >= 100 || nowY >= 100)
        {

        }
        else if (arr[nowY][nowX] == 0 && check[nowY][nowX] == 0)
        {
            check[nowY][nowX] = 1;
            dfs(nowX, nowY, check);
        }
        else if (arr[nowY][nowX] == 3 && check[nowY][nowX] == 0)
        {
            result = 1;
            return;
        }
        
    }
}

int main()
{
    for (int cnt = 0; cnt < 10; cnt++)
    {
        int t;
        cin >> t;
        
        for (int i = 0; i < 100; i++)
        {
            for (int j = 0; j < 100; j++)
            {
                scanf("%1d", &arr[i][j]);
            }
        }

        int check[100][100] = { 0, };
        check[1][1] = 1;

        result = 0;
        dfs(1, 1, check);

        printf("#%d %d\n", t, result);
    }
}