#include<iostream>
#include<vector>
#include<algorithm>

using namespace std;
int main()
{
	int N,x,y,cnt=1;
	cin >> N;
	vector<pair<int, int>>v;//시작과 끝 기록하려고

	for (int i = 0; i < N; i++)
	{
		cin >> x >> y;
		v.push_back(make_pair(y, x));
	}
	//결국엔 끝나는시간 기준으로 하기 때문에 끝나는 시간을 y를 앞으로해서 소트를 할 수 있게 만듦
	sort(v.begin(), v.end());
	//y기준으로 오름차순.

	int start=v[0].second, end=v[0].first;

	for (int i = 1; i < N; i++)
	{
		if (end <= v[i].second) //시작시간이 끝나는시간보다 커지게되면 담 회의시작이니까.
		{
			cnt++;
			end = v[i].first;//마지막시간을 교체.
		}
	}
	cout << cnt;
	return 0;
}
