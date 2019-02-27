#include <stdio.h>


int win, loss;

void dfs(int depth, int end, int *enemy, int *arr, int *check, int *result)
{
    if (depth == end)
    {
        int myPoint = 0;
        int enemyPoint = 0;

        for (int i = 0; i < 9; i++)
        {
            if (result[i] > enemy[i])
            {
                myPoint = myPoint + result[i] + enemy[i];
            }
            else
            {
                enemyPoint = enemyPoint + result[i] + enemy[i];
            }
        }

        if (myPoint > enemyPoint)
            win++;
        else if (myPoint < enemyPoint)
            loss++;

        return;
    }
    else
    {
        for (int i = depth; i < end; i++)
        {
            result[depth] = arr[i];
            
            int temp = arr[i];
            arr[i] = arr[depth];
            arr[depth] = temp;

            dfs(depth + 1, end, enemy, arr, check, result);
            
            temp = arr[i];
            arr[i] = arr[depth];
            arr[depth] = temp;
        }
    }
    
}

int main()
{
    int t;
    scanf("%d", &t);

    int cnt = 0;
    while (1)
    {
        if (cnt == t)
            break;

        win = 0;
        loss = 0;

        int kyu[9] = { 0, };
        for (int i = 0; i < 9; i++)
        {
            scanf("%d", &kyu[i]);
        }


        int yung[9];
        int ycnt = 0;
        for (int i = 1; i <= 18; i++)
        {
            int flag = 0;
            for (int j = 0; j < 9; j++)
            {
                if (kyu[j] == i)
                {
                    flag = 1;
                    break;
                }
            }     

            if (flag == 0)
            {
                yung[ycnt] = i;
                ycnt++;
            }
        }

        int check[9] = { 0, };
        int result[9] = { 0, };
        dfs(0, 9, kyu, yung, check, result);

        cnt++;
        // cout << "#" << cnt << " " << loss << " " << win << endl;
        printf("#%d %d %d\n", cnt, loss, win);
    }
}