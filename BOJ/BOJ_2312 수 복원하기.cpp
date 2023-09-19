#include<iostream>
#include<vector>
using namespace std;
int main()
{
	vector<int>v2;
	vector<int>v3;
	v2.push_back(2);
	for (int i = 3; i < 100001; i++)
	{
		for (int j = 0; j <v2.size(); j++) {
			if (i % v2[j] == 0)
			{
				break;
			}
			if (j == v2.size() - 1)
			{
				v2.push_back(i);
			}
		}
	}
	int t,N;
	vector<int>v;
	cin >> t;
	for (int i = 0; i < t; i++)
	{
		cin >> N;
		v.push_back(N);
	}
	t = 0;
	int check = 0;
	int cnt = 0;
	while (t<v.size())
	{
		cnt = 0;
	for (int i = 0; i < v2.size(); i++)
	{
		cnt = 0;
		check = 0;
		while (v[t] % v2[i] == 0)
		{
			v[t] /= v2[i];
			cnt++;
			check = 1;
		}

		if (check == 1) { cout << v2[i] << " " << cnt << endl; }
		if (v[t] == 1)
		{
			break;
		}

	}
	t++;
	}

	return 0;
}