#include<iostream>
using namespace std;
int main()
{
	int arr[5],cnt=0,min=0,t;
	for (int i = 0; i < 5; i++)
	{
		cin >> arr[i];
		if (min == 0 || arr[i] < min) min = arr[i];
	}
	t = min;
	while (cnt < 3)
	{
		cnt = 0;
		t++;
		for (int i = 0; i < 5; i++)
		{
			if (t % arr[i] == 0)
			{
				cnt++;
			}
		}
	}
	cout << t;
	return 0;
}