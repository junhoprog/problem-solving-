#include<iostream>
#include<vector>
#include<stack>
using namespace std;
int move_x[4] = {0,-1,0,1};
int move_y[4] = { 1,0,-1,0 };
int cnt = 0;
int N, M,K;
//가로 ,세로 ,심어져있는 위치개수
stack<pair<int,int>>S;

void dfs(int x, int y,int **map,bool**check)
{
	for (int i = 0; i < 4; i++)
	{
		if (x + move_x[i] >= M || y + move_y[i] >= N|| x + move_x[i]<0|| y + move_y[i]<0)
		{
			continue;
		}
		//현재위치 x,y
		if (check[x + move_x[i]][y + move_y[i]] == 1 && map[x + move_x[i]][y + move_y[i]] == 1)//이미 방문한 배추위치라면  
		{
			continue;
		}
		else if (check[x + move_x[i]][y + move_y[i]] == 0 && map[x + move_x[i]][y + move_y[i]] == 1) {
			//스택에 넣고
			S.push(make_pair(x, y));//현재 위치를 push
			check[x + move_x[i]][y + move_y[i]] = 1;
			dfs(x + move_x[i], y + move_y[i],map,check);
			//함수(이동시킨거 넣어줌)

		}//방문하지않은 배추위치라면
		else {
			continue;
			//0인 위치
		}
		if (i == 3)
		{
			S.pop();//현재 위치 x,y는 다 돌았기 때문에 스택 맨 뒤에 팝
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
		}//전체 맵크기

		bool** check = new bool* [M];
		for (int i = 0; i < M; i++)
		{
			check[i] = new bool[N];
		}//방문여부를 확인할 맵
		//M*N맵 생성
		for (int i = 0; i < M; i++)
		{
			for (int j = 0; j < N; j++)
			{
				map[i][j] = 0;
				check[i][j] = false;
			}
		}//초기화

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