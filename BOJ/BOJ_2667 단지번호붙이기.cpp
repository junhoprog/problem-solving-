#include<iostream>
#include<vector>
using namespace std;

int num_cnt = 0;
void Search(bool** visited, int** Map, int x, int y, int N, int num_cnt)
{
	static int cnt = 1;

	int dx[4] = { 0,1,0,-1 };
	int dy[4] = { 1,0,-1,0 };

	int nx, ny;

	if (Map[x][y] && visited[x][y] == 0)
	{

		visited[x][y] = 1;
		num_cnt++;
		cout << "hello" << " ";
		for (int i = 0; i < 4; i++)
		{
			nx = x + dx[i];
			ny = y + dy[i];
			if (visited[nx][ny] == 0 && Map[nx][ny])
			{
				Search(visited, Map, nx, ny, N, num_cnt);
				//내 주변에 1이 있는지 확인해
			}

			else {
				continue;
			}
		}
		cnt++;
	}

	cout << num_cnt;
	//자신이 있는 자리가 1이면 

}

int main()
{
	int N, count = 0;
	cin >> N;
	bool** visited = new bool* [N];//방문여부확인
	for (int i = 0; i < N; i++)
	{
		visited[i] = new bool[N];
	}

	int** Map = new int* [N];//정N각형 지도
	for (int i = 0; i < N; i++)
	{
		Map[i] = new int[N];
	}
	
	vector<int>C((N*N)/2+1);
	
	string temp;
	for (int i = 0; i < N; i++)
	{
		cin >> temp;
		for (int j = 0; j < N; j++)
		{
			Map[i][j] = temp[count];
			count++;
		}
		count = 0;
		temp = "";
	}

	count = 0;
	for (int i = 0; i < N; i++)
	{
		for (int j = 0; j < N; j++)
		{
			Search(visited, Map, i, j, N, 0);
				if (num_cnt != 0)
				{
					C[count] = num_cnt;
					num_cnt=0;
					count++;
					cout << "hello" << endl;
				}
		}
	}
	
	cout << count + 1 << endl;
	for (int i = 0; i < count+1; i++)
	{
		cout << C[i] << endl;
	}
	
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


	return 0;
}