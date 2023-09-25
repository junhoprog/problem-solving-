#include<iostream>
using namespace std;

int Draw_x[8] = { 0,1,0,-1,-1,1,1,-1 };
int Draw_y[8] = {1,0,-1,0,-1,1 ,-1,1 };
int Delete_x[8] = { 0,1,0,-1,-1,1,1,-1 };
int Delete_y[8] = { 1,0,-1,0,-1,1 ,-1,1 };
int count = 0;

void Draw(int N, int x, int y, int** visited)//���� ���� �� ���� ���� ��ĥ�ϴ� ����
{
	int cnt = 1;
	visited[x][y]++;
	for (int i = 0; i < 8; i++)
	{
		cnt = 1;
		while (1) {
			
			if ((x + cnt*Draw_x[i]) < 0 || (y + cnt*Draw_y[i]) < 0 || (x + cnt * Draw_x[i]) == N || (y + cnt * Draw_y[i]) == N)
			{
				//�����
				break;
			}
			else {
				visited[x + cnt * Draw_x[i]][y + cnt * Draw_y[i]]++;
			}
			cnt++;
		}

	}
	/*cout << "Draw" << endl;
	for (int i = 0; i < N; i++)
	{
		for (int j = 0; j < N; j++)
		{
			cout << visited[i][j] << " ";
		}
		cout << endl;
	}*/
}

void Delete(int N, int x, int y, int** visited)//pop�Ǿ��� ��, ��ĥ�� ������ �Ѱ� �� �����ϴ� ����
{
	int cnt = 1;
	visited[x][y]--;
	for (int i = 0; i < 8; i++)
	{
		cnt = 1;
		while (1) {

			if ((x + cnt * Draw_x[i]) < 0 || (y + cnt * Draw_y[i]) < 0 || (x + cnt * Draw_x[i]) == N || (y + cnt * Draw_y[i]) == N)
			{
				//�����
				break;
			}
			else {
				visited[x + cnt * Draw_x[i]][y + cnt * Draw_y[i]]--;
			}
			cnt++;
		}

	}
	/*cout << "Delete" << endl;
	for (int i = 0; i < N; i++)
	{
		for (int j = 0; j < N; j++)
		{
			cout << visited[i][j] << " ";
		}
		cout << endl;
	}*/

}
void Backtracking(int N, int** visited, int x, int y)
{
	for (int i = 0; i < N; i++)
	{  //x���� 1������(�Լ������ ������)��Ű�� ����Լ� 

		if (visited[x][y + i] == 0)
		{
			//cout << x << " " << y + i << endl;

			if (x == N - 1)//���� �������� ��(���� ���� �� �����鼭.)
			{
				::count++;
				
				//cout <<"count����"<<" " << ::count << endl;
				break;
			}
			
			//count�ȵǴ°�
			//
			
			Draw(N, x, y + i, visited);//�湮�� �����κ��� queen�� ��°� ��� �׸���
			Backtracking(N, visited, x + 1, y);//x��1�� ���Ѱ��� �ٽ� back����
			Delete(N, x, y + i, visited);//���ٿ����� �����.
		}
	}

	//�������� �� ������
}
int main()
{
	int N, x = 0, y = 0;
	cin >> N;
	int** visited = new int *[N];
	for (int i = 0; i < N; i++)
	{
		visited[i] = new int[N];
	}

	for (int i = 0; i < N; i++)
	{
		for (int j = 0; j < N; j++)
		{
			visited[i][j] = 0;
		}
	}
	for (int i = 0; i < N; i++)
	{//x���� 0�϶��� �������� ������.
		Draw(N, x, i, visited);
		Backtracking(N, visited, x+1, 0);//x�� ������ y�� ��� ���� queen�־��
		Delete(N, x, i, visited);
	}
	cout << ::count;
	for (int i = 0; i < N; i++)
		delete[] visited[i];
	delete[] visited;
	exit(0);
	return 0;
}