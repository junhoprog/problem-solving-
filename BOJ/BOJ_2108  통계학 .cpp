#include<iostream>
#include<vector>
#include<algorithm>

using namespace std;
int main()
{
	//A��� ���� B����� ���  |A-B|�� ��ġȭ  N���� ������� �Ҹ����� �� ���� �ּҷ� �ϸ鼭 �л����� ����� �ű������
	int N,x;
	vector<int>v;
	cin >> N;
	for (int i = 0; i < N; i++)
	{
		cin >> x;
		v.push_back(x);
	}
	sort(v.begin(), v.end());
	long long int sum = 0;
	for (int i = 0; i < N; i++)
	{
		if (i + 1 - v[i] < 0)
		{
			sum += -1 * (i + 1 - v[i]);
		}
		else {
			sum += i + 1 - v[i];
		}
	}
	cout << sum;
	return 0;
		
}