#include<iostream>
#include<vector>
using namespace std;
int main()
{
	vector<long long int>DP(1000001, 0);
	DP[1] = 1;
	DP[2] = 2;
	DP[3] = 4;
	for (int i = 4; i < 1000001; i++)
	{
		DP[i] = (DP[i - 1] + DP[i - 2] + DP[i - 3]) % 1000000009;
	}
	int t;
	cin >> t;
	int n;
	for (int i = 0; i < t; i++)
	{
		cin >> n;
		cout << DP[n]  <<endl;
	}
	return 0;
}
/*
3-> 111 12 21 3  -  4
4-> 1111 112 121 211 22 31 13  -  7
5-> 11111 1112 1121 1211 2111 221 122 212 311 131 113 32 23  - 13
6-> 111111 11112 11121 11211 12111 21111 2211 2121 2112 
	1221 1212 1122 222 3111 1311 1131 1113 123 132 213 231 312 321 33  -  24
7-> 44
DP[i]=DP[i-1]+DP[i-2]+DP[i-3]
*/