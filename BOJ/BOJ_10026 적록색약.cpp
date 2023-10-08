#include<iostream>
#include<string>
using namespace std;

int move_x[4] = { 0,1,0,-1 };
int move_y[4] = { 1,0,-1,0 };

int cnt1 = 0;//���ϻ���x
int cnt2 = 0;//���ϻ���
char criteria;//���� ��
void dfs(bool** visited, char** c, int N, int x, int y)
{
	//ó���� ���ϻ��� �ƴѻ�� ���ϱ�
	for (int q = 0; q < 4; q++) {
		if (y + move_y[q] < 0 || y + move_y[q] == N || x + move_x[q] < 0 || x + move_x[q] == N)//������ �Ѿ��� ��
		{
			continue;
		}
		if (visited[x + move_x[q]][y + move_y[q]] == false && c[x + move_x[q]][y + move_y[q]] ==criteria)
		{
			visited[x + move_x[q]][y + move_y[q]] = 1;
			if (c[x + move_x[q]][y + move_y[q]] == 'G')//G�� R�� �ٲٱ�
			{
				c[x + move_x[q]][y + move_y[q]] = 'R';
			}
			dfs(visited, c, N, x + move_x[q], y + move_y[q]);
		}
	}
}

void dfs2(bool** visited, char** c, int N, int x, int y)
{
	//��ͷ�
	//���ϻ��� ���ϱ�

	for (int q = 0; q < 4; q++) {
		if (y + move_y[q] < 0 || y + move_y[q] == N || x + move_x[q] < 0 || x + move_x[q] == N)
		{
			continue;
		}
		if (visited[x + move_x[q]][y + move_y[q]] == false && c[x + move_x[q]][y + move_y[q]] == criteria)
		{
			visited[x + move_x[q]][y + move_y[q]] = 1;
			dfs2(visited, c, N, x + move_x[q], y + move_y[q]);
		}
	}
}
int main()
{

	//���ϻ��� �ƴѻ�� ���� �� ����
	//�� ����� ����x��-�� ��

	int N;
	cin >> N;
	char** c = new char* [N];
	for (int i = 0; i < N; i++)
	{
		c[i] = new char[N];
	}

	bool** visited = new bool* [N];
	for (int i = 0; i < N; i++)
	{
		visited[i] = new bool[N];
	}

	string s;
	for (int j = 0; j < N; j++)
	{
		cin >> s;
		for (int i = 0; i < N; i++)
		{
			c[j][i] = s[i];//�� �׸���
		}
	}


	for (int i = 0; i < N; i++)
	{
		for (int j = 0; j < N; j++)
		{
			visited[i][j] = false;//�ʱ�ȭ
		}
	}

	for (int i = 0; i < N; i++) {
		for (int j = 0; j < N; j++) {
			{
				criteria = 'd';
				if (visited[i][j] == false && c[i][j] != criteria)//�湮�����ʾҹǳ༭ ���� ���� �ٸ��ٸ�
				{
					criteria = c[i][j];
					if (c[i][j] == 'G')
					{
						c[i][j] = 'R';
					}
					visited[i][j] = true;
					dfs(visited, c, N, i, j);
					
					cnt1++;
				}
				else {
				}
			}
		}
	}
	
	for (int i = 0; i < N; i++)
	{
		for (int j = 0; j < N; j++)
		{
			visited[i][j] = 0;
		}
	}

	criteria = 'd';

	for (int i = 0; i < N; i++) {
		for (int j = 0; j < N; j++) {
			{
				criteria = 'd';
				if (visited[i][j] == false && c[i][j] != criteria)//�湮�����ʾҹǳ༭ ���� ���� �ٸ��ٸ�
				{
					criteria = c[i][j];
					visited[i][j] = true;
					dfs2(visited, c, N, i, j);
					cnt2++;
				}
			}
		}
	}

		cout << cnt1<<" "<<cnt2;
		for (int i = 0; i < N; ++i) {
			delete[] c[i];
		}
		delete[] c;

		for (int i = 0; i < N; ++i) {
			delete[] visited[i];
		}
		delete[] visited;
		return 0;
	
}