#include<iostream>
using namespace std;
void Game(int *DP,int*stair,int N)
{
	for (int i = 4; i <= N; i++)
	{
		DP[i] = max(DP[i - 3] + stair[i - 1], DP[i - 2]) + stair[i];
		/*�������� �������� ���� �� ������ �����ϱ����ؼ� N - 1�Ǵ� N - 2���� �̵��� �ؾ��Ѵ�.
		N-2���� ��� 1ĭ �̵��� 2ĭ 2ĭ�̵��� 2ĭ ��� ������� ������ DP[N-2]�� ����� ���� ���縦 ���ϸ�ȴ�.
		N-1��  �̹� 2ĭ�� ������ ���±⶧���� N-2�� �翬�� �̵��� �� ���⿡ 2ĭ �̵� �� 1ĭ�̵��ؾ� 
		���ӵ� ����� �̿������ʰ� �̵��� �� �ְ� �ȴ�. �׷��� ������ ���� ��ȭ���� ���´�.
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
		cin >> stair[i];//�Է¹ޱ�
	}
	DP[1] = stair[1];
	DP[2] = stair[1] + stair[2];//stair[2]�� ���ԵǾ��ֱ⶧���� 1 1�� �� �ִ�
	DP[3] = max(stair[1] + stair[3], stair[2] + stair[3]);//1 3�Ǵ� 2 3���� �̵� �ִ밪
	Game(DP,stair,N);//4���� ��Ģ�� ã��
	
	cout << DP[N];
	return 0;
}