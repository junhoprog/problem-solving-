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
		while (!s.empty() && s.top() <= v[i])//비거나 s의 탑이 들어온 값보다 작거나 같을 때
		{
			s.pop();
		} //v[i]를 볼 수 없는 건물은 다 pop
		//처음엔 그냥 넘어가기
		ans += (long long int)s.size();//남아있는 스택개수만큼 더해줌(이것이 볼 수 잇는 양임)
		s.push(v[i]);//처음값 넣기
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
			//K까지
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