#include<iostream>
#include<vector>
#include<stack>
using namespace std;
int move_x[4] = {0,-1,0,1};
int move_y[4] = { 1,0,-1,0 };
int cnt = 0;
int N, M,K;
//���� ,���� ,�ɾ����ִ� ��ġ����
stack<pair<int,int>>S;

void dfs(int x, int y,int **map,bool**check)
{
	for (int i = 0; i < 4; i++)
	{
		if (x + move_x[i] >= M || y + move_y[i] >= N|| x + move_x[i]<0|| y + move_y[i]<0)
		{
			continue;
		}
		//������ġ x,y
		if (check[x + move_x[i]][y + move_y[i]] == 1 && map[x + move_x[i]][y + move_y[i]] == 1)//�̹� �湮�� ������ġ���  
		{
			continue;
		}
		else if (check[x + move_x[i]][y + move_y[i]] == 0 && map[x + move_x[i]][y + move_y[i]] == 1) {
			//���ÿ� �ְ�
			S.push(make_pair(x, y));//���� ��ġ�� push
			check[x + move_x[i]][y + move_y[i]] = 1;
			dfs(x + move_x[i], y + move_y[i],map,check);
			//�Լ�(�̵���Ų�� �־���)

		}//�湮�������� ������ġ���
		else {
			continue;
			//0�� ��ġ
		}
		if (i == 3)
		{
			S.pop();//���� ��ġ x,y�� �� ���ұ� ������ ���� �� �ڿ� ��
		}
	}

}

int main()
{
	int T;
	int x, y;
	cin >> T;

	vector<int>v;
	x = 0; y = 0;

	while (T > 0)
	{
		cnt = 0;
		cin >> M >> N >> K;

		int** map = new int* [M];
		for (int i = 0; i < M; i++)
		{
			map[i] = new int[N];
		}//��ü ��ũ��

		bool** check = new bool* [M];
		for (int i = 0; i < M; i++)
		{
			check[i] = new bool[N];
		}//�湮���θ� Ȯ���� ��
		//M*N�� ����
		for (int i = 0; i < M; i++)
		{
			for (int j = 0; j < N; j++)
			{
				map[i][j] = 0;
				check[i][j] = false;
			}
		}//�ʱ�ȭ

		for (int i = 0; i < K; i++) {
			cin >> x >> y;
			map[x][y] = 1;
		}
		x = 0, y = 0;
		for (int i = 0; i < M; i++)
		{
			for (int j = 0; j < N; j++)
			{
				if (check[i][j] == 0 && map[i][j] == 1)
				{
					dfs(i, j, map, check);
					cnt++;
				}
			}
		}
		T--;
		v.push_back(cnt);
		for (int i = 0; i < M; i++)
		{
			delete[] map[i];
		}
		delete[] map;

		for (int i = 0; i < M; i++)
		{
			delete[] check[i];
		}
		delete[] check;
	}
	for (int i = 0; i < v.size(); i++)
	{
		cout << v[i] << endl;
	}
}