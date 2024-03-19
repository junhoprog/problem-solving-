#include<iostream>
using namespace std;
int main()
{
	int N, M;
	cin >> N >> M;

	//나이트가 갈 수 있는 방향은 오른쪽 방향밖에 없기때문에 세로의 어느정도 크기와 함께 가로만 고려하면된다.
	if (N ==2)//위 아래로 갈 수 없음
	{
		if (1<=M&& M<= 2) { cout << 1; }//이동 가능한 경우가 없음
		else if (3 <= M && M <= 4) { cout << 2; }//가로로 한번이동
		else if (5 <= M && M <= 6) { cout << 3; }//두번이동
		else if (7 <= M)//3번 이상
		{
			cout << 4;
		}
	}
	else if (N == 1)//아무대도 갈 수 없음
	{
		cout << 1;
	}
	else {
		if (M == 1) { cout << 1; }//아무대도 갈 수 없음
		else if (M == 2) { cout << 2; }// 위 아래중 하나
		else if (M == 3) { cout << 3; }//위 아래중 둘
		else if (4 <= M && M <= 6) { cout << 4; }//위 아래 중 셋
		else {
			cout << M - 2;///4번 이상부터는 한번씩 사용해야하기 때문에 규칙을 찾음 현재 위치를 포함한 이동한 갯수를 계산
		}
	}
	
	return 0;
}