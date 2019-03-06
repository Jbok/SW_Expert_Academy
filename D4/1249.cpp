#include <iostream>
#include <deque>

using namespace std;

int dir[4][2] = { { 1, 0 }, { 0, 1 }, { -1, 0 }, { 0, -1 } };

int arr[100][100] = { 0, };
int arrMin[100][100];

typedef struct node
{
    int x;
    int y;
}Node;

deque<Node> dq;

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


        for (int i = 0; i < n; i++)
        {
            for (int j = 0; j < n; j++)
            {
                scanf("%1d", &arr[i][j]);
                
                arrMin[i][j] = 100000000;
            }
        }  

        Node start = { 0, 0 };
        arrMin[start.x][start.y] = 0;
        
        dq.push_back(start);

        while (1)
        {
            if (dq.empty())
                break;

            Node now = dq.front();
            dq.pop_front();

            Node next;
            for (int i = 0; i < 4; i++)
            {
                next.x = now.x + dir[i][0];
                next.y = now.y + dir[i][1];

                if (next.x < n && next.y < n && next.x >= 0 && next.y >= 0)
                {
                    if (arrMin[next.x][next.y] > arrMin[now.x][now.y] + arr[next.x][next.y])
                    {
                        arrMin[next.x][next.y] = arrMin[now.x][now.y] + arr[next.x][next.y];
                        dq.push_back(next);
                    }       
                }

            }
        }
        cnt++;
        printf("#%d %d\n", cnt, arrMin[n-1][n-1]);
    }
}