#include <iostream>
#include <deque>
#include <set>

using namespace std;

int main()
{
    for (int cnt = 1; cnt <= 10; cnt++)
    {
        int n, start;
        cin >> n >> start;

        int max = -1;
        int count = -1;

        set<int> s[101];
        for (int i = 0; i < n/2; i++)
        {
            int from;
            scanf("%d", &from);

            int to;
            scanf("%d", &to);

            s[from].insert(to);
        }


        int check[101] = { 0, };

        deque<int> dq;

        set<int>::iterator iter;
        check[start] = 1;
        for (iter = s[start].begin(); iter != s[start].end(); iter++)
        {
            dq.push_back(0);
            dq.push_back(*iter);
            check[*iter] = 1;
            // printf("iter: %d\n", *iter);
        }

        while (1)
        {
            if (dq.empty())
                break;

            int nowCnt = dq.front();
            dq.pop_front();

            int now = dq.front();
            dq.pop_front();
            // printf("now: %d\n", now);
    

            if (nowCnt > count)
            {
                max = now;
                count = nowCnt;        
            }
            else if (nowCnt == count)
            {
                if (max < now)
                    max = now;
            }

            for (iter = s[now].begin(); iter != s[now].end(); iter++)
            {
                if (check[*iter] == 0)
                {
                    dq.push_back(nowCnt+1);
                    dq.push_back(*iter);
                    check[*iter] = 1;
                }  
            }   
        }

        printf("#%d %d\n", cnt, max);
    }
}

/*

1 17
3 22
1 8
1 7
7 1
2 7
2 15
15 4
6 2
11 6
4 10 
4 2


*/