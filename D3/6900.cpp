#include <iostream>

using namespace std;

int main()
{
    int t, n, m;
    cin >> t;
    
    int cnt = 0;
    while (1)
    {
        cin >> n >> m;
        if (cnt == t)
            break;

        char** win = new char*[n];
        for (int i = 0; i < n; i++)
        {
            win[i] = new char[9];
        }

        int *price = new int[n];

        char** have = new char*[m];
        for (int i = 0; i < m; i++)
        {
            have[i] = new char[9];
        }

        for (int i = 0; i < n; i++)
        {
            scanf("%s", win[i]);
            scanf("%d", &price[i]);
        }

        for (int i = 0; i < m; i++)
        {
            scanf("%s", have[i]);
        }

        int result = 0;

        for (int i = 0; i < n; i++)
        {
            for (int j = 0; j < m; j++)
            {
                int flag = 0;
                for (int k = 0; k < 8; k++)
                {
                    if (win[i][k] == '*')
                    {
						
                    }
                    else if (win[i][k] == have[j][k])
                    {

                    }
                    else
                    {
                        // printf("i: %d k:%d / j:%d k:%d / win[i][k]:%c / win:%s / have[j][k]:%c / have:%s \n", i, k, j, k, win[i][k], win[i], have[j][k], have[j]);
                        flag = 1;
                        break;
                    }
                }

                if (flag == 0)
                {
                    result += price[i];
                }
            }
        }

        printf("#%d %d\n", cnt+1, result);

        cnt++;

        for (int i = 0; i < n; i++)
        {
            delete[] win[i];
        }
        delete[] win; 

        delete[] price;

        for (int i = 0; i < m; i++)
        {
            delete[] have[i];
        }
        delete[] have;
    }
    
   return 0;

}