#include<iostream>
using namespace std;
void Game(int *DP,int*stair,int N)
{
	for (int i = 4; i <= N; i++)
	{
		DP[i] = max(DP[i - 3] + stair[i - 1], DP[i - 2]) + stair[i];
		/*끝지점을 기준으로 했을 때 끝으로 도착하기위해선 N - 1또는 N - 2에서 이동을 해야한다.
		N-2같은 경우 1칸 이동후 2칸 2칸이동후 2칸 모두 상관없기 때문에 DP[N-2]에 저장된 값과 현재를 더하면된다.
		N-1은  이미 2칸을 차지한 상태기때문에 N-2는 당연히 이동할 수 없기에 2칸 이동 후 1칸이동해야 
		연속된 계단을 이용하지않고 이동할 수 있게 된다. 그렇기 때문에 위의 점화식이 나온다.
		/1 3 4/ 2 4
		*/
	}
}
int main()
{
	int N;
	cin >> N;
	int* stair = new int[N+1];
	int DP[301] = { 0, };
	for (int i = 1; i <= N; i++)
	{
		cin >> stair[i];//입력받기
	}
	DP[1] = stair[1];
	DP[2] = stair[1] + stair[2];//stair[2]가 포함되어있기때문에 1 1이 더 최대
	DP[3] = max(stair[1] + stair[3], stair[2] + stair[3]);//1 3또는 2 3으로 이동 최대값
	Game(DP,stair,N);//4부터 규칙을 찾음
	
	cout << DP[N];
	return 0;
}