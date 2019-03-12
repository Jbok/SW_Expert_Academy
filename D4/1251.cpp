#include <iostream>
#include <deque>
#include <math.h>

using namespace std;

double valueArr[1000][1000] = { 0, };

double CalValue(double x1, double y1, double x2, double y2, double e)
{
    // printf("%lld %lld %lld %lld %lf \n", x1, x2, y1, y2, e);
    double result = ( (x1-x2)*(x1-x2) + (y1-y2)*(y1-y2) ) * e;
    // printf("x1-x2 %d %d\n", x1-x2, (x1-x2)*(x1-x2));
    // printf("y1-y2 %d %d\n", y1-y2, (y1-y2)*(y1-y2));
    // printf("result: %lf\n", result);
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

        int n;
        scanf("%d", &n);

        int x[1000];
        int y[1000];

        for (int i = 0; i < n; i++)
        {
            scanf("%d", &x[i]);
        }

        for (int i = 0; i < n; i++)
        {
            scanf("%d", &y[i]);
        }

        double e;
        scanf("%lf", &e);

        for (int i = 0; i < n; i++)
        {
            for (int j = 0; j < n; j++)
            {
                valueArr[i][j] = CalValue(x[i], y[i], x[j], y[j], e);
            }
        }

        


        int check[1000] = { 0, };
        deque<int> dq;

        dq.push_back(0);
        check[0] = 1;

        double result = 0;

        for (int i = 0; i < n-1; i++)
        {
            double min = 1000000000000;
            int idx;

            for (deque<int>::iterator iter = dq.begin(); iter != dq.end(); iter++)
            {
                for (int j = 0 ; j < n; j++)
                {
                    if (check[j] == 0)
                    {
                        double temp = valueArr[*iter][j];
                        
                        if (temp < min)
                        {
                            min = temp;
                            idx = j;
                        }
                    }
                    
                }
            }

            dq.push_back(idx);
            check[idx] = 1;
            result += min;
        }   



        cnt++;
        printf("#%d %lld\n", cnt, (long long)(floor(result+0.5)));
    }
}