#include <iostream>
#include <stack>
#include <vector>

using namespace std;

int main() {

	ios_base::sync_with_stdio(0);
	cin.tie(0);
	stack<int> s;
	vector<int>v(80001);
	int num;
	long long ans = 0;

	cin >> num;

	for (int i = 0; i < num; i++)
	{
		cin >> v[i];
	}
	for (int i = 0; i < num; i++) {
		while (!s.empty() && s.top() <= v[i])//��ų� s�� ž�� ���� ������ �۰ų� ���� ��
		{
			s.pop();
		} //v[i]�� �� �� ���� �ǹ��� �� pop
		//ó���� �׳� �Ѿ��
		ans += (long long int)s.size();//�����ִ� ���ð�����ŭ ������(�̰��� �� �� �մ� ����)
		s.push(v[i]);//ó���� �ֱ�
	}
	cout << ans << '\n';
}
/*
#include<iostream>
using namespace std;
int main()
{
	int N, K;
	cin >> N >> K;
	int arr[200001];
	for (int i = 0; i < 200001; i++)
	{
		arr[i] = 1000000;
	}
	arr[N] = 0;
	if (N > K) 
	{
		int cnt = 0;
		for (int i = N; i > K; i--)
		{
			cnt++;
			//K����
		}
		cout << cnt;
		return 0;
	}

	for (int i = N; i <=100000; i++)
	{

		if (arr[2 * i] > arr[i] + 1)
		{
			arr[2 * i] = arr[i] + 1;
		}
		if (arr[i + 1] > arr[i] + 1)
		{
			arr[i + 1] = arr[i] + 1;
		}

		if (arr[i - 1] > arr[i] + 1)
		{
			arr[i - 1] = arr[i] + 1;
		}
	}

	for (int i = N; i <= 100000; i++)
	{

		if (arr[2 * i] > arr[i] + 1)
		{
			arr[2 * i] = arr[i] + 1;
		}
		if (arr[i + 1] > arr[i] + 1)
		{
			arr[i + 1] = arr[i] + 1;
		}

		if (arr[i - 1] > arr[i] + 1)
		{
			arr[i - 1] = arr[i] + 1;
		}

	}
	cout << arr[K];
	return 0;
}*/