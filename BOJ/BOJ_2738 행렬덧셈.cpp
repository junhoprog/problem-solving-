/*
//어떤 수가 소수의 N제곱 꼴일때, 그 수를 거의 소수라고한다.

#include<iostream>
#include<cmath>
#include<vector>

using namespace std;

int check_sqrt_count(long long int input, long long int min, long long int max) {
	//input 소수, max B
	int count = 0;
	int num = 2;
	//input 3 
	while (1) {
		long long int pow_num = pow(input, num);
		if (pow_num <= max && pow_num >= min) {
			count++;
		}
		if (pow_num >= max) break;
		num++;
	}
	return count;
}


int main()
{
	long long int A, B, cnt = 0, count = 0;
	vector<long long int>v;
	cin >> A >> B;
	int temp;
	cnt += check_sqrt_count(2,A, B);
	if (B!= 1) {
		v.push_back(2);

		for (long long int i = 3; i <= sqrt(B); i++)
		{
			for (long long int j = 0; j <= v.size(); j++) {
				if (i % v[j] == 0)//소수가 아니기 때문에 넘김
				{
					break;
				}
				if (j == v.size() - 1)//끝까지 가면 소수
				{
					v.push_back(i);
					cnt += check_sqrt_count(i,A, B);
				}
			}
		}
	}
	else {
		cout << 0;
		return 0;
	}
	cout << cnt;
	return 0;
} 1456*/
#include<iostream>

int N, M;
using namespace std;
int main()
{
	cin >> N >> M;
	int x;
	int** A = new int* [N];
	for (int i = 0; i < N; i++)
	{
		A[i] = new int[M];
	}
	int** B = new int* [N];
	for (int i = 0; i < N; i++)
	{
		B[i] = new int[M];
	}

	for (int i = 0; i < N; i++)
	{
		for (int j = 0; j < M; j++)
		{
			cin >> x;
			A[i][j] = x;
		}
	}
	for (int i = 0; i < N; i++)
	{
		for (int j = 0; j < M; j++)
		{
			cin >> x;
			B[i][j] = x;
		}
	}

	for (int i = 0; i < N; i++)
	{
		for (int j = 0; j < M; j++)
		{
			A[i][j] += B[i][j];
			cout << A[i][j] << " ";
		}
		cout << endl;
	}

	return 0;
}