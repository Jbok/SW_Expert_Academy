#include <iostream>

using namespace std;

int change(int *target, int length)
{
    int result = 0;

    for (int i = 0; i < length-1; i++)
    {
        for (int j= i+1; j < length; j++)
        {
            int temp;
            temp = target[i];
            target[i] = target[j];
            target[j] = temp;

            int ten = 1;
            int tempResult = 0;
            for (int i = length-1; i >= 0; i++)
            {
                tempResult += target[i] * ten;
                ten = ten * 10; 
            }     
            if (tempResult > result)
                result = tempResult;

            temp = target[i];
            target[i] = target[j];
            target[j] = temp;
        }
    }

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

        int target, n;
        cin >> target >> n;

        int ten = 1;
        int num = 0;
        while (1)
        {
            if (target / ten == 0)
                break;

            num++;
            ten = ten * 10;
        }

        int arr[6] = { 0, };
        for (int i = 0; i < num; i++)
        {
            arr[i] = (target%ten)/(ten/10);

            ten = ten/10;
        }

        for (int i = 0; i < num; i++)
        {
            printf("%d ", arr[i]);
        }

        int result = change(arr, num);

        printf("num: %d\n", num);

        printf("result: %d\n", result);

        cnt++;
    }
}