#include<iostream>
#include<vector>
using namespace std;
int main()
{
	ios::sync_with_stdio(0);
	cin.tie(0);
	//����N�� �־����� �� �� ���� ���δٸ� M���� ���丮���� ������ ��Ÿ�� �� �ִ��� �˾Ƴ��� ���α׷�
	//2=0!+1!(���� �ٸ� ������ ��Ÿ�� �� �־����.)
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
			}//���� ���� ���ڷ� ��� ����
		}
		if (N) cout << "NO";//������ no
		else {
			//0�̸� yes
			cout << "YES";
		}
	}
}