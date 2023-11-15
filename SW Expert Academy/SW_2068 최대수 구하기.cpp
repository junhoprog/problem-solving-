#include<iostream>
using namespace std;
int main()
{
	int T,max,x;
	cin >> T;
	for (int i = 1; i <= T; i++)
	{
		cin >> x;
		max = x;
		for (int j = 1; j < 10; j++)
		{
			cin >> x;
			if (max < x)
			{
				max = x;
			}
		}
		
		cout <<"#"<<i<<" "<< max << endl;
	}
	return 0;
}