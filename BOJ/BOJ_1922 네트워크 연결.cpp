#include<iostream>
#include<vector>
using namespace std;
int main()
{
	int N,M;
	cin >> N;
	cin >> M;
	int A, B, C;
	int** w = new int*[N];
	for (int i = 0; i < N; i++)
	{
		w[i] = new int[N];
	}
	for (int i = 0; i < N; i++)
	{
		for (int j = 0; j < N; j++)
		{
			w[i][j] = 0;
		}
	}

	for (int i = 0; i < N; i++)
	{
		cin >> A >> B >> C;
		w[A - 1][B - 1] = w[B - 1][A - 1] = C;
	}
	vector<bool>v;
	int min=1000;
	for (int i = 0; i < N; i++)
	{
		min = 1000;
		for (int j = 0; j < N; j++)
		{
			if (w[i][j] == 0)
			{
				continue;
			}
			if (v[i] == true)
			{
				continue;
			}

			else {
				if (min > w[i][j])
				{
					min = w[i][j];
				}
			}
		}
	}
	int sum = 0;

	
	return 0;
}