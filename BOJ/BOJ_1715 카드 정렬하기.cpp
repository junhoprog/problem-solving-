#include<iostream>
#include<queue>
using namespace std;
int main()
{
	priority_queue<int,vector<int>,greater<int>>q;//우선순위 큐-> queue에서 알아서 sort를 해줌
	int n, x;
	cin >> n;

	for (int i = 0; i < n; i++)
	{
		cin >> x;
		q.push(x);//q에 모든 값을 먼저 넣고
	}
	if (n == 1)//n이 1이면
	{
		cout << 0;
		return 0;//더한게 없으니 0
	}

	int left, right;// 왼 + 오
	long long sum = 0;//합의 크기가 long long 일수도있으니
	while (!q.empty())//q가 빌때까지 수행
	{
		if (q.size() == 1)//q사이즈가 1일때-> 10+20+30+40->30+30+40->40+60->100(한개 남음->끝난 상황)
		{
			cout << sum;//현재 순간에서의 sum출력
			return 0;
		}
		left = q.top();//left에 qtop반환 후
		q.pop();//없애고
		if (!q.empty())//비지 않았다면
		{
			right = q.top();//right에 qtop 반환 후
			q.pop();//없애고
			q.push(left + right);//두 합을 q에 넣어줌
			sum += left + right;//두 합을 sum에 더함
		}
	}
}