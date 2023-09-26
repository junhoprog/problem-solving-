#include<iostream>
#include<algorithm>
#include<vector>
#include<string>
using namespace std;

int move_x[4] = { 0,1,0,-1 };
int move_y[4] = { 1,0,-1,0 };
vector<int>v;
void check_num(int x,int y,int N, int **check, bool **visited,int** map,int cnt)
{
	for (int i = 0; i < 4; i++)
	{
		if (x+move_x[i] < 0 || y + move_y[i] < 0 || x+move_x[i] == N || y+move_y[i] == N)
		{
			continue;
		}
		else if (check[x + move_x[i]][y + move_y[i]] == 1 && visited[x + move_x[i]][y + move_y[i]]==0)//1이면서 방문하지않았다면
		{
			visited[x + move_x[i]][y + move_y[i]] = 1;
			map[x + move_x[i]][y + move_y[i]] = cnt;
			v[cnt - 1]++;
			check_num(x + move_x[i], y + move_y[i], N, check, visited, map, cnt);//함수에 다음갈 곳 넣어주기
		}
	}
}

int main()
{
	int N;
	string s;
	cin >> N;
	int cnt = 1;
	int**check = new int* [N];//단지있는지여부확인 맵
	for (int i = 0; i < N; i++)
	{
		check[i] = new int[N];
	}

	int** map = new int* [N];//단지 수 기록
	for (int i = 0; i < N; i++)
	{
		map[i] = new int[N];
	}

	bool** visited = new bool* [N];//방문여부
	for (int i = 0; i < N; i++)
	{
		visited[i] = new bool[N];
	}

	for (int i = 0; i < N; i++)
	{
			cin >> s;
			for (int j = 0; j < s.size(); j++)
			{
				check[i][j] =(int)(s[j] - '0');
			}//문자열로 받은 뒤 각각 넣어주기***
	}

	for (int i = 0; i < N; i++)//방문여부 초기화
	{
		for (int j = 0; j < N; j++) {
			visited[i][j] = 0;
		}
	}


	for (int i = 0; i < N; i++)
	{
		for (int j = 0; j < N; j++)
		{
			if (check[i][j] == 1&&visited[i][j]==0)//방문x면서 1이면
			{
				v.push_back(1);//단지별 개수파악
				visited[i][j] = 1;
				map[i][j] = cnt;//단지번호
				check_num(i,j,N,check,visited,map,cnt);
				cnt++;
			}
		}
	}
	sort(v.begin(), v.end());
	cout << --cnt<<endl;
	for (int i = 0; i < v.size(); i++)
	{
		cout << v[i] << endl;
	}
		return 0;
}