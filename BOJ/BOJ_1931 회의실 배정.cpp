#include<iostream>
#include<vector>
#include<algorithm>

using namespace std;
int main()
{
	int N,x,y,cnt=1;
	cin >> N;
	vector<pair<int, int>>v;//���۰� �� ����Ϸ���

	for (int i = 0; i < N; i++)
	{
		cin >> x >> y;
		v.push_back(make_pair(y, x));
	}
	//�ᱹ�� �����½ð� �������� �ϱ� ������ ������ �ð��� y�� �������ؼ� ��Ʈ�� �� �� �ְ� ����
	sort(v.begin(), v.end());
	//y�������� ��������.

	int start=v[0].second, end=v[0].first;

	for (int i = 1; i < N; i++)
	{
		if (end <= v[i].second) //���۽ð��� �����½ð����� Ŀ���ԵǸ� �� ȸ�ǽ����̴ϱ�.
		{
			cnt++;
			end = v[i].first;//�������ð��� ��ü.
		}
	}
	cout << cnt;
	return 0;
}
