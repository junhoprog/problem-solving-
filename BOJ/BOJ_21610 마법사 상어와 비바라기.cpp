#include<iostream>
#include<vector>
using namespace std;
int N, M;

vector<pair<int, int>>cloud;
int move_diry[9] = {0, -1,-1,0,1,1,1,0,-1 };
int move_dirx[9] = {0, 0,-1,-1,-1,0,1,1,1 };
vector<vector<int>> search_cloud(vector<vector<int>>v,vector<pair<int,int>>temp)
{
	bool is_check = false;
	for (int i = 0; i < N; i++)
	{
		for (int j = 0; j < N; j++)
		{
			if (v[i][j] > 1)
			{
				for (int t = 0; t < temp.size(); t++)
				{
					if (i == temp[t].first && j == temp[t].second)
					{
						is_check = true;
						break;
					}
				}
				if (is_check == true)
				{
					is_check = false;
					continue;
				}
				v[i][j] -= 2;
				cloud.push_back(make_pair(i, j));
			}
		}
	}
	return v;
}
vector<vector<int>> copy_cloud(vector<int>dir, vector<int>move, vector<vector<int>>v, int i)
{
	for (int i = 0; i < cloud.size(); i++)
	{
		int x = cloud[i].first;
		int y= cloud[i].second;
		if (x - 1 >= 0 && y - 1 >= 0 && v[x - 1][y - 1] > 0)
		{
			v[x][y]++;
		}
		if (x + 1 < N && y - 1 >= 0 && v[x + 1][y - 1] > 0)
		{

			v[x][y]++;
		}
		if (x + 1 < N && y + 1< N && v[x + 1][y + 1] > 0)
		{

			v[x][y]++;
		}
		if (x - 1 >= 0 && y + 1 < N && v[x - 1][y + 1] > 0)
		{

			v[x][y]++;
		}
	}
	return v;
}

vector<vector<int>> move_cloud(vector<int>dir, vector<int>move, vector<vector<int>>v,int i)
{
	int x=move_dirx[dir[i]], y= move_diry[dir[i]];
	//cloud에 있는 모든 요소들을 dir
	for (int j = 0; j < cloud.size(); j++)
	{
		cloud[j].first += (x * move[i]);
		cloud[j].second += (y * move[i]);

		if (cloud[j].first < 0)
		{
			while (cloud[j].first < 0)
			{
				cloud[j].first = N + cloud[j].first;
			}
		}
		else if (cloud[j].first >= N)
		{
			while (cloud[j].first >= N)
			{
				cloud[j].first = cloud[j].first - N;
			}
		}
		if (cloud[j].second < 0)
		{
			while (cloud[j].second < 0)
			{
				cloud[j].second = N + cloud[j].second;
			}

		}
		else if (cloud[j].second >= N)
		{
			while (cloud[j].second >= N)
			{
				cloud[j].second = cloud[j].second - N;
			}
		}
	}
	for (int j = 0; j < cloud.size(); j++)
	{
		v[cloud[j].first][cloud[j].second]++;
	}
	return v;
}

void solve(vector<int>dir, vector<int>move, vector<vector<int>>v)
{
	//처음(N, 1), (N, 2), (N - 1, 1), (N - 1.2) 비구름 생성
	cloud.push_back(make_pair(N-1, 0));
	cloud.push_back(make_pair(N-1, 1));
	cloud.push_back(make_pair(N-2, 0));
	cloud.push_back(make_pair(N-2, 1));
	vector<pair<int,int>>temp;
	for (int i = 0; i < M; i++)
	{
		//m번 이동을 시작
		v=move_cloud(dir, move,v,i);//비구름 이동시키기

		//대각선 찾아서 복사하기
		v=copy_cloud(dir, move, v, i);
		temp = cloud;
		cloud.clear();
		//2개이상인 곳 찾아서 구름 만들기
		v=search_cloud( v,temp);
	}
	int sum = 0;
	for (int i = 0; i < N; i++)
	{
		for (int j = 0; j < N; j++)
		{
			sum += v[i][j];
		}
	}
	cout << sum;
}

int main()
{
	cin >> N >> M;
	vector<vector<int>>v(N, vector<int>(N));
	vector<int>dir(M);
	vector<int>move(M);
	for (int i = 0; i < N; i++)
	{
		for (int j = 0; j < N; j++)
		{
			cin >> v[i][j];
		}
	}

	for (int i = 0; i < M; i++) {
		cin >> dir[i] >> move[i];
	}
	solve(dir, move, v);
	return 0;
}
/*
처음 (N,1),(N,2),(N-1,1),(N-1.2) 비구름 생성
이동 M번 명령 i번째 이동명령은 방향 di과 거리 si로 이루어짐
만약 1,3 이면 1방향으로 3만큼 이동
*/