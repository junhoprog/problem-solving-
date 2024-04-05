#include <string>
#include <vector>
#include<queue>
#include<iostream>
using namespace std;

int move_x[4] = { 0,1,0,-1 };//이동 x
int move_y[4] = { 1,0,-1,0 };// 이동 y
int n, m;//그래프 크기

void search(pair<int, int> goal, pair<int, int> start, vector<vector<char>>graph, vector<vector<bool>>visited, int& answer)
{
	int x, y, cnt = 0;
	queue < pair<pair<int, int>, int>>q;//queue x,y와 해당 지점의 cnt번 이동횟수 기록

	q.push(make_pair(make_pair(start.first, start.second), 0));//처음 위치를 q에 넣고
	visited[start.first][start.second] = true;//처음 위치 방문 표시

	while (!q.empty())//q가 빌때까지
	{
		x = q.front().first.first;
		y = q.front().first.second;
		cnt = q.front().second;
		q.pop();
		//x,y,cnt에 q값 넣고 빼줌

		if (x == goal.first && y == goal.second)//x,y가 목표지점 도착했을 때 최소 횟수를 기록
		{
			answer = min(answer, cnt);//여러 번 방문할 수도 있어서
		}

		for (int i = 0; i < 4; i++)//상하좌우 이동
		{
			int nx = x, ny = y;
			while (1)//벽 안닿을 때까지 이동
			{
				nx += move_x[i];
				ny += move_y[i];

				if (nx == n || ny == m || ny == -1 || nx == -1 || graph[nx][ny] == 'D')//벽에 닿으면
				{
					//다시 전 자리로 이동
					nx -= move_x[i];
					ny -= move_y[i];
					break;
				}
			}

			if (visited[nx][ny])//방문한 곳이면 다음 방향
			{
				continue;
			}

			q.push(make_pair(make_pair(nx, ny), cnt + 1));//방문 안했으면 q에 넣고
			visited[nx][ny] = true;//지금 위치 방문 표시

		}
	}
}

int solution(vector<string> board) {
	int answer =12784174;//무조건 큰 값을 넣어줌
	vector<vector<char>>graph(board.size());//전체 모형
	pair<int, int> Goal;//목표지점
	pair<int, int> Start;//시작지점
	vector<vector<bool>>visited(board.size());//방문여부
	n = board.size();//그래프 크기 가로길이
	m=board[0].size();//세로길이

	for (int i = 0; i < n; i++)
	{
		for (int j = 0; j <m; j++)
		{
			visited[i].push_back(false);//초기화
			graph[i].push_back(board[i][j]);//공간 채우기

			if (board[i][j] == 'R')//시작지점이면
			{
				Start = make_pair(i, j);//기록
			}

			else if (board[i][j] == 'G')//목표 지점이면
			{
				Goal = make_pair(i, j);//기록
			}
		}
	}

	search(Goal, Start, graph, visited, answer);

	if (answer == 12784174)//쓰레기 값이면 -1 출력
	{
		answer = -1;
	}
	return  answer;
}


int main()
{
	vector<string>board;
	string s="...D..R";
	board.push_back(s);
	s = ".D.G...";
	board.push_back(s);
	s = "....D.D";
	board.push_back(s);
	s = "D....D.";
	board.push_back(s);
	s = "..D....";
	board.push_back(s);

	cout<<solution(board);
}