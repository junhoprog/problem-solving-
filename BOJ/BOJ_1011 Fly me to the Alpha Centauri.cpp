#include<iostream>
#include<vector>
using namespace std;
int x = 0, cnt = 0, k = 0;
long long int y = 0, r = 0;

void move(long long int r)
{
	cnt = 0;
	for (long long int i = 1; i < y; i++)
	{
		if (r<i*i)
		{
			k = i - 1;
			break;
		}
	}
	cnt = 2 * k - 1;
	r = r - k * k;
	if (r % k == 0)
	{
		cnt += r / k;
	}
	else {
		cnt += r / k + 1;
	}
}

int main()
{
	vector<int>v;
	//k�� ������ ���ٸ� ������ k-1�Ǵ�k, k+1(ó���� -1(�ǹ̾���),0,1)
	//y������ �����ϱ� �ٷ� ������ �̵��Ÿ��� 1�����̾����.
	//x����y���� �ּ�Ƚ��

	int t;
	cin >> t;
	while (t != 0)
	{
		cin >> x >> y;
		if (y - x <= 3)
		{
			v.push_back(y-x);
			t--;
			cnt = 0;
			continue;
		}
		move(y-x);
		v.push_back(cnt);
		t--;
		cnt = 0;
	}
	for (int i = 0; i < v.size(); i++)
	{
		cout << v[i] << endl;
	}

	return 0;
}