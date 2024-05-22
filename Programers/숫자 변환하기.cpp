#include <string>
#include <vector>
#include <iostream>
#include <queue>
using namespace std;

int solution(int x, int y, int n) {

	int answer = 0
	int temp;// q에 있는 값을 temp에 담음
	vector<int>DP(y+1,1000001);
	queue<int>q;//q에 현재 숫자로부터 나올 수 있는 모든 다음 경우를 넣을 것
	bool flag = false;//성공 실패여부판단
	q.push(y);//첫숫자를 넣어서 다음 반복문 조건에 맞춤
	DP[y] = 0;//처음 숫자는 이동이없으니 0으로

	while (!q.empty())//q가 모두 비게 되면 종료
	{
		temp = q.front();//temp에 q끝 숫자 담고
		q.pop();
		if (temp < 0)//index넘어가는거 확인
		{
			continue;
		}

		if (temp == x)//만약 발견했으면
		{
			answer = DP[temp];//해당 횟수를 answer에 넣고 반복문 끝냄
			flag = true;
			break;
		}

		else {//발견못하면 현재 숫자에 3가지 조건 모두 확인하면서 q에 넣어줌
			if (temp-n>0&&DP[temp-n]>DP[temp]+1)
			{
				DP[temp - n] = DP[temp] + 1;
				q.push(temp - n);
			}
			if (temp%2==0&&temp/2 > 0 && DP[temp/2] > DP[temp] + 1)
			{
				DP[temp/2] = DP[temp] + 1;
				q.push(temp/2);
			}
			if (temp%3==0&&temp/3 > 0 && DP[temp/3] > DP[temp] + 1)
			{
				DP[temp/3] = DP[temp] + 1;
				q.push(temp/3);
			}
		}

	}
	if (flag == false)//false
	{
		answer = -1;
	}
	return answer;
}
int main()
{
	cout<<solution(10, 40, 5);
	return 0;
}