#include<iostream>
#include<vector>
#include<cmath>
using namespace std;
int main()
{
	int N,K,mid;
	int x, y;
	cin >> N;
	cin >> K;
	vector<pair<int, int>>v(pow(N+1,N+1));

	int** map = new int*[N];
	for (int i = 0; i < N; i++)
	{
		map[i] = new int[N];
	}//N*N
	mid = N / 2;
	if (N % 2 != 0)
	{
		x = mid; y = mid - 1;//4->2,1 홀수일 때 1위치

	}
	else {
		x = mid; y = mid;//5->2,2//짝수일 때 1위치
	}
	mid = N / 2;// (4,4)자리가 되게 마지막에 +1 좌표 4->2,1  5-> 2,2

	while (1)
	{
		if (x > N - 1)
		{

		}
	}
	return 0;
}