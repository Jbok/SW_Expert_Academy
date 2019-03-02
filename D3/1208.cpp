#include <iostream>

using namespace std;

int main()
{
    int cnt = 0;

    while (1)
    {
        if (cnt == 10)
            break;

        int dump = 0;
        cin >> dump;

        int arr[100];
        for (int i = 0; i < 100; i++)
        {
            cin >> arr[i];
        }

        int maxIdx, minIdx;
        
        for (int j = 0; j < dump; j++)
        { 
            int min = 101;
            int max = 0;
            for (int i = 0; i < 100; i++)
            {
                if (min > arr[i])
                {
                    min = arr[i];
                    minIdx = i;
                }

                if (max < arr[i])
                {
                    max = arr[i];
                    maxIdx = i;
                }
            }
        
            arr[minIdx]++;
            arr[maxIdx]--;
        }

        int resMin = 101;
        int resMax = 0;
        for (int i = 0; i < 100; i++)
        {
            int temp = arr[i];
            if (resMin > arr[i])
            {
                resMin = arr[i];
            }

            if (resMax < arr[i])
            {
                resMax = arr[i];
            }
        }
        
        cnt++;
        printf("#%d %d\n", cnt, resMax-resMin);
    }
}