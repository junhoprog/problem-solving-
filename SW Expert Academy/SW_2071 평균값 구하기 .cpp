#include<iostream>
using namespace std;
int main()
{
	int T,x,sum=0;
	double avg = 0;
	cin >> T;
	for (int i = 1; i <= T; i++)
	{
		sum = 0;
		for (int j = 0; j < 10; j++)
		{
			cin >> x;
			sum += x;
		}
		cout << "#" << i << " ";
		if (sum % 10 == 0)
		{
			sum /= 10;
		}
		else {
			if (sum % 10 < 5)
			{
				sum -= sum % 10;
				sum /= 10;
			}
			else {
				sum += (10 - sum % 10);
				sum /= 10;
			}
		}
		cout << sum<< endl;
	}
	return 0;
}