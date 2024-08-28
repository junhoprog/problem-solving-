#include<iostream>
#include<vector>
using namespace std;

long long int cnt = 0;

int main()
{
	int N;
	cin >> N;
	int B, C;
	vector<int>v(N, 0);
	for (int i = 0; i < N; i++)
	{
		cin >> v[i];
	}
	cin >> B >> C;
	for (int i = 0; i < N; i++)
	{
		v[i] -= B;
		cnt++;
		if (v[i] <= 0)
			continue;
		cnt += v[i] / C;
		if (v[i] % C)
		{
			cnt += 1;
		}
	}
	cout << cnt;
	return 0;
}
/*
N개의 시험장, 각 시험장마다 응시자있음
i번 시험장 Ai명
감독관은 총감독, 부감독이있음
총감독관 감시 B명, 부 감독관 감시 C명
각각 시험장 총 감독관은 무조건 1명 부 감독관여러명 가능
필요한 감독관 수 최솟값
*/