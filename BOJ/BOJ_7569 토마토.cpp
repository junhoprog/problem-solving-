#include<iostream>
#include<queue>
#include<vector>
using namespace std;
int cnt = 0;

void BFS(queue<pair<int, int>>q,int** box, bool** visited,int N,int M,int H,int t) 
{
	int move_x[6] = { 0,1,0,-1,M,-M };
	int move_y[6] = { 1,0,-1,0,0,0 };
	int x = 0,y=0;
	int tmp = 0;
	int count=t;
	while (!q.empty())
	{
		for (int i = 0; i < count; i++) {
			x = q.front().first;//4
			y = q.front().second;//2
			q.pop();//���ֱ�
			for (int i = 0; i < 6; i++) //�� �����°� �����ϱ�
			{
				if (x + move_x[i] < 0 || x + move_x[i] >= M*H || y + move_y[i] < 0 || y + move_y[i] >= N)
				{
					continue;
				}
				if (x % M == 0 && i==3)
				{
					continue;
				}
				else if (x % M == M - 1&&i==1)
				{

					continue;
				}
				if (box[x + move_x[i]][y + move_y[i]] == 0 && visited[x + move_x[i]][y + move_y[i]] == 0)
				{
					//������ġ(1)���� �����¿찡 0�̸鼭, �湮�������� ������ ��.
					box[x + move_x[i]][y + move_y[i]] = 1;//�� ��ġ�� 1�� ������ְ�
					visited[x + move_x[i]][y + move_y[i]] = 1;//�湮 Ȯ��
					q.push(make_pair(x + move_x[i], y + move_y[i]));//queue�� 1�� ���� ��ġ�� �־��ش�
					tmp++;
				}
			}
		}
		count = tmp;//�ٽ� Ƚ�� �ٲ���.
		tmp = 0;
		cnt++;
	}
	cnt--;
}
int main()
{
	// �������� 0 ���� 1 ����������� ĭ -1
	// ���� �丶����� ������ ���� �ִ� ���� ���� �丶����� ���� �丶�� ����޾� ����.
	// ������ ���� �� �� �� ��
	// 1���� ������ 1�ֺ� 0�� 1�̵�. �ּ� �ϼ� ���ϱ�.
	int N, M,H;
	int t = 0;
	cin >> N >> M>>H;
	int num;
	queue<pair<int, int>>q;

	bool** visited = new bool* [M*H];
	for (int i = 0; i < M*H; i++)
	{
		visited[i] = new bool[N];
	}

	int** box = new int*[M*H];
	for (int i = 0; i < M*H; i++)
	{
		box[i] = new int[N];
	}

	for (int i = 0; i < M*H; i++)
	{
		for (int j = 0; j < N; j++) {
			cin >> num;
			box[i][j] = num;
			visited[i][j] = 0;
			if (num == 1)
			{
				q.push(make_pair(i,j));
				visited[i][j] = 1;
				t++;
			}
		}
	}

		BFS(q, box,visited, N, M,H,t);

		for (int i = 0; i < M*H; i++)
		{
			for (int j = 0; j < N; j++)
			{
				if (box[i][j] == 0)//1���� ���������ִٸ�
				{
					cout << -1;
					return 0;
				}
			}
		}
		cout << cnt;

		for (int i = 0; i < M*H; i++) {
			delete[] box[i];
		}
		delete[] box;

		for (int i = 0; i < M; i++) {
			delete[] visited[i];
		}
		delete[] visited;
	return 0;
}