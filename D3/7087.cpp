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

    
        int alphabet[26] = { 0, };
        int ncnt = 0;

        while (1)
        {
            if (ncnt == n)
                break;

            char str[31];
            cin >> str;

            alphabet[ str[0] - 'A' ] = 1;
            ncnt++;          
        }
        
        int nresult = 0;
        for (nresult = 0; nresult < 26; nresult++)
        {
            if (alphabet[nresult] == 0)
                break;
        }

        cnt++;
        printf("#%d %d\n", cnt, nresult);
    }

}