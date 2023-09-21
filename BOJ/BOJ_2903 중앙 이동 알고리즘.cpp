#include<iostream>
#include<cmath>
using namespace std;
int main()
{
	int N;
	int arr[16];
	cin >> N;
	int num = 3;
	arr[1] = pow(num,2);
	if (N == 1)
	{
		cout << arr[1];
		return 0;
	}
	for (int i = 2; i <= N; i++)
	{
		num += pow(2, i - 1);
		arr[i] = pow(num, 2);
	}
	cout<<arr[N];
	return 0;
}