#include<iostream>
#include<vector>
#include<algorithm>
#include<map>
using namespace std;
vector<vector<int>>v2;
int N;
int person;
int move_x[4] = { 0,1,0,-1 };
int move_y[4] = { -1,0,1,0 };

vector<vector<int>> third(int index, vector<pair<int, int>>check2, vector<vector<int>>seat)
{
	int x, y;
	int low_X=21, low_Y=21;
	for (int i = 0; i < check2.size(); i++)
	{
		x = check2[i].first;
		y = check2[i].second;
		if (seat[x][y] == 0) {
			if (x < low_X)
			{
				low_X = x;
			}
			if (x==low_X&&y < low_Y)
			{
				low_Y = y;
			}
		}
	}
	seat[low_X][low_Y] = v2[index][0];
	return seat;
}
vector<vector<int>> second(int index,vector<pair<int, int>>check, vector<vector<int>>seat)
{
	int max_cnt = 0;
	int x, y;
	int cnt = 0;

	vector<pair<int, int>>check2;
	for (int i = 0; i < check.size(); i++)
	{
		x = check[i].first;
		y = check[i].second;
		//앉은 자리에서 상하좌우에 좋아하는 학생의 번호 있는지 확인
		for (int t = 0; t < 4; t++)
		{
			if (x + move_x[t] < 0 || x + move_x[t] >= N || y + move_y[t] < 0 || y + move_y[t] >= N)
			{
				continue;
			}

			if (seat[x + move_x[t]][y + move_y[t]]==0)
			{
				cnt++;
			}
		}
		if (max_cnt < cnt)
		{
			max_cnt = max(max_cnt, cnt);
			check2.clear();
			check2.push_back(make_pair(x, y));
		}
		else if (max_cnt == cnt)
		{
			check2.push_back(make_pair(x, y));
		}
		cnt = 0;
	}
	if (check2.size() > 1)
	{
		seat=third(index, check2,seat);
	}
	else if(check2.size()==1){
		seat[check2[0].first][check2[0].second] = v2[index][0];
	}
	return seat;
}

vector<vector<int>> solve(int index,vector<vector<int>>seat)
{
	int cnt = 0;
	int max_cnt = 0;
	int x, y;
	vector<pair<int, int>>check;
	//모든 칸을 보면서 4번학생이 좋아하는 학생의 명수가 가장 많은 곳을 선택
	for (int i = 0; i < N; i++)
	{
		for (int j = 0; j < N; j++)
		{
			if (seat[i][j] != 0)
			{
				continue;
			}
			//앉은 자리에서 상하좌우에 좋아하는 학생의 번호 있는지 확인
			for (int t = 0; t < 4; t++)
			{
				x = move_x[t];
				y = move_y[t];
				if (i + x < 0 || i + x >= N || j + y < 0 || j + y >= N)
				{
					continue;
				}
				for (int q = 1; q < 5; q++)
				{
					if (v2[index][q] == seat[i +x][j + y])
					{
						cnt++;
						break;
					}
				}
			}
			if (max_cnt < cnt)
			{
				max_cnt = max(max_cnt, cnt);
				check.clear();
				check.push_back(make_pair(i, j));
			}
			else if (max_cnt == cnt)
			{
				check.push_back(make_pair(i, j));
			}
			cnt = 0;
		}
	}

	if (check.size() > 1)
	{
		seat=second(index,check,seat);
	}
	else {
		x = check[0].first;
		y= check[0].second;
		seat[x][y] = v2[index][0];
	}
	return seat;
}

int main()
{
	cin >> N;
	person = N * N;
	vector<vector<int>>v(person, vector<int>(5));
	vector<vector<int>>seat(N, vector<int>(N,0));
	for (int i = 0; i < person; i++)
	{
		for (int j = 0; j < 5; j++)
		{
			cin >> v[i][j];
		}
	}
	v2 = v;
	for (int i = 0; i < person; i++)
	{
		seat = solve(i, seat);
	}
	int x, y, cnt = 0, sum = 0;

	map<int, int>m;
	for (int i = 0; i < person; i++)
	{
		m[v[i][0]] = i;
	}
	//현재 위치에 있는 값
	
	int index;
	for (int i = 0; i < N; i++)
	{
		for (int j = 0; j < N; j++)
		{
			for (int t = 0; t < 4; t++)
			{
				x = move_x[t];
				y = move_y[t];
				if (i + x < 0 || i + x >= N || j + y < 0 || j + y >= N)
				{
					continue;
				}
				for (int q = 1; q < 5; q++)
				{
					index = m[seat[i][j]];
					if (v2[index][q] == seat[i + x][j + y])
					{
						cnt++;
						break;
					}
				}
			}
			switch (cnt)
			{
			case 0:
				sum += 0;
				break;
			case 1:
				sum += 1;
				break;
			case 2:
				sum += 10;
				break;
			case 3:
				sum += 100;
				break;
			case 4:
				sum += 1000;
			}
			cnt = 0;
		}
	}
	
	cout << sum;

	
	//모두가 0일때, 비어있는 칸이 가장 많은 칸으로 자리 선택
	//자리많은 곳 여러 곳일 때 r행 가장적은 다음 c행 가장적은 행 선택
}

/*
교실 N*N크기의 격자
n^2명
1~n^2까지 번호 매김(r,c)는 r행 c열
각 학생이 좋아하는 4명 조사(상하좌우가 인접한 자리임)
1. 비어있는 칸 중에서 좋아하는 학생이 인접한 칸에 가장 많은 칸으로 자리를 정함
*/