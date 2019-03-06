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

        int n;
        cin >> n;

        int *arr = new int[n];
        for (int i = 0; i < n; i++)
        {
            scanf("%d", &arr[i]);
        }


        int temp[10001] = { 0, };
        int score[10001] = { 0, };        

        for (int i = 0; i < n; i++)
        {
            for (int j = 0; j < 10001; j++)
            {
                temp[j] = score[j];
            }

            for (int j = 0; j < 10001; j++)
            {
                if (temp[j] == 1)
                {
                    score[j + arr[i]] = 1;
                }
            }

            score[arr[i]] = 1;
        }

        int result = 0;
        for (int j = 0; j < 10001; j++)
        {
            if (score[j] == 1)
            {
                result++;
            }
        }

        cnt++;
        printf("#%d %d\n", cnt, result+1);
    }   
}