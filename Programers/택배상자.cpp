#include <string>
#include <vector>
#include<iostream>
#include<stack>
using namespace std;

int solution(vector<int> order) {
	int answer = 0;
	int size = order.size();
	stack<int>s;//맨 마지막에 들어온게 나가야하니까 스택 사용

	int seq = 1;//현재 순서를 나타낼 변수

	for (int i = 0; i < size; i++)//모든 주문을 확인
	{
		if (order[i] == seq)//다음 컨테이너벨트가 현재 순서면 택배에 실음
		{
			answer++;
			seq++;//1개 증가
		}
		else if (!s.empty() && s.top() == order[i])//비어있으면 오류생기니까 비어있지 않으면서 스택 맨 끝 숫자라면
		{
			answer++;
			s.pop();
		}
		else if (seq < order[i])//만약 현재 순서보다 큰 숫자가 다음 순서면 그 전까지의 택배를 모두 스택에 담음
		{
			for (int j = seq; j < order[i]; j++)//스택에 담고
			{
				s.push(j);
			}
			seq = order[i] + 1;//다음 순서로 seq를 옮겨줌
			answer++;
		}
		else {//만약 컨테이너, 서브 벨트 모두 없다면 종료
			break;
		}
	}

	return answer;
}

/*
순서대로 트럭에 실어야한다.
1 2 3 4 5로 온다
이때 트럭에 넣어야하는 순서는
4 3 1 2 5 일때 order[i]를 만날 수 있는가
4 5 3 2 1
4 3 6 5 2 1
1 2 3
seq보다 크면 스택에 넣기
*/
//seq=4

int main()
{
	vector<int>order = { 4,3,6,5,2,1 };
	cout << solution(order);
	return 0;
}