#include<iostream>
#include<vector>
using namespace std;
long long int max_num=0;

void Search(long long int start, long long int end, vector<long long int>& v, int N)
{
	int cnt = 0;
	long long int mid = (start + end) / 2;
	while (start <= end) {
		cnt = 0;
		mid = (start + end) / 2;

		for (int i = 0; i < v.size(); i++)
		{
			cnt += v[i] / mid;//9라면 줄이고 12라면 늘려야해
		}

		if (cnt >= N)
		{
			start = mid + 1; 
			if (max_num < mid)
			{
				max_num = mid;
			}
		}
		else if (cnt < N)
		{
			end = mid - 1;
		}
	}
	cout << max_num;
}

int main()
{
	long long int K, N;
	int cnt = 0;
	cin >> K >> N;
	long long int x;
	vector<long long int>v;
	for (int i = 0; i < K; i++)
	{
		cin >> x;
		v.push_back(x);
	}

	long long int maxx = v[0];
	for (int i = 1; i < v.size(); i++)
	{
		if (maxx < v[i])
		{
			maxx = v[i];
		}
	}
	Search(1,maxx,v,N);

	return 0;
}