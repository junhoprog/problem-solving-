#include<iostream>
using namespace std;

void Search(bool** visited, int** Map,int* C,int x,int y, int N)
{
	static int cnt = 0;
	int num_cnt = 0;
	int dx[4] = { 0,1,0,-1 };
	int dy[4] = { 1,0,-1,0 };
	int nx, ny;

	for (int i = 0; i < 4; i++)
	{
		nx = x + dx[i];
		ny = y + dy[i];
		if (visited[nx][ny] == 0 && Map[nx][ny])
		{

		}

	}
	//모든 면이 search가 끝나면 cnt++하고 num_cnt에 값 저장
}

int main()
{
	int N,count=0;
	cin >> N;
	bool** visited = new bool*[N];
	for (int i = 0; i < N; i++)
	{
		visited[i] = new bool[N];
	}

	int** Map = new int* [N];
	for (int i = 0; i < N; i++)
	{
		Map[i] = new int[N];
	}
	int*C=new int[N];

	string temp;
	for (int i = 0; i < N; i++)
	{
		cin >> temp;
		for (int j = 0; j < N; j++)
		{
			Map[i][j] = temp[count];
			count++;
		}
		temp = "";
	}
	visited[0][0] = 1;
	Search(visited,Map,C,0 ,0,N);
	for (int i = 0; i < N; i++)
	{
		delete[]Map[i];
	}
	delete[]Map;

	for (int i = 0; i < N; i++)
	{
		delete[]visited[i];
	}
	delete[]visited;

	delete[]C;

	//1은 집 0은 집X

	return 0;
}