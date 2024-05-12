#include<iostream>
#include<cstring>
#include<vector>
using namespace std;

long long int max_num = 0;
void dfs(vector<pair<int, int>>v[], int i, long long int sum, bool visit[])
{
	if (visit[i]) {
		return;
	}
	visit[i] = true;//방문하면 true
	//v의 1번째부터 들어가면서 w를 더해줌 최대값을 계속 갱신함.
	//만약 다른 방향으로 빠지게 되면 뺴주고 더해줌
	for (int j = 0; j < v[i].size(); j++)
	{
		if (visit[v[i][j].first] == false)//갈 수 있는곳이면
		{
			sum += v[i][j].second;
			if (sum > max_num) {
				max_num = sum;
			}
			dfs(v, (v[i][j].first), sum, visit); //랑 연결되어있는 수를 들어가면서 w를 더해줌
			sum -= v[i][j].second;
		}
	}
}

int main()
{
	ios::sync_with_stdio(0);
	cin.tie(0); cout.tie(0);

	int n;
	cin >> n;

	int x, y, weight;
	vector<pair<int, int>>v[10001];
	bool visit[10001] = { false, };
	for (int i = 0; i < n - 1; i++)
	{
		cin >> x >> y >> weight;
		v[x].push_back(make_pair(y, weight));
		v[y].push_back(make_pair(x, weight));
	}

	for (int i = 1; i < n + 1; i++)
	{
		dfs(v, i, 0, visit);
		memset(visit, false, sizeof(visit));
	}
	cout << max_num;
	return 0;
}