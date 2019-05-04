#include <cstdio>
#include <iostream>

using namespace std;

void Check(int integer)
{
	int arr[100];

	int idx = 0;
	int tempInteger = integer;
	while (1)
	{
		if (integer == 0)
		{
			break;
		}

		arr[idx] = integer % 10;
		integer = integer / 10;
		idx++;
	}

	int flag = 1;

	for (int i = 0; i < idx; i++)
	{
		if (arr[i] == 3 || arr[i] == 6 || arr[i] == 9)
		{
			flag = 0;
			printf("-");
		}
	}

	if (flag == 1)
	{
		printf("%d ", tempInteger);
	}
	else
	{
		printf(" ");
	}
}

int main()
{
	int n;
	cin >> n;

	for (int i = 1; i <= n; i++)
	{
		Check(i);
	}
}