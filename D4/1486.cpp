#include <iostream>
#include <algorithm>
#include <deque>

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

        int n, b;
        cin >> n >> b;

        int arr[20] = { 0, };
        for (int i = 0; i < n; i++)
        {
            scanf("%d", &arr[i]);
        }
        sort(arr, arr+n);

        deque<int> dq;
        dq.push_back(0);

        for (int i = 0; i < n; i++)
        {
            int now = arr[i];

            deque<int> dqTemp;
    
            while (1)
            {
                if (dq.empty())
                    break;
                
                int temp = dq.front();
                dq.pop_front();

                dqTemp.push_back(temp);
                dqTemp.push_back(temp+now);
            }

            dq.swap(dqTemp);
        }

        int min = 200001;

        while (1)
        {
            if (dq.empty())
                break;

            int temp = dq.front();
            dq.pop_front();

            if (temp >= b)
            {
                if (temp-b < min)
                {
                    min = temp-b;
                }
            }            
        }

        cnt++;
        printf("#%d %d\n", cnt, min);
    }
}

