#include<iostream>
using namespace std;
int main()
{
	int N, M;
	int x,y;
	cin >> N >> M;
	int* bucket = new int[N];
	for (int i = 0; i < N; i++)
	{
		bucket[i] = i + 1;
	}
	int temp;
	for (int i = 0; i < M; i++)
	{
		cin >> x >> y;

		temp = bucket[x - 1];
		bucket[x - 1] = bucket[y - 1];
		bucket[y - 1] = temp;
	}
	for (int i = 0; i <N; i++)
	{
		cout << bucket[i] << " ";
	}
	return 0;
}