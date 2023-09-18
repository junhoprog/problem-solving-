#include<iostream>
#include<vector>
#include<cmath>
using namespace std;
int x_move[4] = { 0,1,0,-1 };
int y_move[4] = { 1,0,-1,0 };

int main()
{
	int N, K, mid;
	int x, y;
	int result_x, result_y;
	cin >> N;
	cin >> K;

	int** map = new int* [N];
	for (int i = 0; i < N; i++)
	{
		map[i] = new int[N];
	}//N*N
	mid = N / 2;
	if (N % 2 == 0)//4 2 1
	{
		x = mid; y = mid - 1;//4->2,1 짝수일 때 1위치
	}
	else {
		x = mid; y = mid;//5->2,2//홀수일 때 1위치
	}
	// (4,4)자리가 되게 마지막에 +1 좌표 4->2,1  5-> 2,2
	//1부터 시작해서 위 오 아래 왼순으로 cnt

	int index = 0;
	int count = 0;
	int cnt = 1;
	map[x][y] = 1;
	if (map[x][y] == K)
	{
		result_x = x + 1;
		result_y = y + 1;
	}
	int num = 1;
	//cout << x << " " << y << " " << num << endl;
	num = 2;
	int i = 0;
	x = x - 1;
	int t = 1;
	map[x][y] = num;//고정 2
	if (num == K)
	{
		result_x = x + 1;
		result_y = y + 1;
	}
	//cout << x << " " << y << " " << num << endl;
	num++;
	while (1) {
		count = 0;// 이동횟수
		//전체N*N만큼 돌기위한 반복문
		while (1)
		{
			i = 0;
			//3번 위 오 아 왼 돌리기 위한 반복문
			while (i < cnt)
			{
				x += x_move[index];
				y += y_move[index];
				map[x][y] = num;
				//cout << x << " " << y << " " << map[x][y] << endl;
				if (num == K)
				{
					result_x = x + 1;
					result_y = y + 1;
				}
				num++;
				i++;
			}
			count++;
			if (count == 2)
			{

				//한번더 이동 후
				x += x_move[index];
				y += y_move[index];
				if (x > N - 1 || y > N - 1 || x < 0 || y < 0)
				{
					t = 0;
					break;
					//맨끝자락일 때
				}
				map[x][y] = num;
				//cout << x << " " << y << " " << map[x][y] << endl;
				if (num == K)
				{
					result_x = x + 1;
					result_y = y + 1;
				}
				num++;
				index++;
				if (index > 3)
				{
					index = 0;
				}
				break;
			}
			index++;
			if (index > 3)
			{
				index = 0;
			}
		}
		cnt++;
		if (t == 0)
		{
			break;
		}
		if (x > N - 1 || y > N - 1 || x < 0 || y < 0)
		{

			break;
			//맨끝자락일 때
		}
	}
	for (int i = 0; i < N; i++)
	{
		for (int j = 0; j < N; j++)
		{
			cout << map[i][j] << " ";
		}
		cout << endl;
	}
	cout << result_x << " " << result_y;
	return 0;
}