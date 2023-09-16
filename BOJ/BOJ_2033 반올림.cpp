#include<iostream>
#include<math.h>
using namespace std;
int main()
{
	long long int N,result=0,t;
	int cnt=1;
	cin >> N;
	result = N;

	while (1)
	{
		t = pow(10, cnt);
		//cout << N<<" "<<t << endl;
		if (N > t&& (N% t>=0&&N% t <5*pow(10,cnt-1)))
		{
			N -= (N % t);
		}
		else if (N > t && (N % t > 4 * pow(10, cnt - 1) && N % t < 10 * pow(10, cnt - 1)))
		{
			N += (t - (N % t));
		}
		else {
			break;
		}
		cnt++;
	}
	cout << N;
	return 0;
}