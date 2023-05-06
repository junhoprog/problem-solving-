#include<iostream>
using namespace std;


void Search_Maze(bool** Maze,bool** visited,int x,int y,int N,int M)
{
	int dx[4] = { 0,1,0,-1 };
	int dy[4] = { 1,0,-1,0 };

	for (int i = 0; i < 4; i++)
	{
		if (Maze[x][y] == 1)
		{

		}
		else if (Maze[x][y]==0&&)
	}
	if (x == 0 || y == 0 || x == N || y == M)
	{

	}
}
int main()
{
	int N, M;
	cin >> N >> M;
	bool** Maze = new bool*[N + 2];
	for (int i = 0; i <= N+1; i++)
	{
		Maze[i] = new bool[M + 2];
	}

	for (int i = 1; i <= N; i++)
	{
		for (int j = 1; j <= M; j++)
		{
			cin >> Maze[i][j];
		}
	}

	for (int i = 0; i <= N+1; i++)
	{
		Maze[i][0] = 0;
	}
	for (int j = 0; j <= M+1; j++)
	{
		Maze[0][j] = 0;
	}

	for (int i = 1; i <= N+1; i++)
	{
		Maze[i][M+1] = 0;
	}
	for (int i = 1; i <= M+1; i++)
	{
		Maze[N+1][i] = 0;
	}
	for (int i = 0; i <= N+1; i++)
	{
		for (int j = 0; j <= M+1; j++)
		{
			cout << Maze[i][j] << " ";
		}
		cout << endl;
	}
	static bool** visited = new bool* [N + 2];
	for (int i = 0; i <= N + 1;i++)
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
	Search_Maze(Maze,visited, 1, 1, N + 1, M + 1);

	for (int i = 0; i <= N+1; i++)
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