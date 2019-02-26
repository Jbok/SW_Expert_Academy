#include <iostream>

using namespace std;

int main()
{
    int t;
    cin >> t;

    int cnt = 0;

    while (1)
    {
        if (t == cnt)
            break;

        int n;
        cin >> n;

        int start = 'A'- 1;

        int ncnt = 0;
        int nresult = 0;
        while (1)
        {
            if (ncnt == n)
                break;

            char str[31];
            cin >> str;

            if ((int)(str[0])-1 != start)
            {
                
            }
            else
            {
                start++;
                nresult++;
            }

            ncnt++;          
        }
        
        cnt++;
        printf("#%d %d\n", cnt, nresult);
    }

}