#include<iostream>
#include<string>
using namespace std;

bool check(int i, bool ignore[])
{
	string s = to_string(i);//���簪�� stringȭ ��Ų ��
	for (int j = 0; j < s.length(); j++)
	{
		if (ignore[s[j] - '0']) {//���簪�� ���ڰ� ����ȭ�Ȱ��̱⶧���� �Ͻ������� '0'���༭ ���ڷ� ����
			return false;//���õǾ��ִ� ���ڰ� �Ѱ��� �ִٸ� false
		}
	}
	return true;
}

int main()
{
	int N, M, x, temp;
	int min_cnt = 1000000;
	cin >> N;
	cin >> M;
	bool ignore[10] = { 0, };
	for (int i = 0; i < M; i++)
	{
		cin >> x;
		ignore[x] = true;
	}

	string s = to_string(N);//N�� ��Ʈ������

	min_cnt = abs(N - 100);//��ǥ���� 100���� �����ϱ⶧���� 100��ŭ ���� ���� �ּ� cnt
	for (int i = 0; i < 1000001; i++)
	{
		if (check(i, ignore)) {//���ڿ����� ���ؼ� �������������ľ�
			temp = abs(N - i) + to_string(i).length();//��ǥ������ ���ϰų� ���°�+ ������ ��ư
			min_cnt = min(min_cnt, temp);//���� �ּ�cnt�� ���簪 ���ؼ� ���� ���� Ƚ��
		}
	}
	cout << min_cnt;
	return 0;
}