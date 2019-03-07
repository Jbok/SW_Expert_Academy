#include <iostream>

using namespace std;

int arr[100][100] = { 0, };

int checkFunction(int startX)
{
    int x = startX;
    int y = 0;
    int result = 1;

    int check[100][100] = { 0, };

    while (1)
    {
        check[y][x] = 1;
        
        if (x+1 < 100 && arr[y][x+1] == 1 && check[y][x+1] == 0)
        {
            x = x+1;
        }
        else if (x-1 >= 0 && arr[y][x-1] == 1 && check[y][x-1] == 0)
        {
            x = x-1;
        }
        else
        {
            if (y == 99)
                return result;
            
            y = y+1;
        }

    
        result++;    
    }
}

int main()
{
    for (int cnt = 0; cnt < 10; cnt++)
    {
        int testCase;
        cin >> testCase;

        for (int i = 0; i < 100; i++)
        {
            for (int j = 0; j < 100; j++)
            {
                scanf("%d", &arr[i][j]);
            }
        }

        int min = 10000;
        int index;

    
        for (int i = 99; i >= 0; i--)
        {
            if (arr[0][i] == 1)
            {
                int temp = checkFunction(i);
                if (min > temp)
                {
                    min = temp;
                    index = i;
                }
            }
        }

        printf("#%d %d\n", testCase, index);
    }
}
