#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;
int N;
int gap = 10000;
vector<int>team;

int check(vector<vector<int>>v, int index)
{
	int sum1 = 0;
	int sum2 = 0;
	vector<bool>B(N + 1, false);
	for (int i = 0; i < team.size(); i++)
	{
		B[team[i]] = true;

		for (int j = i + 1; j < team.size(); j++)
		{
			sum1 += v[team[i] - 1][team[j] - 1];
			sum1 += v[team[j] - 1][team[i] - 1];
		}
		//만약 123이면 12 13 23을 모두 확인해야함
	}
	vector<int>team2;
	for (int i = 0; i < N / 2; i++)
	{
		team2.push_back(0);
	}
	int tmp = 0;
	for (int i = 0; i < N; i++)
	{
		if (B[i + 1] == false)
		{
			team2[tmp] = i + 1;
			tmp++;
		}
	}

	for (int i = 0; i < team2.size(); i++)
	{
		for (int j = i + 1; j < team2.size(); j++)
		{
			sum2 += v[team2[i] - 1][team2[j] - 1];
			sum2 += v[team2[j] - 1][team2[i] - 1];
		}
		//만약 123이면 12 13 23을 모두 확인해야함
	}
	return abs(sum1 - sum2);
}
void solve(vector<vector<int>>v, int index,int x)
{
	if (index == N / 2)
	{
		
		gap = min(gap, check(v, index));
		return ;
	}
	for (int i = x; i < N; i++)
	{
		team[index] += i + 1;
		solve(v,index+1, i + 1);
		team[index] -= i + 1;
	}
}

int main()
{
	cin >> N;
	vector<vector<int>>v(N, vector<int>(N));
	for (int i = 0; i < N; i++)
	{
		for (int j = 0; j < N; j++)
		{
			cin >> v[i][j];
		}
	}
	team.push_back(1);
	for (int i = 1; i < N / 2; i++)
	{
		team.push_back(0);
	}
	//12 34, 13 24, 14 23
	//123 456, 124 356,125 346, 126 345 ,134 256, 135 246
	/*첫번째 숫잔 1로 고정하고 2~N/2까지의 숫자들을 조합해서 만듦*/

	solve(v,1,1);
	cout << gap;

	return 0;
}

/*
N(짝수)명 N/2명 스타트/링크 팀
1~N 번호 배정, 능력치 조사 능력치 Sij는 i번사람과 j번 사람이 같은 팀 속했을 때
더해지는 능력치
팀의 능력치는 팀에 속한 모든 쌍의 능력치 Sij의 합
Sij != Sji , i번째 사람과 j번째 사람이 같은 팀이때 Sij, ji모두 더해줌

능력치 차이를 최소가 되게 만드는 팀구성
*/