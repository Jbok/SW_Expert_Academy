#include <iostream>

using namespace std;

int main()
{
    int t;
    scanf("%d", &t);

    int cnt = 0;
    while (1)
    {
        if (cnt == t)
            break;

        int m;
        scanf("%d", &m);

        int value;
        if (m < 100)
        {
            value = 0;
        }
        else if (m < 1000)
        {
            value = 1;
        }
        else if (m < 10000)
        {
            value = 2;
        }
        else if (m < 100000)
        {
            value = 3;
        }
        else if (m < 1000000)
        {
            value = 4;
        }
        else
        {
            value = 5;
        }
        

        cnt++;
        printf("#%d %d\n", cnt, value);
    }
}