#include<iostream>
#include<vector>
using namespace std;
void dp(int** P, int k, int n)
{
	int sum = 0;
	if (k != 0)
	{
		dp(P, k - 1, n);//해당층
		for (int i = 1; i <= n; i++)
		{
			for (int j = 1; j <= i; j++)
			{
				sum += P[k - 1][j];
			}
		}

		//k층이 0층일 때까지 0층이면 1~n층까지 더해서 각각 p[k][n]에 넣기
	}
	else {
		for (int i = 1; i <= n; i++) {
			P[0][i] = i;
		}
		//k가 0층일 때의 값을 넣어주고 이값으로 윗층들을 채워줌
	}
	//기록 해놓기
}

int main()
{
	//a층 b호에 살려면 a-1층의 1호부터 b호까지 
	//사람들의 수의 합만큼 사람들을 데려와야한다.

	//0층 i호->i명
	int T, k, n, d = 0;
	cin >> T;
	int* arr = new int[T];

	while (T > 0) {
		cin >> k;
		cin >> n;
		int** P = new int* [k];
		for (int i = 0; i < k; i++)
		{
			P[i] = new int[n + 1];
		}
		dp(P, k, n);
		arr[d] = P[k][n];
		d++;
		T--;
	}
	for (int i = 0; i < d; i++)
	{
		cout << arr[i] << endl;
	}
	return 0;
}