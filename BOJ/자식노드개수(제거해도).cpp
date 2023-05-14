/*#include<iostream>
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
			//자식노드가 N을 뛰어넘으면 -> 자식노드가 없다는 뜻
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
void Reduce_Tree(int* Tree, int N, int r,bool *live,int num)
{
	int x, y;
	for (int i=num; i < N; i++)
	{
		x = 2 * i + 1;
		y = 2 * i + 2;

		if (i == r)
		{
		while (i < N) {
			live[i] = 0;
				if (Tree[x] == i)
				{
					
				}
				if (Tree[y] == i)
				{

				}
				break;
			}
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
		cin>>Tree[i];//부모노드 넣기
	}

	cin >> r;

	Reduce_Tree(Tree, N, r, live,0);
	cout << cnt;
	return 0;
}*/


#include<iostream>
using namespace std;

int cnt = 0;
void Search_child(int* Tree, int N, bool* live, int i) {
	int x = 2 * i + 1;
	int y = 2 * i + 2;

	if (live[i])
	{
		if (live[x] && x < N)
		{
			Search_child(Tree, N, live, x);
			cout << "x에서" <<x<< "\n";
		}

		if (live[y] && y < N)
		{
			Search_child(Tree, N, live, y);
			cout << "y에서" <<  y << "\n";
		}

		if (x > N || y > N)
		{
			cnt++;
		}
	}
}
void R_Tree(int* Tree, int N, int r, bool* live) {
	int x = 2 * r + 1;
	int y = 2 * r + 2;
	live[r] = 0;
	if (x < N)
	{
		R_Tree(Tree, N, x, live);
	}

	if (y < N)
	{
		R_Tree(Tree, N, y, live);
	}
}

void Reduce_Tree(int* Tree, int N, int r, bool* live)
{
	for (int i = 0; i < N; i++)
	{
		if (i == r)
		{
			R_Tree(Tree, N, r, live);
			Search_child(Tree, N, live, 0);
		}
		else {
			continue;
		}
	}
}
void Set_Tree(int* Tree, int N, int r, bool* live,int i)
{
	int s=0;
	if (Tree[i] == -1)
	{
		live[i] = 1;
		Set_Tree(Tree, N, r, live, i+1);
	}
	else {
		if (s == 0)
		{
			live[2 * Tree[i] + 1] = 1;
			s++;
		}
		else if (s == 1)
		{
			live[2 * Tree[i] + 2] = 1;
			s = 0;
		}
	}
		Reduce_Tree(Tree, N, r, live);
}

int main()
{
	int N, r;
	cin >> N;
	int* Tree = new int[N];
	bool* live = new bool[N*N];
	for (int i = 0; i < N*N; i++)
	{
		live[i] = 0;
	}

	for (int i = 0; i < N; i++)
	{
		cin >> Tree[i];//부모노드 넣기
	}

	cin >> r;
	Set_Tree(Tree, N, r, live, 0);
	cout << cnt;
	return 0;
}