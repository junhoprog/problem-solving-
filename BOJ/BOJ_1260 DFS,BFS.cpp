#include<iostream>
#include<queue>
#include<stack>

using namespace std;
stack<int>S;
queue<int>Q;

void DFS(bool **arr,int V,int N,bool*B)
{
	S.push(V);
	cout << V << " ";
	B[V] = 1;
		for (int i = 1; i <= N; i++)
		{
			if (V == i)
			{
				continue;
			}
			else if (B[i] == 1)
			{
				continue;
			}
			else if (B[i] == 0 && arr[V][i] == 1)
			{
				DFS(arr, i, N,B);
			}
		}	
		S.pop();
}
void BFS(bool** arr,int V, int N, bool* B)
{
	for (int i = 1; i <= N; i++)
	{
		if (V == i)
		{
			continue;
		}
		else if (B[i] == 1)
		{
			continue;
		}
		else if (B[i] == 0 && arr[V][i] == 1)
		{
			Q.push(i);
			B[i] = 1;
		}
	}

	cout << Q.front()<<" ";
	Q.pop();
	if (Q.empty() == 1) {
		return;
	}
	BFS(arr, Q.front(), N, B);
}

int main()
{
	int N, M, V;
	int x, y;
	bool** arr;
	cin >> N >> M >> V;
	arr = new bool*[N+1];

	bool* B = new bool[N + 1];
	for (int i = 0; i < N + 1; i++)
	{
		B[i] = 0;
	}

	for (int i = 0; i < N+1; i++)
	{
		arr[i] = new bool[N+1];
	}

	for (int i = 0; i < M; i++)
	{
		cin >> x >> y;
		arr[x][y] = arr[y][x] = 1;
	}
	DFS(arr,V,N,B);
	for (int i = 0; i < N + 1; i++)
	{
		B[i] = 0;
	}
	cout << "\n";
	Q.push(V);
	B[V] = 1;
	BFS(arr, V, N, B);
	for (int i = 0; i <= N; i++)
	{
		delete[] arr[i];
	}
	delete[] arr;

	delete[] B;
}