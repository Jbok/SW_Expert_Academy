#include <iostream>
#include <cstdio>

#define S 365
#define E 24
#define M 29

using namespace std;

int main()
{
	int t;
	cin >> t;

	for (int testCase = 1; testCase <= t; testCase++)
	{
		int s, e, m;
		scanf("%d%d%d", &s, &e, &m);

		long long n = s;
		
		if (s == S)
		{
			s = 0;
		}

		if (m == M)
		{
			m = 0;
		}

		if (e == E)
		{
			e = 0;
		}
		
		while (1)
		{
			if (n % S == s && n % E == e && n % M == m)
			{
				printf("#%d %lld\n", testCase, n);
				break;
			}
			else
			{
				n += S;
			}
		}
	}
}