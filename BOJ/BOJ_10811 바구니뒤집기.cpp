#include<iostream>
#include<vector>
#include<algorithm>

using namespace std;
int main()
{
	int N, M, a, b, t = 0,temp;
	cin >> N >> M;
	vector<int>v(N+1);
	for (int i = 0; i < v.size(); i++)
	{
		v[i] = i;
	}

	for (int i = 0; i < M; i++)
	{
		t = 0;
		cin >> a >> b;
		for (int j = a; j< b; j++)//(a+b)/2
		{
			temp = v[j];
			v[j] = v[b - t];
			v[b - t] = temp;

			if (j+1>=(b-t))
			{
				break;
			}
			t++;
		}
	}
	for (int i = 1; i < v.size(); i++)
	{
		cout << v[i] << " ";
	}
	return 0;
}
