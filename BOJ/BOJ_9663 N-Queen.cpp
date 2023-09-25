#include<iostream>
using namespace std;

int Draw_x[8] = { 0,1,0,-1,-1,1,1,-1 };
int Draw_y[8] = {1,0,-1,0,-1,1 ,-1,1 };
int Delete_x[8] = { 0,1,0,-1,-1,1,1,-1 };
int Delete_y[8] = { 1,0,-1,0,-1,1 ,-1,1 };
int count = 0;

void Draw(int N, int x, int y, int** visited)//퀸을 놓을 수 없는 곳에 색칠하는 과정
{
	int cnt = 1;
	visited[x][y]++;
	for (int i = 0; i < 8; i++)
	{
		cnt = 1;
		while (1) {
			
			if ((x + cnt*Draw_x[i]) < 0 || (y + cnt*Draw_y[i]) < 0 || (x + cnt * Draw_x[i]) == N || (y + cnt * Draw_y[i]) == N)
			{
				//벗어나면
				break;
			}
			else {
				visited[x + cnt * Draw_x[i]][y + cnt * Draw_y[i]]++;
			}
			cnt++;
		}

	}
	/*cout << "Draw" << endl;
	for (int i = 0; i < N; i++)
	{
		for (int j = 0; j < N; j++)
		{
			cout << visited[i][j] << " ";
		}
		cout << endl;
	}*/
}

void Delete(int N, int x, int y, int** visited)//pop되었을 때, 색칠한 곳들을 한개 씩 제거하는 과정
{
	int cnt = 1;
	visited[x][y]--;
	for (int i = 0; i < 8; i++)
	{
		cnt = 1;
		while (1) {

			if ((x + cnt * Draw_x[i]) < 0 || (y + cnt * Draw_y[i]) < 0 || (x + cnt * Draw_x[i]) == N || (y + cnt * Draw_y[i]) == N)
			{
				//벗어나면
				break;
			}
			else {
				visited[x + cnt * Draw_x[i]][y + cnt * Draw_y[i]]--;
			}
			cnt++;
		}

	}
	/*cout << "Delete" << endl;
	for (int i = 0; i < N; i++)
	{
		for (int j = 0; j < N; j++)
		{
			cout << visited[i][j] << " ";
		}
		cout << endl;
	}*/

}
void Backtracking(int N, int** visited, int x, int y)
{
	for (int i = 0; i < N; i++)
	{  //x축을 1씩증가(함수사용할 때마다)시키며 재귀함수 

		if (visited[x][y + i] == 0)
		{
			//cout << x << " " << y + i << endl;

			if (x == N - 1)//끝에 도착했을 때(퀸을 놓을 수 있으면서.)
			{
				::count++;
				
				//cout <<"count에요"<<" " << ::count << endl;
				break;
			}
			
			//count안되는거
			//
			
			Draw(N, x, y + i, visited);//방문한 곳으로부터 queen과 닿는곳 모두 그리고
			Backtracking(N, visited, x + 1, y);//x를1씩 더한값을 다시 back해줌
			Delete(N, x, y + i, visited);//갔다왔으면 지우기.
		}
	}

	//실패했을 때 빼야함
}
int main()
{
	int N, x = 0, y = 0;
	cin >> N;
	int** visited = new int *[N];
	for (int i = 0; i < N; i++)
	{
		visited[i] = new int[N];
	}

	for (int i = 0; i < N; i++)
	{
		for (int j = 0; j < N; j++)
		{
			visited[i][j] = 0;
		}
	}
	for (int i = 0; i < N; i++)
	{//x축이 0일때를 기준으로 돌린다.
		Draw(N, x, i, visited);
		Backtracking(N, visited, x+1, 0);//x축 다음행 y축 모든 열에 queen넣어보기
		Delete(N, x, i, visited);
	}
	cout << ::count;
	for (int i = 0; i < N; i++)
		delete[] visited[i];
	delete[] visited;
	exit(0);
	return 0;
}