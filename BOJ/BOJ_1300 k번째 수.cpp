/*
메모리 초과
#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;

int main()
{
	int N;
	cin >> N;

	vector<int>B;
	B.push_back(0);

	int** A = new int* [N+1];
	for (int i = 0; i < N+1; i++)
	{
		A[i] = new int[N+1];
	}

	for (int i = 1; i < N+1; i++)
	{
		for (int j = 1; j < N+1; j++)
		{
			A[i][j] = i * j;
			B.push_back(A[i][j]);
		}
	}

	sort(B.begin(), B.end());

	int k;
	cin >> k;
	cout << B[k];

	for (int i = 0; i < N+1; i++)
	{
		delete [] A[i];
	}
	delete[]A;
	return 0;
}

