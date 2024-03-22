#include<iostream>
#include<vector>
#include<queue>

using namespace std;

int move_x[8] = { 0,1,1,1,0,-1,-1,-1 };//모든 방향이동
int move_y[8] = { -1,-1,0,1,1,1,0,-1 };

void BFS(vector<vector<bool>>visit,vector<vector<int>>v, vector<vector<int>>map, vector < pair<int, int>>shark, queue<pair<int, int>>q,int cnt,int N,int M,int amount)
{
	int count = 0;//상어가 이동하는 횟수
	int count2 = 0;//다음 상어가 이동할(queue에 넣은)횟수저장
	int max_num = 0;//최대값저장

	//cnt가 1일때 샤크의 범위내 모든 0을 1로 만듦.
	while (!q.empty()) {//q가 비어있을 때까지
		
		count++;//상어가 칸에 도착하기까지의 횟수
		if (count > amount)//넘으면
		{
			cnt++;//다음 으로 넘어감.
			amount = count2;//다음횟수 저장.
			count2 = 0;
			count = 1;
		}
		int temp_x = q.front().first, temp_y = q.front().second;//상어의 이동위치
		q.pop();

		for (int j = 0; j < 8; j++)
		{
			temp_x += move_x[j];//이동방향을 더함
			temp_y += move_y[j];
			
			//모든 방향 가면서
			if (temp_x < 0 || temp_y < 0 || temp_x >= N || temp_y >= M)//넘으면 원래상태로
			{
				temp_x -= move_x[j];
				temp_y -= move_y[j];
				continue;
			}
			else if (v[temp_x][temp_y] == 0 && !visit[temp_x][temp_y])//방문해도 되는 곳이라면
			{
				if (map[temp_x][temp_y] > cnt)//값이 더 큰 것이 있다면 교체
				{
					
					map[temp_x][temp_y]=cnt;
					if (max_num < cnt)//max_num도 교체
						max_num = cnt;
				}
				q.push(make_pair(temp_x, temp_y));//q에 넣고
				visit[temp_x][temp_y] = true;//방문했다고 표시
				count2++;//다음 상어의 이동횟수에 추가함.
			}
			temp_x -= move_x[j];
			temp_y -= move_y[j];
		}
		//모든 샤크 범위 확인

	}
	
	cout << max_num;
}

int main()
{
	int N, M;
	cin >> N >> M;

	int x;

	vector<vector<int>>v(N,vector<int>(M,0));
	vector<vector<int>>map(N, vector<int>(M, 100));//weight를 최신화
	vector < pair<int, int>>shark;
	vector<vector<bool>>visit(N, vector<bool>(M, false));
	for (int i = 0; i < N; i++)
	{
		for (int j = 0; j < M; j++)
		{
			cin >> x;
			v[i][j] = x;
			if (x == 1)
			{
				shark.push_back(make_pair(i, j));//상어가 있는 곳만 확인하려고
			}
		}
	}
	
	int cnt = 0;
	queue<pair<int, int>>q;
	for (int i = 0; i < shark.size(); i++)
	{
		q.push(make_pair(shark[i].first, shark[i].second));
	}
	BFS(visit,v, map, shark, q, cnt+1,N,M,shark.size());
	
	return 0;
}
