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


        int x1, y1, x2, y2;
        cin >> x1 >> y1 >> x2 >> y2;

        int n;
        cin >> n;

        int exterior = 0;
        int cross = 0;
        int interior = 0;

        for (int i = 0; i < n; i++)
        {
            int xn, yn;
            cin >> xn >> yn;

            if (xn < x1 || xn > x2 || yn < y1 || yn > y2)
            {
                exterior++;
            }
            else if (yn == y1 && xn >= x1 && xn <= x2)
            {
                cross++;
            }
            else if (yn == y2 && xn >= x1 && xn <= x2)
            {
                cross++;
            }
            else if (xn == x1 && yn >= y1 && yn <= y2)
            {
                 cross++;
            }
            else if (xn == x2 && yn >= y1 && yn <= y2)
            {
                cross++;
            }
            else
            {
                interior++;
            }
        }
        cnt++;
        printf("#%d %d %d %d\n", cnt, interior, cross, exterior);
    }
}
