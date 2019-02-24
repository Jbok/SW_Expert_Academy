#include <iostream>
#include <math.h>

using namespace std;

long long Calculation(long long a, long long b, int n, long long r, long long c)
{
    int temp = r-c;
    if (temp < 0)
        temp = temp * -1;

    long long result = a * temp + b * (n - r * c);
    
    return result;
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

        int n, a, b;
        cin >> n >> a >> b;

        long long min = 10000000000 + 10000000000;

        for (int i = 1; i <= n; i++)
        {
            int small = i;
            int big = n / small;

            for (int j = 1; j <= big; j++)
            {
                // printf("small:%d big:%d\n", small, j);
                long long temp = Calculation(a, b, n, small, j);
                if (temp < min)
                {
                    // printf("%d\n", min);
                    min = temp;
                }
            }
            

            
        }

        cnt++;
        printf("#%d %d\n", cnt, min);
    }

    return 0;
}