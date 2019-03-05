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

        int a, b;
        cin >> a >> b;

        char temp;

        if (a > b)
        {
            temp = '>';
        }
        else if (a < b)
        {
            temp = '<';
        }
        else
        {
            temp = '=';
        }
        


        cnt++;
        printf("#%d %c\n", cnt, temp);
    }
}