#include <iostream>

using namespace std;

int main()
{
    int t;
    cin >> t;

    int cnt = 0;
    while (1)
    {
        if (cnt == t)
            break;

        int n, m;
        cin >> n >> m;

        int result[41] = { 0, };

        for (int i = 1; i <= n; i++)
        {
            for (int j = 1; j <= m; j++)
            {
                result[i+j]++;
            }
        }

        int max = 0;

        for (int i = 1; i < 41; i++)
        {
            if (max < result[i])
                max = result[i];
        }

        cnt++;

        printf("#%d ", cnt);
        for (int i = 1 ; i < 41; i++)
        {
            if (result[i] == max)
                printf("%d ", i);
        }
        printf("\n");
    }
}