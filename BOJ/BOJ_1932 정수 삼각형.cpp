#include<iostream>
#include<vector>
using namespace std;
int main()
{
	int N;
	cin >> N;
	int x,MAX=0;
	vector<int>v[501];
	vector<int>DP[501];
	for (int i = 1; i <= N; i++)
	{
		for (int j = 1; j <= i; j++)
		{

			cin >> x;
			v[i].push_back(x);
			DP[i].push_back(0);
		}
	}
	if (N == 1)
	{
		cout << v[1][0];
		return 0;
	}
	DP[1][0] = v[1][0];
	for (int i = 2; i <= N; i++)
	{
		for (int j = 0; j < v[i].size()-1; j++)
		{

			//0일땐 그냥 위에
			if (DP[i][j + 1] < v[i][j + 1] + DP[i - 1][j])
			{
				DP[i][j + 1] = v[i][j + 1] + DP[i - 1][j];
			}
			if (DP[i][j] < v[i][j] + DP[i - 1][j])
			{
				DP[i][j] = v[i][j] + DP[i - 1][j];
			}
		}
	}
	for (int i = 2; i <= N; i++)
	{
		for (int j = 0; j < v[i].size(); j++)
		{
			if (MAX < DP[i][j])
			{
				MAX = DP[i][j];
			}
		}
	}

	cout << MAX;
	return 0;
}
//7 3 8 8 1 0 2 7 4 4 4 5
//1 2 3 4 5 6 7 8 9 10 11 12
//현재층 현재층+1이 왼 오 대각선임.
//맨 윗층을 1로