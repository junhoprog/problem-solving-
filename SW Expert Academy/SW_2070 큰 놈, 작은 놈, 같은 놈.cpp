#include<iostream>
using namespace std;
int main()
{
	int T,x,y;
	cin >> T;
	for (int i = 1; i <= T; i++)
	{
		cin >> x >> y;
		cout << "#" << i << " ";
		if (x == y)
		{
			cout << "=" << endl;
		}
		else if (x < y)
		{
			cout << "<" << endl;

		}
		else if (x > y)
		{
			cout << ">" << endl;

		}
	}
	return 0;
}