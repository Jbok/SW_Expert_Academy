#include <iostream>

using namespace std;

int arr[100][100] = { 0, };

int main()
{
    for (int cnt = 1; cnt <= 10; cnt++)
    {
        int trash;
        cin >> trash;

        for (int i = 0; i < 100; i++)
        {
            for (int j = 0; j < 100; j++)
            {
                scanf("%d", &arr[i][j]);
            }
        }

        for (int i = 0; i < 100; i++)
        {
            int check[100][100] = { 0, };
            int y = 0;
            int x = i;

            int flag = -1;

            if (arr[y][x] == 1)
            {
                while (1)
                {
                    check[y][x] = 1;
                    
                    if (y == 99 && arr[y][x] == 2)
                    {
                        flag = i;
                        break;
                    }
                    else if (y == 99 && arr[y][x] != 2)
                    {
                        flag = -1;
                        break;
                    }
                    else if (x+1 < 100 && arr[y][x+1] == 1 && check[y][x+1] == 0)
                    {
                        x = x+1;
                    }
                    else if (x-1 >= 0 && arr[y][x-1] == 1 && check[y][x-1] == 0)
                    {
                        x = x-1;
                    }
                    else
                    {
                        y = y+1;
                    }
                }
            }
            
            if (flag == -1)
            {

            }
            else
            {
                printf("#%d %d\n", cnt, flag);
            }
            
        }
    }
}