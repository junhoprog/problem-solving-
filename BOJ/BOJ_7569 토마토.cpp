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
			q.pop();//빼주기
			for (int i = 0; i < 6; i++) //층 나누는거 생각하기
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
					//현재위치(1)에서 상하좌우가 0이면서, 방문하지않은 곳으로 감.
					box[x + move_x[i]][y + move_y[i]] = 1;//그 위치를 1로 만들어주고
					visited[x + move_x[i]][y + move_y[i]] = 1;//방문 확인
					q.push(make_pair(x + move_x[i], y + move_y[i]));//queue에 1로 만든 위치를 넣어준다
					tmp++;
				}
			}
		}
		count = tmp;//다시 횟수 바꿔줌.
		tmp = 0;
		cnt++;
	}
	cnt--;
}
int main()
{
	// 익지않은 0 익은 1 들어있지않은 칸 -1
	// 익은 토마토들의 인접한 곳에 있는 익지 않은 토마토들은 익은 토마토 영향받아 익음.
	// 인접의 기준 왼 오 윗 아
	// 1일이 지나면 1주변 0이 1이됨. 최소 일수 구하기.
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
				if (box[i][j] == 0)//1개라도 안익은게있다면
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