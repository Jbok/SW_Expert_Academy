#include <iostream>

using namespace std;

int arr[21][21] = { 0, };

int main()
{
	int t;
    cin >> t;
    
    int cnt = 0;
    while (1)
    {
		if (cnt == t)
            break;
        
        int n, m;
        cin >> n >> m;
        
        for (int i = 0; i < n; i++)
        {
			for (int j = 0; j < m; j++)
            {
				cin >> arr[i][j];
            }
        }
        
        int max = 0;
        int people = 0;
        
        for (int i = 0; i < n; i++)
        {
            int temp = 0;
			for (int j = 0; j < m; j++)
            {
                temp += arr[i][j];
            }
            
            if (temp > max)
            {
				people = 1;
                max = temp;
            }
            else if (temp == max)
            {
				people++;
            }
        }
        
        cnt++;
        printf("#%d %d %d\n", cnt, people, max);
    }
}