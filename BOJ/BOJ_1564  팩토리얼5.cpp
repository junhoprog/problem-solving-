#include<iostream>
#include<string>
using namespace std;
int main()
{
	long long int N;
	long long int sum = 1;
	string s;
	cin >> N;
	for (int i = 1; i <= N; i++)
	{
		sum *= i;
		while (sum % 10 == 0)
		{
			sum /= 10;
		}
		sum  %= 1000000;

	}
	sum %= 100000;
	s = to_string(sum);
	while (1)
	{
		if (sum < 10000)
		{
			s = "0" + s;
			sum *= 10;
		}
		else {
			break;
		}
	}
	cout << s;
	return 0;
}