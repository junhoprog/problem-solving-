#include<iostream>
#include<cmath>
using namespace std;
int main()
{
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	long long int N,num;
	int K,cnt=0;
	
	cin >> N >> K;
	num = N;
	int temp = N;
	int pow_cnt = 0;
	while (temp>0)
	{
		if (temp / 10 == 0)
		{
			break;
		}
		else {
			temp /= 10;
			pow_cnt++;
		}
	}
	//cout << pow_cnt;
	while (cnt != K)
	{
		if (num % K == 0)
		{
			cout << cnt + 1;
			return 0;
		}
		else {
			num %= K;
			num= num* pow(10,pow_cnt+1) + N;//N이 십의자리면 십의자리만큼10의 몇2제곱해야함
			//cout << num<<" ";
		}
		cnt++;
	}
	cout << -1;
	return 0;
}

