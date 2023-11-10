#include<iostream>
#include<vector>
#include<algorithm>

using namespace std;

int Q_index(int N, vector<int>v)
{
	int cnt = 0, max = 0;
	for (int i = 0; i <= v.size(); i++)
	{
		cnt = 0;
		for (int j = 0; j < v.size(); j++)
		{
			if (v[j] >= i)
			{
				cnt++;
			}
		}
		if (cnt >= i && v.size() - cnt <= i)
		{
			max = i;
		}
	}
	return max;
}

int main()
{
	int N,x;
	cin >> N;
	vector<int>v;
	for (int i = 0; i < N; i++)
	{
		cin >> x;
		v.push_back(x);
	}
	sort(v.begin(), v.end());
	cout << Q_index(N, v);
	return 0;
}