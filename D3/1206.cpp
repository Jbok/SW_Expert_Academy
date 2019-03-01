#include <iostream>

using namespace std;

int main()
{
    int t = 10;

    int cnt = 0;
    while (1)
    {
        if (cnt == t)
            break;


        int arr[1001] = { 0, };

        int n;
        cin >> n;

        for (int i = 0; i < n; i++)
        {
            cin >> arr[i];
        }
        int result = 0;

        for (int i = 2; i < n-2; i++)
        {
            int max = 255;
            if (arr[i-1] < arr[i] && arr[i-2] < arr[i] && arr[i+1] < arr[i] && arr[i+2] < arr[i])
            {
                int r1 = arr[i] - arr[i-1];
                int r2 = arr[i] - arr[i-2];
                int r3 = arr[i] - arr[i+1];
                int r4 = arr[i] - arr[i+2];

                if (r1 < max)
                    max = r1;

                if (r2 < max)
                    max = r2;
                
                if (r3 < max)
                    max = r3;
                
                if (r4 < max)
                    max = r4;
            }
            else
            {
                max = 0;
            }          

            result += max;
        }

        cnt++;
        printf("#%d %d\n", cnt, result);
    }
}