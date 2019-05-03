#include <iostream>
#include <cstdio>

using namespace std;

int arr[1000001];

int main()
{
	int testCase;
	cin >> testCase;

	for (int t = 0; t < testCase; t++)
	{
		int n;
		cin >> n;

		for (int i = 0; i < n; i++)
		{
			scanf("%d", &arr[i]);
		}


		int maxValue = arr[n - 1];
		long long result = 0;

		for (int i = n - 2; i >= 0; i--)
		{
			if (arr[i] > maxValue)
			{
				maxValue = arr[i];
			}
			else
			{
				result += maxValue - arr[i];
			}
		}

		printf("#%d %lld\n", t+1, result);
	}
}