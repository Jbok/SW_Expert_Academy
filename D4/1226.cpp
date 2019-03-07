#include <iostream>

using namespace std;

int dir[8][2] = { { 1, 1 }, { 1, -1 }, { -1, 1 }, { -1, -1 }, { 1, 0 }, { 0, 1 }, { -1, 0 }, { 0, -1 } };

int arr[16][16] = { 0, };

void dfs(int x, int y, int check[16][16], int *result)
{
    if (arr[y][x] == 3)
    {
        *result = 1;
    }
    else if (arr[y][x] == 1)
    {
        return;
    }
    else
    {
        check[y][x] = 1;
        
        for (int i = 0; i < 8; i++)
        {
            int nextX, nextY;
            nextX = x + dir[i][0];
            nextY = y + dir[i][1];

            if (nextX >= 0 && nextX < 16 && nextY >= 0 && nextY < 16 && check[nextY][nextX] == 0)
            {
                dfs(nextX, nextY, check, result);
            }
        }
    }
}

int main()
{
    for (int cnt = 0; cnt < 10; cnt++)
    {
        int n;
        cin >> n;

        for (int i = 0; i < 16; i++)
        {
            for (int j = 0; j < 16; j++)
            {
                scanf("%1d", &arr[i][j]);
            }
        }

        int result = 0;
        int *ptr = &result;

        int check[16][16] = { 0, };

        dfs(1, 1, check, ptr);

        if (result == 0)
        {
            printf("#%d %d\n", n, result);
        }
        else
        {
            printf("#%d %d\n", n, result);
        }
        
    }
}