#include<iostream>
#include<vector>
#include<queue>
using namespace std;

int move_X[2] = { 0,1 };//오른쪽또는 밑 이동 시
int move_Y[2] = { 1,0 };
vector<vector<int>>visit;//초기화
bool flag = false;
bool BFS(queue<pair<pair<int, int>, int>>q, int w, int i, int j, int N, vector<vector<int>>v)
{
	int x = 1, y = 1;
	while (!q.empty()) {//빌때까지 비었는데 도착안하면 Hing
		w = q.front().second;//숫자넣기
		x = q.front().first.first;//좌표넣기
		y = q.front().first.second;
		visit[x][y] = 1;


		q.pop();//앞부분 제거

		for (int d = 0; d < 2; d++)//이동
		{
			x += move_X[d] * w;
			y += move_Y[d] * w;

			if ((x == N - 1 && y == N - 1) && visit[x][y] == 0)//도착했다면
			{
				flag = true;
				return true;
			}

			if (x < N && y < N && visit[x][y] == 0)	//넘어가지않으면 push 
			{

				q.push(make_pair(make_pair(x, y), v[x][y]));
			}

			x -= move_X[d] * w;//다시 원상복구
			y -= move_Y[d] * w;
		}
		BFS(q, w, x, y, N, v);//반복(다음 queue pop하려고.)
	}
	return false;
}

int main()
{
	int N, x;
	cin >> N;
	vector<vector<int>>v(N, vector<int>(N, 0));//초기화
	vector<vector<int>>temp(N, vector<int>(N, 0));//초기화
	visit = temp;//동일하게 만듦.
	for (int i = 0; i < N; i++)
	{
		for (int j = 0; j < N; j++)
		{
			cin >> x;
			v[i][j] = x;//값 넣기
		}
	}
	queue<pair<pair<int, int>, int>>q;//queue 선언 좌표와 해당 가중치를 같이 저장.

	int i = 0, j = 0, w = 1;//i,j 위치 w는 가중치를 곱해줄 변수
	q.push(make_pair(make_pair(i, j), v[0][0]));//초기 위치 넣기
	visit[i][j] = 1;//0,0은 이미 방문했으니 1로 바꿈
	BFS(q, w, i, j, N, v);
	if (flag)//끝으로 도달하면
	{
		cout << "HaruHaru";
	}
	else {
		cout << "Hing";
	}
	return 0;
}