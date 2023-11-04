#include<iostream>
#include<string>
#include<algorithm>

using namespace std;

int Search(string s1, string s2)
{
	int** DP = new int* [s1.length()+1];//2���� DP����
	for (int i = 0; i < s1.length()+1; i++)
	{
		DP[i] = new int[s2.length()+1];
	}

	for (int i = 0; i <= s1.length(); i++)
	{
		for (int j = 0; j <= s2.length(); j++)
		{
			DP[i][j] = 0;//�ʱ�ȭ
		}
	}

	for (int i = 1; i <= s1.length(); i++)
	{
		for (int j = 1; j <= s2.length(); j++)
		{
			if (s1[i-1] == s2[j-1])//���ٸ�
			{
				DP[i][j] = DP[i - 1][j - 1] + 1;//���� �밢���� 1������Ų ���� ������ ���� ��
			}
			else {
				DP[i][j] = max(DP[i - 1][j], DP[i][j - 1]);//�ٸ��ٸ� ���� �Ǵ� ���ʿ� �ִ� ���� �ִ밪������
			}
		}
	}

	return DP[s1.length()][s2.length()];//���������� �ִ�LCS������
}
int main()
{
	string s1, s2;
	cin >> s1 >> s2;

	cout<<Search(s1,s2);
	return 0;
}