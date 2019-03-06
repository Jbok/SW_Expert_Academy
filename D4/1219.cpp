#include <iostream>

using namespace std;

int arr1[101];
int arr2[101];

void dfs(int source, int *value)
{
    int result;

    if (arr1[source] != -1)
    {
        result = arr1[source];
        
        if (result == 99)
        {
            *value = 1;
            return;
        }

        dfs(result, value);
    }
    
    if (arr2[source] != -1)
    {
        result = arr2[source];

        if (result == 99)
        {
            *value = 1;
            return;
        }

        dfs(result, value);
    }
    
}

int main()
{
    for (int i = 0; i < 10; i++)
    {

        for (int j = 0; j < 101; j++)
        {
            arr1[j] = -1;
            arr2[j] = -1;
        }

        int t;
        cin >> t;

        int n;
        cin >> n;

        for (int j = 0; j < n; j++)
        {
            int begin;
            cin >> begin;

            if (arr1[begin] == -1)
            {
                cin >> arr1[begin];
            }
            else
            {
                cin >> arr2[begin];
            }
        }

        int result = 0;
        int *ptr = &result;

        dfs(0, ptr);

        printf("#%d %d\n", t, result);
    }
}