#include <iostream>

using namespace std;

int main()
{
    for (int cnt = 1; cnt <= 10; cnt++)
    {
        int result = 0;

        int n;
        cin >> n;

        char *str = new char[n];
        cin >> str;

        for (int i = 0; i < n; i++)
        {
            if (str[i] != '+')
            {
                result += str[i] - '0';
            }
        }


        printf("#%d %d\n", cnt, result);
    }
}