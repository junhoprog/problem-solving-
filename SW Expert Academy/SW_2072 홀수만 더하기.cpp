#include<iostream>
using namespace std;
int main()
{
	int T;
	cin >> T;
	for (int i = 1; i <= T; i++)
	{
		cout << "#" << i << " ";
		int sum = 0;
		for (int k = 0; k < 10; k++)
		{
			int n;
			cin >> n;
			if (n % 2 == 1)
			{
				sum += n;
			}
		}
		cout << sum << endl;
	}
	return 0;

}