#include<iostream>
#include<vector>
using namespace std;
int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	int N, M, t;
	cin >> N >> M;
	vector<vector<int>>v(N+1,vector<int>(N+1,0));
	for (int i = 0; i < N; i++)
	{
		for (int j = 0; j < N; j++)
		{
			cin >> t;
			v[i + 1][j + 1] = v[i][j + 1] + v[i + 1][j] - v[i][j]+t;
		}
	}

	int x1, y1, x2, y2;
	int sum = 0;
	for (int i = 0; i < M; i++) {
		int x1, y1, x2, y2;
		cin >> y1 >> x1 >> y2 >> x2;

		cout << v[y2][x2] - v[y1 - 1][x2] - v[y2][x1 - 1] + v[y1 - 1][x1 - 1] << '\n';

	}
	return 0;
}
