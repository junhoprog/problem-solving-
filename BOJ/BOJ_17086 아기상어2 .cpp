#include<iostream>
#include<vector>
#include<queue>

using namespace std;

int move_x[8] = { 0,1,1,1,0,-1,-1,-1 };//��� �����̵�
int move_y[8] = { -1,-1,0,1,1,1,0,-1 };

void BFS(vector<vector<bool>>visit,vector<vector<int>>v, vector<vector<int>>map, vector < pair<int, int>>shark, queue<pair<int, int>>q,int cnt,int N,int M,int amount)
{
	int count = 0;//�� �̵��ϴ� Ƚ��
	int count2 = 0;//���� �� �̵���(queue�� ����)Ƚ������
	int max_num = 0;//�ִ밪����

	//cnt�� 1�϶� ��ũ�� ������ ��� 0�� 1�� ����.
	while (!q.empty()) {//q�� ������� ������
		
		count++;//�� ĭ�� �����ϱ������ Ƚ��
		if (count > amount)//������
		{
			cnt++;//���� ���� �Ѿ.
			amount = count2;//����Ƚ�� ����.
			count2 = 0;
			count = 1;
		}
		int temp_x = q.front().first, temp_y = q.front().second;//����� �̵���ġ
		q.pop();

		for (int j = 0; j < 8; j++)
		{
			temp_x += move_x[j];//�̵������� ����
			temp_y += move_y[j];
			
			//��� ���� ���鼭
			if (temp_x < 0 || temp_y < 0 || temp_x >= N || temp_y >= M)//������ �������·�
			{
				temp_x -= move_x[j];
				temp_y -= move_y[j];
				continue;
			}
			else if (v[temp_x][temp_y] == 0 && !visit[temp_x][temp_y])//�湮�ص� �Ǵ� ���̶��
			{
				if (map[temp_x][temp_y] > cnt)//���� �� ū ���� �ִٸ� ��ü
				{
					
					map[temp_x][temp_y]=cnt;
					if (max_num < cnt)//max_num�� ��ü
						max_num = cnt;
				}
				q.push(make_pair(temp_x, temp_y));//q�� �ְ�
				visit[temp_x][temp_y] = true;//�湮�ߴٰ� ǥ��
				count2++;//���� ����� �̵�Ƚ���� �߰���.
			}
			temp_x -= move_x[j];
			temp_y -= move_y[j];
		}
		//��� ��ũ ���� Ȯ��

	}
	
	cout << max_num;
}

int main()
{
	int N, M;
	cin >> N >> M;

	int x;

	vector<vector<int>>v(N,vector<int>(M,0));
	vector<vector<int>>map(N, vector<int>(M, 100));//weight�� �ֽ�ȭ
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
				shark.push_back(make_pair(i, j));//�� �ִ� ���� Ȯ���Ϸ���
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
