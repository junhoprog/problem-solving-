/*
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
*/

#include<iostream>
#include<algorithm>
using namespace std;
long long N, k,cnt=0,law,high,mid;

long long count(long long x)
{
	long long sum = 0;
	for (int i = 1; i <= N; i++)
	{
		sum += min(x / i, N);
	}
	return sum;
}
long long solve(long long N, long long k)
{
	law = 1; high = N*N;
	while (law <= high)
	{
		mid = (law + high) / 2;
		cnt = count(mid);
		if (k <= cnt)
		{
		high = mid - 1;
		}
		else{
			law = mid + 1;
		}
	
	}
	return law;
}
int main()
{

cin >> N >> k;
cout<<solve(N, k);
return 0;
}