#include<iostream>
using namespace std;
int main()
{
	long long int s;
	cin >> s;
	int cnt = 0;
	long long int sum = 0;
	//서로다른 n개가 합해져서 s가 될때 자연수 n의 최대값(최대로 만들 수 있는 갯수)
	for (int i = 1;; i++)
	{
	
		sum += i;
		
		if (sum > s)
		{
			sum -= i;
			cnt--;
			break;
		}
		cnt++;
	}
	cout << cnt+1;
	return 0;
}