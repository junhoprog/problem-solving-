#include<iostream>
#include<vector>
#include<set>
using namespace std;
int solution(vector<int>topping)
{
	int answer = 0;

	vector<int>v(10001,0);//형
	vector<int>v2(10001,0);//동생

	set<int>s;//형의 토핑 개수
	set<int>s2;//동생의 토핑 개수
	for (int i = 0; i < topping.size(); i++)
	{
		v2[topping[i]]++;//동생에게 모든 토핑을 먼저 채운다.
		s2.insert(topping[i]);//동생은 모든 토핑을 가진 상태
	}

	for (int i = 0; i < topping.size(); i++)//모든 토핑을 확인한다.
	{
		//앞에서부터 토핑을 나누면서 확인한다.
		v[topping[i]]++;//형의 토핑 개수를 추가하는 동시에 동생의 토핑은 감소
		v2[topping[i]]--;
		if (v2[topping[i]] == 0)//해당 토핑개수가 0이 된다는건 토핑이 없는 것이기 때문에 집합에서 제거
		{
			s2.erase(topping[i]);
		}
		s.insert(topping[i]);//형의 토핑은 추가함

		if (s.size() == s2.size())//형제의 토핑 개수가 같아지면 answer증가
		{
			answer++;
		}
	}

	return answer;
}
int main()
{
	vector<int>topping = { 1,2,3,1,4 };

	cout << solution(topping);
	return 0;
}