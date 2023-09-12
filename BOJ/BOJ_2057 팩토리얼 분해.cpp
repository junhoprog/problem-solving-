#include<iostream>
#include<vector>
using namespace std;
int main()
{
	ios::sync_with_stdio(0);
	cin.tie(0);
	//정수N이 주어졌을 때 이 수를 서로다른 M개의 팩토리얼의 합으로 나타낼 수 있는지 알아내는 프로그램
	//2=0!+1!(서로 다른 정수로 나타낼 수 있어야함.)
	//
	long long int N,i=0;
	vector<long long int>v;
	
	if (i == 0)
	{
		v.push_back(1);
	}
	for (i = 1; i < 20; i++)
	{
		v.push_back(v[i - 1] * i);
	}
	cin >> N;
	if (N == 0)
	{
		cout << "NO";
	}
	else {
		for (int i = 19; i >= 0; i--)
		{
			if (N >= v[i])
			{
				N -= v[i];
			}//뺀후 남은 숫자로 계속 빼줌
		}
		if (N) cout << "NO";//남으면 no
		else {
			//0이면 yes
			cout << "YES";
		}
	}
}