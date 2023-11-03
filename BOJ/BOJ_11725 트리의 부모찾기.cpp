#include<iostream>
#include<vector>
#include<queue>
using namespace std;
vector<int>v[100001];
vector<bool> visit(100001);
vector<int>parent(100001);
queue<int>q;

int main()
{
	int N,a,b;
	cin >> N;

	for (int i = 0; i < N - 1; i++) {
		cin >> a >> b;
		v[a].push_back(b);
		v[b].push_back(a);

	}
	for (int i = 0; i <= N; i++)
	{
		visit[i] = 0;
	}

	int i = 0;
	q.push(1);

	while (!q.empty()){
		i = q.front();//4
		q.pop();
		if (visit[i] == 0)
		{
			visit[i] = 1;
			for (int j = 0; j < v[i].size(); j++)
			{
				if (visit[v[i][j]] == 1)
				{
					continue;
				}
				else {
					q.push(v[i][j]);//4,6
					parent[v[i][j]] = i;//4와 6의 부모가 i 1임.
				}
			}
		}
	}

	for (int i = 2; i <= N; i++)
	{
		cout << parent[i] << "\n";
	}

	return 0;
}