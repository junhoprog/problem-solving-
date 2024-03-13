#include<iostream>
#include<vector>
#include<queue>
using namespace std;

int move_X[2] = { 0,1 };//�����ʶǴ� �� �̵� ��
int move_Y[2] = { 1,0 };
vector<vector<int>>visit;//�ʱ�ȭ
bool flag = false;
bool BFS(queue<pair<pair<int, int>, int>>q, int w, int i, int j, int N, vector<vector<int>>v)
{
	int x = 1, y = 1;
	while (!q.empty()) {//�������� ����µ� �������ϸ� Hing
		w = q.front().second;//���ڳֱ�
		x = q.front().first.first;//��ǥ�ֱ�
		y = q.front().first.second;
		visit[x][y] = 1;


		q.pop();//�պκ� ����

		for (int d = 0; d < 2; d++)//�̵�
		{
			x += move_X[d] * w;
			y += move_Y[d] * w;

			if ((x == N - 1 && y == N - 1) && visit[x][y] == 0)//�����ߴٸ�
			{
				flag = true;
				return true;
			}

			if (x < N && y < N && visit[x][y] == 0)	//�Ѿ�������� push 
			{

				q.push(make_pair(make_pair(x, y), v[x][y]));
			}

			x -= move_X[d] * w;//�ٽ� ���󺹱�
			y -= move_Y[d] * w;
		}
		BFS(q, w, x, y, N, v);//�ݺ�(���� queue pop�Ϸ���.)
	}
	return false;
}

int main()
{
	int N, x;
	cin >> N;
	vector<vector<int>>v(N, vector<int>(N, 0));//�ʱ�ȭ
	vector<vector<int>>temp(N, vector<int>(N, 0));//�ʱ�ȭ
	visit = temp;//�����ϰ� ����.
	for (int i = 0; i < N; i++)
	{
		for (int j = 0; j < N; j++)
		{
			cin >> x;
			v[i][j] = x;//�� �ֱ�
		}
	}
	queue<pair<pair<int, int>, int>>q;//queue ���� ��ǥ�� �ش� ����ġ�� ���� ����.

	int i = 0, j = 0, w = 1;//i,j ��ġ w�� ����ġ�� ������ ����
	q.push(make_pair(make_pair(i, j), v[0][0]));//�ʱ� ��ġ �ֱ�
	visit[i][j] = 1;//0,0�� �̹� �湮������ 1�� �ٲ�
	BFS(q, w, i, j, N, v);
	if (flag)//������ �����ϸ�
	{
		cout << "HaruHaru";
	}
	else {
		cout << "Hing";
	}
	return 0;
}