#include<iostream>
using namespace std;
int main()
{
	int A, B, C;
	int arr[10] = { 0, };
	long long sum = 0;
	cin >> A >> B >> C;
	sum = A * B * C;
	long long result = sum;

	while (result != 0)
	{
		arr[result % 10]++;
		result /= 10;

	}
	for (int i = 0; i < 10; i++)
	{
		cout << arr[i] << endl;
	}
	return 0;
}