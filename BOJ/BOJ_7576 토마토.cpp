#include<iostream>
#include<queue>

using namespace std;
int cnt = 0;
int move_x[4] = {0,1,0,-1};
int move_y[4] = {1,0,-1,0};

void BFS(queue<pair<int, int>>q,int** box, bool** visited,int N,int M,int t) 
{
	int x = 0,y=0;
	int tmp = 0;
	int count=t;
	while (!q.empty())
	{
		for (int i = 0; i < count; i++) {
			x = q.front().first;
			y = q.front().second;
			q.pop();//���ֱ�
			for (int i = 0; i < 4; i++)
			{
				if (x + move_x[i] < 0 || x + move_x[i] >= M || y + move_y[i] < 0 || y + move_y[i] >= N)
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
	int N, M;
	int t = 0;
	cin >> N >> M;
	int num;
	queue<pair<int, int>>q;

	bool** visited = new bool* [M];
	for (int i = 0; i < M; i++)
	{
		visited[i] = new bool[N];
	}

	int** box = new int*[M];
	for (int i = 0; i < M; i++)
	{
		box[i] = new int[N];
	}

	for (int i = 0; i < M; i++)
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
		BFS(q, box,visited, N, M,t);
		
		for (int i = 0; i < M; i++)
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

		for (int i = 0; i < M; i++) {
			delete[] box[i];
		}
		delete[] box;

		for (int i = 0; i < M; i++) {
			delete[] visited[i];
		}
		delete[] visited;
	return 0;
}