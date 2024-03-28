#include<iostream>
#include<algorithm>
using namespace std;

int N, M;
int check(int target,int A[])
{
	
	int	start = 0;
	int end = N-1;
	while (start<=end)
	{
		int mid = (start + end) / 2;
		if (A[mid] < target)//더 크면
		{
			start = mid + 1;
		}
		else if (A[mid] == target)//발견!
		{
			return 1;
		}
		else {//더 작으면
			end = mid - 1;
		}
	}
	return 0;
}
int main()
{
	ios_base::sync_with_stdio(0); 
	cin.tie(0);

	int A[100000];
	cin >> N;
	for (int i = 0; i < N; i++)
	{
		cin >> A[i];
	}
	
	sort(A,A+N);
	
	cin >> M;
	int x;
	for (int i = 0; i < M; i++)
	{
		cin >> x;
		cout << check(x,A) << "\n";
	}
	
	return 0;
}
