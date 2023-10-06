#include<iostream>
#include<vector>
using namespace std;
int main()
{
	int N,x;
	cin >> N;
	vector<int>v;
	for (int i = 0; i < N; i++)
	{
		cin >> x;
		v.push_back(x);
	}
	int sum = 0;

	for (int i = 0; i < v.size(); i++)
	{
		sum += v[i];
	}
	int avg,rem;
	avg = sum/ v.size();//4
	rem = sum % v.size();//2
	sum = 0;
	int cnt = 0;//Å« °¹¼ö

	for (int i = 0; i < v.size(); i++)
	{
		if (v[i] >= avg+1)
		{
			cnt++;//1°³
			sum += v[i] - (avg + 1);//4
			v[i] =(avg + 1);//5 3 3 3
		}
	}
	while (1)
	{
		if (cnt > rem)
		{
			sum++;
			cnt--;
		}
		else if (cnt == rem)
		{
			break;
		}
		else if (cnt < rem)
		{
			cnt++;
		}
	}
	cout << sum;
	return 0;
}