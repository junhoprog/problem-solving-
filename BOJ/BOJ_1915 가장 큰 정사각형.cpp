#include<iostream>
#include<vector>
#include<string>
using namespace std;

int max_length = 0;

int Min(int A, int B)
{
	if (A < B)
	{
		return A;
	}
	else {
		return B;
	}
}

void check(vector<vector<int>>graph, int N, int M)
{
	for (int i = 1; i <= N; i++)
	{
		for (int j = 1; j <= M; j++)
		{
			if (graph[i][j] != 0)
			{
				graph[i][j] = Min(graph[i - 1][j - 1], Min(graph[i - 1][j], graph[i][j - 1]))+1;
			}
			if (max_length < graph[i][j])
			{
				max_length = graph[i][j];
			}
		}
	}
}

int main()
{
	int N, M;
	cin >> N >> M;
	string s;
	vector<vector<int>>graph(N+1, vector<int>(M+1, 0));
	for (int i = 1; i <= N; i++)
	{
		cin >> s;
		for (int j = 1; j <= M; j++)
		{
			graph[i][j] = (s[j-1]-'0');
		}
	}

	check(graph, N, M);
	
	cout << max_length*max_length;
	//1번 시작하고나서 1번이끝나기전에 2번 시작시간이 되면 하나 더 늘려서 돌림
	return 0;
}