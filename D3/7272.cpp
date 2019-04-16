#include <iostream>
#include <string.h>

using namespace std;

char str1[11];
char str2[11];

int main()
{
	int t;
	cin >> t;

	int cnt = 0;
	while (1)
	{
		if (cnt == t)
		{
			break;
		}

		cin >> str1 >> str2;

		int flag = 1;

		if (strlen(str1) != strlen(str2))
		{
			flag = 0;
		}
		else
		{
			for (int i = 0; i < strlen(str1); i++)
			{
				int value1, value2;
				
				if (str1[i] == 'B')
				{
					value1 = 2;
				}
				else if (str1[i] == 'A' || str1[i] == 'D' || str1[i] == 'O' || str1[i] == 'P' || str1[i] == 'Q' || str1[i] == 'R')
				{
					value1 = 1;
				}
				else
				{
					value1 = 0;
				}

				if (str2[i] == 'B')
				{
					value2 = 2;
				}
				else if (str2[i] == 'A' || str2[i] == 'D' || str2[i] == 'O' || str2[i] == 'P' || str2[i] == 'Q' || str2[i] == 'R')
				{
					value2 = 1;
				}
				else
				{
					value2 = 0;
				}

				if (value1 == value2)
				{

				}
				else
				{
					flag = 0;
					break;
				}
			}
		}

		cnt++;
		if (flag == 0)
		{
			printf("#%d DIFF\n", cnt);
		}
		else
		{
			printf("#%d SAME\n", cnt);
		}
		
	}
}