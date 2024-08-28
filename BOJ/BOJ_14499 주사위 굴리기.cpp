#include<iostream>
#include<vector>
using namespace std;

int N, M, x, y, K;
int map[20][20];

vector<int>orders;
vector<int>dice;

void move(int index)
{
	bool is_check = false;
	int temp = 0;
	switch (index)
	{
		//밑 0 동 1 남 2 위 3  북 4 서 5 로 설정해 방향이 바뀔때마다 이 숫자들로 방향 설정
	case 1:
		if (y + 1 >= M)
		{
			is_check = true;
			break;
		}
		//동->0 밑->서 서->위 위->동
		//1->0 0->5 5-> 3 3->1
		y++;
		temp = dice[0];
		dice[0] = dice[1];
		dice[1] = dice[3];
		dice[3] = dice[5];
		dice[5] = temp;
		break;

	case 2:
		//서쪽
		if (is_check == true || y - 1 < 0)
		{
			is_check = true;
			break;
		}
		//서->0 밑->동 동->위 위->서
		//5->0 0->1 1->3 3->5
		y--;
		temp = dice[0];
		dice[0] = dice[5];
		dice[5] = dice[3];
		dice[3] = dice[1];
		dice[1] = temp;
		break;

	case 3:
		if (is_check == true || x - 1 < 0)
		{
			is_check = true;
			break;
		}

		//북->0 밑->남 남->위 위->북
		//4->0 0->2 2->3 3->4
		x--;
		temp = dice[0];
		dice[0] = dice[4];
		dice[4] = dice[3];
		dice[3] = dice[2];
		dice[2] = temp;
		break;

	case 4:
		if (is_check == true || x + 1 >= N)
		{
			is_check = true;
			break;
		}

		//남->0 밑->북 북->위 위->남
		//2->0 0->4 4->3 3->2
		x++;
		temp = dice[0];
		dice[0] = dice[2];
		dice[2] = dice[3];
		dice[3] = dice[4];
		dice[4] = temp;
		//남쪽
		break;
	}
	//이제 지도이동하면서 그 칸에 있는 값을 dice[0]에 넣어주면됨
	if (is_check == true)
	{
		return;
	}
	else {
		if (map[x][y] != 0)
		{
			dice[0] = map[x][y];
			map[x][y] = 0;
		}
		else {
			map[x][y] = dice[0];
		}
		cout << dice[3] << endl;
	}
}

int main()
{
	cin >> N >> M >> x >> y >> K;
	vector<int>orders;
	for (int i = 0; i < N; i++)
	{
		for (int j = 0; j < M; j++)
		{
			cin >> map[i][j];
		}
	}

	for (int i = 0; i < K; i++)
	{
		int order;
		cin >> order;
		orders.push_back(order);
	}

	for (int i = 0; i < 6; i++)
	{
		dice.push_back(0);
	}

	for (int i = 0; i < K; i++)
	{
		move(orders[i]);
	}

	return 0;
}
/*
N*M 지도가 존재 지도의 좌표는 (r,c)-> r는 북쪽으로부터 떨어진 칸의 개수 c는 서쪽으로부터 떨어진 칸의 개수
6이 밑 1이 위 3이 동쪽 바라보고 2가 북쪽 ...-> 방향을 말하는것.
놓여져 있는 곳의 좌표(x,y) 가장 처음 주사위에는 모든 면이 0'
지도의 각 칸에는 정수가 하나씩 쓰여져 있다. 주사위 굴렸을 때 이동한 칸에 쓰여있는 수가 0이면 주사위 바닥면에 쓰여있는 수가 칸에 복사됨
0일때 0이 바닥면
또는
0이 아니면 0아닌 수가 바닥면으로 그리고 칸에 쓰여있는 수는 0
즉 6이 있는 값이 복사되는것.

 2
413
 5
 6

*/