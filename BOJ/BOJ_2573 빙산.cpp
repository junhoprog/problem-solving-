#include<iostream>
#include<vector>
#include<queue>
using namespace std;

int move_x[4] = { 0,1,0,-1 };
int move_y[4] = { 1,0,-1,0 };

int count(vector<vector<int>>& v, int R, int C, vector<vector<bool>> visited)
{
	int cnt = 0;
	int x, y;
	queue<pair<int, int>>q;
	for (int i = 0; i < R; i++)
	{
		for (int j = 0; j < C; j++)
		{
			if (v[i][j] != 0 && visited[i][j] == false)
			{
				q.push(make_pair(i, j));
				visited[i][j] = true;

				while (!q.empty()) {
					x = q.front().first;
					y = q.front().second;
					q.pop();

					for (int t = 0; t < 4; t++)
					{
						if (x + move_x[t] < 0 || y + move_y[t] < 0 || y + move_y[t] >= C || x + move_x[t] >= R)
						{
							continue;
						}

						if (v[x + move_x[t]][y + move_y[t]] != 0 && visited[x + move_x[t]][y + move_y[t]] == false)
						{
							q.push(make_pair(x + move_x[t], y + move_y[t]));
							visited[x + move_x[t]][y + move_y[t]] = true;
						}
					}
					//동서남북을 돌면서 visited가 false면서 0이 아닌 곳으로 이동
				}
				cnt++;
			}
		}
	}

	return cnt;
}
//빙산 2개 이상으로 나눠지는 횟수 파악 함수

void search(vector<vector<int>>& v, int R, int C, vector<vector<bool>>& visited)
{

	vector<vector<int>> temp = v;
	int cnt = 0;
	int result = 0;
	int x, y;
	while (1) {
	
		v = temp;
		for (int i = 0; i < R; i++)
		{
			for (int j = 0; j < C; j++)
			{
				cnt = 0;
				if (v[i][j] != 0)
				{
					for (int r = 0; r < 4; r++)
					{
						x = i + move_x[r];
						y = j + move_y[r];
						if (x < 0 || y < 0 || y >= C || x >= R)
						{
							continue;
						}
						//바깥나가는거확인
						if (v[x][y] == 0)
						{
							cnt++;
						}
					}
					temp[i][j] -= cnt;

					if (temp[i][j] < 0)
					{
						temp[i][j] = 0;
					}
				}
			}
		}
		result++;
		if (count(temp, R, C, visited) > 1)//빙산의 개수가 2개이상이되면 break;
		{
			break;
		}
		else if (count(temp, R, C, visited) == 0)
		{
			result = 0;
			break;
		}
	}
	cout << result;
}


int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);

	int R, C, x;
	cin >> R >> C;

	vector<vector<int>>v(R, vector<int>(C, 0));
	vector<vector<bool>>visited(R, vector<bool>(C, false));
	for (int i = 0; i < R; i++)
	{
		for (int j = 0; j < C; j++)
		{
			cin >> x;
			v[i][j] = x;
		}
	}

	search(v, R, C, visited);

	return 0;
}