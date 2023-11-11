#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;
int main() {
	int N, K,x;
	vector<int>array;

	cin >>N>> K;
	for (int i = 0; i < N; i++)
	{
		cin >> x;
		array.push_back(x);
	}
	vector<vector<int>>commands(K);
	
	for (int i = 0; i < K; i++)
	{
		for (int j = 0; j < 3; j++)
		{
			cin >> x;
			commands[i].push_back(x);
		}
	}
	
		vector<int> answer;//vector배열에 값 넣기
		vector<int>v;
		int index = 0;
		for (int i = 0; i < commands.size(); i++)
		{
			v.clear();
			//j=1j<=4
			for (int j = commands[i][index] - 1; j <= commands[i][index + 1] - 1; j++)
			{
				v.push_back(array[j]);
			}
			sort(v.begin(), v.end());
			for (int q = 0; q < v.size(); q++)
			{
				cout << v[q] << " ";
			}
			cout << "\n";
			int select = commands[i][index + 2] - 1;
			answer.push_back(v[select]);
		}
		for (int i = 0; i < answer.size(); i++)
		{
			cout << answer[i] << " ";
		}
	return 0;
}