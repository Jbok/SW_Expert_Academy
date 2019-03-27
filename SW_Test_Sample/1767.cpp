#include <iostream>
#include <deque>

using namespace std;

typedef struct node
{
	int r;
	int c;
}point;

int arr[12][12] = { 0, };
int dir[4][2] = { {-1, 0}, {0, 1}, {1,0}, {0, -1} };
point core[12];

void dfs(int n, int now, int finish, int correctTemp, int lineTemp, int *correct, int *line, int arr[12][12])
{
	int nowR = core[now].r;
	int nowC = core[now].c;

	/*
	printf("\n");
	printf("n:%d now:%d finish:%d correctTemp:%d lineTemp:%d \n", n, now, finish, correctTemp, lineTemp);
	printf("nowR:%d nowC:%d\n", nowR, nowC);
	for (int i = 0; i < n; i++)
	{
		for (int j = 0; j < n; j++)
		{
			printf("%d ", arr[i][j]);
		}
		printf("\n");
	}
	printf("\n");
	///*/
	
	if (now == finish)
	{
		//printf("lineTemp: %d correctT: %d *line :%d *correct:%d\n", lineTemp, correctTemp, *line, *correct);
		if (*correct > correctTemp)
		{
			return;
		}
		else if (*correct == correctTemp)
		{
			if (*line > lineTemp)
			{
				*line = lineTemp;
			}
			return;
		}
		else
		{
			*correct = correctTemp;
			*line = lineTemp;
		}
		return;
	}


	if (nowR == 0 || nowC == 0 || nowR == n - 1 || nowC == n - 1)
	{
		correctTemp++;
		dfs(n, now + 1, finish, correctTemp, lineTemp, correct, line, arr);
	}
	else
	{
		for (int i = 0; i < 4; i++)
		{
			int nextR = nowR + dir[i][0];
			int nextC = nowC + dir[i][1];
			int nextCorrectTemp = correctTemp;
			int nextLineTemp = lineTemp;
			
			while (1)
			{
				if (nextR >= 0 && nextR < n & nextC >= 0 && nextC < n)
				{
					if (arr[nextR][nextC] == 0)
					{
						if (nextR == 0 || nextC == 0 || nextR == n - 1 || nextC == n - 1)
						{
							nextCorrectTemp++;

							// 1표시
							if (nowR <= nextR && nowC <= nextC)
							{
								for (int j = nowR; j <= nextR; j++)
								{
									for (int k = nowC; k <= nextC; k++)
									{
										arr[j][k] = 2;
										nextLineTemp++;
									}
								}
							}
							else if (nowR >= nextR && nowC <= nextC)
							{
								for (int j = nextR; j <= nowR; j++)
								{
									for (int k = nowC; k <= nextC; k++)
									{
										arr[j][k] = 2;
										nextLineTemp++;
									}
								}
							}
							else if (nowR <= nextR && nowC >= nextC)
							{
								for (int j = nowR; j <= nextR; j++)
								{
									for (int k = nextC; k <= nowC; k++)
									{
										arr[j][k] = 2;
										nextLineTemp++;
									}
								}
							}
							else if (nowR >= nextR && nowC >= nextC)
							{
								for (int j = nextR; j <= nowR; j++)
								{
									for (int k = nextC; k <= nowC; k++)
									{
										arr[j][k] = 2;
										nextLineTemp++;
									}
								}
							}

							nextLineTemp -= 1;
							dfs(n, now + 1, finish, nextCorrectTemp, nextLineTemp, correct, line, arr);

							if (nowR <= nextR && nowC <= nextC)
							{
								for (int j = nowR; j <= nextR; j++)
								{
									for (int k = nowC; k <= nextC; k++)
									{
										arr[j][k] = 0;
									}
								}
							}
							else if (nowR >= nextR && nowC <= nextC)
							{
								for (int j = nextR; j <= nowR; j++)
								{
									for (int k = nowC; k <= nextC; k++)
									{
										arr[j][k] = 0;											
									}
								}
							}
							else if (nowR <= nextR && nowC >= nextC)
							{
								for (int j = nowR; j <= nextR; j++)
								{
									for (int k = nextC; k <= nowC; k++)
									{
										arr[j][k] = 0;
									}
								}
							}
							else if (nowR >= nextR && nowC >= nextC)
							{
								for (int j = nextR; j <= nowR; j++)
								{
									for (int k = nextC; k <= nowC; k++)
									{
										arr[j][k] = 0;
									}
								}
							}
							arr[nowR][nowC] = 1;

							break;
						}
						else
						{
							nextR += dir[i][0];
							nextC += dir[i][1];
						}
					}
					else
					{
						dfs(n, now + 1, finish, correctTemp, lineTemp, correct, line, arr);
						break;
					}
				}
				else
				{
					break;
				}	
			}


		}
		
	}
}

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

		int coreNum = 0;

		for (int i = 0; i < n; i++)
		{
			for (int j = 0; j < n; j++)
			{
				scanf("%d", &arr[i][j]);
				if (arr[i][j] == 1)
				{
					core[coreNum++] = { i, j };
				}
			}
		}

		int correctMax = 0;
		int lineMin = 10000;

		int *ptrCorrect = &correctMax;
		int *ptrLine = &lineMin;

		dfs(n, 0, coreNum, 0, 0, ptrCorrect, ptrLine, arr);

		cnt++;
		printf("#%d %d\n", cnt, lineMin);
	}
}