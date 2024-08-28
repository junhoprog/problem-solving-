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
		//�� 0 �� 1 �� 2 �� 3  �� 4 �� 5 �� ������ ������ �ٲ𶧸��� �� ���ڵ�� ���� ����
	case 1:
		if (y + 1 >= M)
		{
			is_check = true;
			break;
		}
		//��->0 ��->�� ��->�� ��->��
		//1->0 0->5 5-> 3 3->1
		y++;
		temp = dice[0];
		dice[0] = dice[1];
		dice[1] = dice[3];
		dice[3] = dice[5];
		dice[5] = temp;
		break;

	case 2:
		//����
		if (is_check == true || y - 1 < 0)
		{
			is_check = true;
			break;
		}
		//��->0 ��->�� ��->�� ��->��
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

		//��->0 ��->�� ��->�� ��->��
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

		//��->0 ��->�� ��->�� ��->��
		//2->0 0->4 4->3 3->2
		x++;
		temp = dice[0];
		dice[0] = dice[2];
		dice[2] = dice[3];
		dice[3] = dice[4];
		dice[4] = temp;
		//����
		break;
	}
	//���� �����̵��ϸ鼭 �� ĭ�� �ִ� ���� dice[0]�� �־��ָ��
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
N*M ������ ���� ������ ��ǥ�� (r,c)-> r�� �������κ��� ������ ĭ�� ���� c�� �������κ��� ������ ĭ�� ����
6�� �� 1�� �� 3�� ���� �ٶ󺸰� 2�� ���� ...-> ������ ���ϴ°�.
������ �ִ� ���� ��ǥ(x,y) ���� ó�� �ֻ������� ��� ���� 0'
������ �� ĭ���� ������ �ϳ��� ������ �ִ�. �ֻ��� ������ �� �̵��� ĭ�� �����ִ� ���� 0�̸� �ֻ��� �ٴڸ鿡 �����ִ� ���� ĭ�� �����
0�϶� 0�� �ٴڸ�
�Ǵ�
0�� �ƴϸ� 0�ƴ� ���� �ٴڸ����� �׸��� ĭ�� �����ִ� ���� 0
�� 6�� �ִ� ���� ����Ǵ°�.

 2
413
 5
 6

*/