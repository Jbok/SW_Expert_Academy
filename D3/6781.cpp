#include <iostream>

using namespace std;

void dfs(int depth, int end, int *arr, int *result)
{
    if (depth == end)
    {
        int flag = 0;
        for (int i = 0; i < end; i = i+3)
        {
            if ((arr[i] == arr[i+1] && arr[i+1] == arr[i+2]) || (arr[i] == arr[i+1] -1 && arr[i+1] == arr[i+2] - 1))
            {
                
            }
            else
            {
                flag = 1;
            }
        }

        if (flag == 0)
        {
            // for (int i = 0; i < end; i++)
            // {
            //     printf("%d ", arr[i]);
            // }
            // printf("\n");
            *result = 1;
        }
    }
    else
    {
        for (int i = depth; i < end; i++)
        {
            int temp = arr[i];
            arr[i] = arr[depth];
            arr[depth] = temp;

            dfs(depth + 1, end, arr, result);

            temp = arr[i];
            arr[i] = arr[depth];
            arr[depth] = temp;
        }
    }
    
}

int main()
{
    int t;
    cin >> t;

    int cnt = 0;
    while (1)
    {
        if (t == cnt)
            break;

        
        char number[9];
        cin >> number;

        char color[9];
        cin >> color;

        int redNum[9];
        int redCnt = 0;

        int blueNum[9];
        int blueCnt = 0;

        int greenNum[9];
        int greenCnt = 0;

        for (int i = 0; i < 9; i++)
        {
            redNum[i] = -1;
            blueNum[i] = -1;
            greenNum[i] = -1;
        }

        for (int i = 0; i < 9; i++)
        {
            if (color[i] == 'R')
            {
                redNum[redCnt++] = number[i];
            }
            if (color[i] == 'B')
            {
                blueNum[blueCnt++] = number[i];
            }
            if (color[i] == 'G')
            {
                greenNum[greenCnt++] = number[i];
            }
        }

        int result = 0;
        int greenResult = 0;
        int redResult = 0;
        int blueResult = 0;

        if (redCnt % 3 != 0 || blueCnt % 3 != 0 || greenCnt % 3 != 0)
        {
            result = 0;
        }
        else
        {
            
            int *gptr = &greenResult;
            dfs(0, greenCnt, greenNum, gptr);
            
            int *rptr = &redResult;
            dfs(0, redCnt, redNum, rptr);

            int *bptr = &blueResult;
            dfs(0, blueCnt, blueNum, bptr);
        }     
        

        cnt++;

        if (greenResult != 0 && redResult != 0 && blueResult != 0)
        {
            printf("#%d Win\n", cnt);
        }
        else
        {
            printf("#%d Continue\n", cnt);
        }
    }
}