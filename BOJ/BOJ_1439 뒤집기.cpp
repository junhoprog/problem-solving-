#include<iostream>
#include<string>
using namespace std;
int main()
{
	string s;
	cin >> s;
	int cnt1 = 0, cnt2 = 0;
	bool check = 0;

		for (int i = 0; i < s.length(); i++)
		{
			if (check == 0 && '0' == s[i])
			{
				check = 1;
				cnt1++;
			}
			else if (check == 1 && '0' == s[i])//연속
			{
				continue;
			}
			else if (check == 1 && '0' != s[i])
			{
				check = 0;
			}
		}
		check = 0;
		for (int i = 0; i < s.length(); i++)
		{
			if (check == 0 && '1' == s[i])
			{
				check = 1;
				cnt2++;
			}
			else if (check == 1 && '1' == s[i])//연속
			{
				continue;
			}
			else if (check == 1 && '1' != s[i])
			{
				check = 0;
			}
		}
		cout << min(cnt1, cnt2);
		return 0;
}