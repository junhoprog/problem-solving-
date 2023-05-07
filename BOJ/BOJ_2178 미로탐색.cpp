#include<iostream>
#include<string>
using namespace std;


void Search_Maze(bool** Maze, bool** visited, int x, int y, int N, int M)
{
	int dx[4] = { 1,0,0,-1 };
	int dy[4] = { 0,1,-1,0 };
	static int cnt = 1;

	if (x == N - 1 && y == M - 1)
	{
		cout <<cnt;
		return;
	}

	for (int i = 0; i < 4; i++)
	{
		if (x + dx[i] == 0 || y + dy[i] == 0 || x + dx[i] == N || y + dy[i] == M)
		{
			continue;
			//벽으로 가면 못가게하기
		}
		else if (visited[x + dx[i]][y + dy[i]]) {
			continue;
			//방문했던 곳이라면
		}
		else if (Maze[x + dx[i]][y + dy[i]] == 1 && visited[x + dx[i]][y + dy[i]] == 0)
		{
			visited[x + dx[i]][y + dy[i]] = 1;
			cnt++;
			Search_Maze(Maze, visited, x + dx[i], y + dy[i], N, M);
		}
		else {
			continue;
		}
	}
	cnt--;
}


int main()
{
	int N, M,count=0;
	string s;
	char q;
	cin >> N >> M;
	bool** Maze = new bool* [N + 2];
	for (int i = 0; i <= N + 1; i++)
	{
		Maze[i] = new bool[M + 2];
	}
	string temp;
	for (int i = 1; i <= N; i++)
	{
		count = 0;
		cin >> temp;
		for (int j = 1; j <= M; j++)
		{
			Maze[i][j] = temp[count] - '0';
			count++;
		}
		temp = "";
	}

	for (int i = 0; i <= N + 1; i++)
	{
		Maze[i][0] = 0;
	}
	for (int j = 0; j <= M + 1; j++)
	{
		Maze[0][j] = 0;
	}

	for (int i = 1; i <= N + 1; i++)
	{
		Maze[i][M + 1] = 0;
	}
	for (int i = 1; i <= M + 1; i++)
	{
		Maze[N + 1][i] = 0;
	}

	static bool** visited = new bool* [N + 2];
	for (int i = 0; i <= N + 1; i++)
	{
		visited[i] = new bool[M + 2];
	}

	for (int i = 0; i <= N + 1; i++)
	{
		for (int j = 0; j <= M + 1; j++)
		{
			visited[i][j] = 0;
		}
	}
	visited[1][1] = 1;
	Search_Maze(Maze, visited, 1, 1, N + 1, M + 1);

	for (int i = 0; i <= N + 1; i++)
	{
		delete[] Maze[i];
	}
	delete[]Maze;

	for (int i = 0; i <= N + 1; i++)
	{
		delete[] visited[i];
	}
	delete[]visited;
	return 0;
}