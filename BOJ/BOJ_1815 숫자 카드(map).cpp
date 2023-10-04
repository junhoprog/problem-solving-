#include<iostream>
#include<map>
using namespace std;
int main()
{
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	int N, M,x;
	cin >> N;
	map<int, bool>m;
	for (int i = 0; i < N; i++)
	{
		cin >> x;
		m[x] = 1;
	}
	cin >> M;
	for (int i = 0; i < M; i++)
	{
		cin >> x;
		if (m[x] == 1)
		{
			cout << 1<<" ";
		}
		else {
			cout << 0<<" ";
		}
	}
	return 0;
}