#include<iostream>
using namespace std;
int main()
{
	int end, start;
	cin >> end >> start;
	int cnt = 0;
	for (int i = start; i <= end; i++)
	{
		cnt++;
	}
	cout << cnt;
}