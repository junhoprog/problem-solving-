#include<iostream>
#include<string>
#include<algorithm>

using namespace std;

int Search(string s1, string s2)
{
	int** DP = new int* [s1.length()+1];//2차원 DP생성
	for (int i = 0; i < s1.length()+1; i++)
	{
		DP[i] = new int[s2.length()+1];
	}

	for (int i = 0; i <= s1.length(); i++)
	{
		for (int j = 0; j <= s2.length(); j++)
		{
			DP[i][j] = 0;//초기화
		}
	}

	for (int i = 1; i <= s1.length(); i++)
	{
		for (int j = 1; j <= s2.length(); j++)
		{
			if (s1[i-1] == s2[j-1])//같다면
			{
				DP[i][j] = DP[i - 1][j - 1] + 1;//왼쪽 대각선의 1증가시킨 값이 현재의 값이 됨
			}
			else {
				DP[i][j] = max(DP[i - 1][j], DP[i][j - 1]);//다르다면 왼쪽 또는 위쪽에 있는 값중 최대값가져옴
			}
		}
	}

	return DP[s1.length()][s2.length()];//마지막값이 최대LCS개수임
}
int main()
{
	string s1, s2;
	cin >> s1 >> s2;

	cout<<Search(s1,s2);
	return 0;
}