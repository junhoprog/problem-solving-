#include<iostream>
#include<string>
using namespace std;
int main()
{
	int t;
	cin >> t;
	int days[13] = { 0,31,28,31,30,31,30,31,31,30,31,30,31 };
	for (int i = 1; i <= t; i++)
	{
		string s = "";
		cin >> s;
		string year = "";
		string mon = "";
		string day = "";
		for (int j = 0; j < 4; j++)
		{
			year += s[j];
		}
		for (int j = 4; j < 6; j++)
		{
			mon += s[j];
		}
		for (int j = 6; j < 8; j++)
		{
			day += s[j];
		}
		int m = stoi(mon);
		int d = stoi(day);

		cout << "#" << i << " ";
		if (m > 12 || m < 1)
		{
			cout << -1 << endl;
		}
		else {
			if (d > days[m] || d == 0)
			{

				cout << -1 << endl;
			}
			else {
				cout << year << "/" << mon << "/" << day << endl;
			}
		}
	}
	return 0;
}