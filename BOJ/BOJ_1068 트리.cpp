#include<iostream>
using namespace std;

int cnt = 0;
void Search_child(int* Tree, int N, bool* live, int i) {
	int x = 2 * i + 1;
	int y = 2 * i + 2;

	if (live[i])
	{
		if (x > N)
		{
			cnt++;
			//�ڽĳ�尡 N�� �پ������ -> �ڽĳ�尡 ���ٴ� ��
		}
		if (y > N)
		{
			cnt++;
			return;
		}
		if (live[x] && x < N)
		{
			Search_child(Tree, N, live, x);
		}

		if (live[y] && y < N)
		{
			Search_child(Tree, N, live, y);
		}

	}
}
void Reduce_Tree(int* Tree, int N, int r,bool *live)
{
	//r�� ���° ��带 �������� ��Ÿ���°�.
	for (int i = 0; i < N; i++)
	{
		if (i == r)
		{
			while (1)
			{
				int x = 2 * i + 1;
				int y = 2 * i + 2;
				if (x > N || y > N)
				{
					//�ڽĳ�尡 �����Ƿ� ��
					break;
				}
				live[x] = 0;
				live[y] = 0;

			}
			break;
			Search_child(Tree, N, live, 0);
		}
		else {
			continue;
		}
	}
}

int main()
{
	int N, r;
	cin >> N;
	int* Tree = new int[N];
	bool* live = new bool[N];
	for (int i = 0; i < N; i++)
	{
		live[i] = 1;
	}

	for (int i = 0; i < N; i++)
	{
		cin>>Tree[i];//�θ��� �ֱ�
	}

	cin >> r;
	Reduce_Tree(Tree, N, r, live);
	cout << cnt;
	return 0;
}