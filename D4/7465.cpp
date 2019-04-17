#include <iostream>
#include <cstdio>
#include <vector>
#include <deque>

using namespace std;

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

		int n, m;
		cin >> n >> m;

		vector<int> v[101];

		for (int i = 0; i < m; i++)
		{
			int a, b;
			cin >> a >> b;

			v[a].push_back(b);
			v[b].push_back(a);
		}

		bool check[101] = { 0, };
		int groupNum = 0;
		for (int i = 1; i <= n; i++)
		{
			if (check[i] == false)
			{
				deque<int> dq;
				dq.push_back(i);
				check[i] = true;

				while (1)
				{
					if (dq.empty())
					{
						groupNum++;
						break;
					}

					int now = dq.front();
					dq.pop_front();

					while (1)
					{
						if (v[now].empty())
						{
							break;
						}

						int nowV = v[now].back();
						v[now].pop_back();

						if (check[nowV] == false)
						{
							check[nowV] = true;
							dq.push_back(nowV);
						}
					}
				}
			}
			

		}


		cnt++;
		printf("#%d %d\n", cnt, groupNum);
	}
}