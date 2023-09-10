#include<iostream>
#include<deque>

using namespace std;
int main()
{
	//큐에서 3가지연산
	//1. 첫번째원소를 뽑아낸다. 이 연산 수행하면 원래 큐의 원소가 a1..ak에서 a2...ak와같이된다.(맨앞에 a1이 새로생긴다.)
	//2. 왼쪽으로 한칸 이동 a1...ak가 a2...aka1이 된다.
	//3.오른쪽으로 한칸 이동 a1...ak가 aka1...ak-1이됨.

	//처음 포함되어있던 수 N 지민이가 뽑아내려고하는 원소의 위치 주어짐(처음 큐에서의 위치).
	//순서대로 뽑을 때 드는 2번,3번연산의 최솟값 출력

	deque<int>d;
	int N, M,x,count=0,index=0;
	cin >> N >> M;
	for (int i = 1; i <= N; ++i)
	{
		d.push_back(i);
	}
	while (M != 0)
	{
		cin >> x;
		for (int i = 0; i < d.size(); i++)
		{
			if (d[i] == x)
			{
				index = i;//현재위치를 index에 첨돌아갈 때 담음
				break;
			}
		}

		if (index < d.size() - index)
		{
			//현재 위치 기준으로 전체 길이에서 왼쪽 오른쪽 구분을 남은 길이에 맞춰 정함
			while (1)
			{
				if (d.front() == x)
				{
					d.pop_front();
					break;
				}
				count++;
				//앞에 있는 것을 뒤로 보내면서 맨 앞만 비교를 함.
				d.push_back(d.front());
				d.pop_front();
			}
		}
		else {
			while (1)
			{
				if (d.front() == x)
				{
					d.pop_front();
					break;
				}
				count++;
				//뒤에있는 것을 앞에 넣어줌
				d.push_front(d.back());
				d.pop_back();
			}
		}
		M--;
	}
	cout << count;
	return 0;
}