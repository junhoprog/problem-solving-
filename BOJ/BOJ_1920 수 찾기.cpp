#include<iostream>
#include<algorithm>
#include<vector>
using namespace std;

void Search(bool* B, vector<int>v, long long int* arr2, int i, int s, int q) {
	int m = (s + q) / 2;
	if (v[q] < arr2[i])
	{
		B[i] = 0;
		return;
	}
	else {
		if (v[m] < arr2[i])
		{
			Search(B, v, arr2, i, m + 1, q);
		}
		else if (v[m] > arr2[i])
		{
			Search(B, v, arr2, i, s, m);
		}

		else if (v[m] == arr2[i]) {
			B[i] = 1;
		}
		else {
			B[i] = 0;
		}
	}
}
void Find_num(bool* B, vector<int>v, long long int* arr2, int N, int M)
{
	for (int i = 0; i < M; i++)
	{
		Search(B, v, arr2, i, 0, M - 1);
	}
}
int main()
{
	int N, M;
	cin >> N;
	vector<int>v(N);
	for (int i = 0; i < N; i++)
	{
		cin >> v[i];
	}

	cin >> M;
	long long int* arr2 = new long long int[M];
	bool* B = new bool[M];
	for (int i = 0; i < M; i++)
	{
		B[i] = 0;
	}
	for (int j = 0; j < M; j++)
	{
		cin >> arr2[j];
	}
	sort(v.begin(), v.end());
	Find_num(B, v, arr2, N, M);
	for (int i = 0; i < M; i++)
	{
		cout << B[i] << "\n";
	}
	delete[]B;
	delete[]arr2;
	//arr2에 있는 수들이 arr에 존재하는지 알아내기-
	return 0;
}