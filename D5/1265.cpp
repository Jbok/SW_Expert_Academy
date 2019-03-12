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

        int arr[100] = { 0, };

        int divi;
        cin >> divi;

        int value;
        value = n / divi;
        for (int i = 0; i < divi; i++)
        {
            arr[i] = value;
        }


        int remain = n % divi;
        for (int i = 0; i < remain; i++)
        {
            arr[i]++;
        }

        long long result = 1;
        for (int i = 0 ; i < divi; i++)
        {
            result = result * arr[i];
        }


        cnt++;
        printf("#%d %lld\n", cnt, result);
    }
}