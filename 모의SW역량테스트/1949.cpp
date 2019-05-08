#include <iostream>
#include <cstdio>
#include <deque>

using namespace std;

typedef struct
{
	int r;
	int c;
}Point;

int dir[4][2] = { {1, 0}, {-1, 0}, {0, 1}, {0, -1} };
int arr[8][8] = { 0, };
int n, k;
int maxLength;

void Dfs(Point now, int flag, int length, int (*check)[8])
{
	if (length > maxLength)
	{
		maxLength = length;
	}

	Point next;
	for (int i = 0; i < 4; i++)
	{
		next.r = now.r + dir[i][0];
		next.c = now.c + dir[i][1];

		if (next.r >= 0 && next.r < n && next.c >= 0 && next.c < n && check[next.r][next.c] == 0)
		{
			if (arr[next.r][next.c] < arr[now.r][now.c])
			{
				check[next.r][next.c] = 1;
				Dfs(next, flag, length+1, check);
				check[next.r][next.c] = 0;
			}

			if (flag == 0)
			{
				for (int deep = 1; deep <= k; deep++)
				{
					if (arr[next.r][next.c] - deep < arr[now.r][now.c])
					{
						int temp = arr[next.r][next.c];
						arr[next.r][next.c] -= deep;
						

						check[next.r][next.c] = 1;
						Dfs(next, 1, length + 1, check);
						check[next.r][next.c] = 0;

						arr[next.r][next.c] = temp;
					}
				}
			}

		}
	}
}

int main()
{
	int t;
	cin >> t;

	for (int testCase = 1; testCase <= t; testCase++)
	{
		cin >> n >> k;

		int maxValue = 0;

		for (int i = 0; i < n; i++)
		{
			for (int j = 0; j < n; j++)
			{
				scanf("%d", &arr[i][j]);
				if (arr[i][j] > maxValue)
				{
					maxValue = arr[i][j];
				}
			}
		}

		deque<Point> dqMaxPoint;
		for (int i = 0; i < n; i++)
		{
			for (int j = 0; j < n; j++)
			{
				if (arr[i][j] == maxValue)
				{
					dqMaxPoint.push_back({ i, j });
				}
			}
		}

		maxLength = 0;
		for (deque<Point>::iterator iter = dqMaxPoint.begin(); iter != dqMaxPoint.end(); iter++)
		{
			int check[8][8] = { 0, };
			check[(*iter).r][(*iter).c] = 1;
			Dfs(*iter, 0, 1, check);
		}

		printf("#%d %d\n", testCase, maxLength);
	}

}