#include <iostream>
#include <set>

using namespace std;

int arr[4][4];
int dir[4][2] = { { 1, 0 }, { -1, 0 }, { 0, 1 }, { 0, -1 }};
set<int> s;

int dfs(int depth, int end, int row, int col, int* arrResult)
{
    if (depth == end)
    {
        int result = 0;
        int ten = 1000000;
        for (int i = 0; i < 7; i++)
        {
            result += ten * arrResult[i];
            ten = ten / 10;
        }
        
        // printf("%d ", result);
        s.insert(result);
        return 0;
    }
    else
    {
        for (int i = 0; i < 4; i++)
        {
            int newRow, newCol;
            newRow = row + dir[i][0];
            newCol = col + dir[i][1];
            
            if (newRow >= 0 && newRow < 4 && newCol >= 0 && newCol < 4)
            {
                arrResult[depth] = arr[newRow][newCol];
                dfs(depth+1, end, newRow, newCol, arrResult);
            }
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
        if (cnt == t)
            break;
        
        for (int i = 0; i < 4; i++)
        {
            for (int j = 0; j < 4; j++)
            {
                cin >> arr[i][j];
            }
        }

        for (int i = 0; i < 4; i++)
        {
            for (int j = 0; j < 4; j++)
            {
                int temp = arr[i][j];
                int tempArr[7];
                tempArr[0] = temp;
                dfs(1, 7, i, j, tempArr);
            }
        }

        cnt++;
        printf("#%d %d\n", cnt, s.size());

        s.clear();
    }
}