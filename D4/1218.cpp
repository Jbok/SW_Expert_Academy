#include <iostream>

using namespace std;

int main()
{
    for (int cnt = 1; cnt <= 10; cnt++)
    {
        int n;
        cin >> n;

        char *str = new char[n];
        cin >> str;

        int arr[4] = { 0, };

        int flag = 1;

        for (int i = 0; i < n; i++)
        {
            if (str[i] == '(')
            {
                arr[0] += 1;
            }
            else if (str[i] == '[')
            {
                arr[1] += 1;
            }
            else if (str[i] == '{')
            {
                arr[2] += 1;
            }
            else if (str[i] == '<')
            {
                arr[3] += 1;
            }
            else if (str[i] == ')')
            {
                arr[0] -= 1;
            }
            else if (str[i] == ']')
            {
                arr[1] -= 1;
            }
            else if (str[i] == '}')
            {
                arr[2] -= 1;
            }
            else if (str[i] == '>')
            {
                arr[3] -= 1;
            }

            if (arr[0] < 0 || arr[1] < 0 || arr[2] < 0 || arr[3] < 0)
            {
                break;
                flag = 0;
            }
        }

        if (arr[0] != 0 || arr[1] != 0 || arr[2] != 0 || arr[3] != 0)
        {
            flag = 0;
        }

        printf("#%d %d\n", cnt, flag);
    }
}