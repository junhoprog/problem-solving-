#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;

int N, M;
vector<vector<int>>v;
vector<pair<int, int>>house;
vector<pair<int,int>>chicken;
vector<pair<int, int>>temp;
int min_num = 10000000;
int check()
{
	int temp_num = 10000000;
	int sum = 0;
	
	for (int i = 0; i < house.size(); i++)
	{
		for (int j = 0; j < temp.size(); j++)
		{
			int num = abs(house[i].first - temp[j].first) + abs(house[i].second - temp[j].second);
			temp_num = min(temp_num, abs(house[i].first - temp[j].first) + abs(house[i].second - temp[j].second));
		}
		sum += temp_num;
		temp_num = 10000000;
	}
	
	return sum;
}

void solve(int index)
{

	if (temp.size() == M)
	{
		//여기서 모든 거리 확인
		min_num = min(min_num, check());
	}

	for (int i = index; i < chicken.size(); i++)
	{
		temp.push_back(make_pair(chicken[i].first,chicken[i].second));
		solve(i + 1);
		temp.pop_back();
	}
}

int main()
{
	cin >> N >> M;
	int x;
	vector<int>temp;
	for (int i = 0; i < N; i++)
	{
		v.push_back(temp);
		for (int j = 0; j < N; j++)
		{
			cin >> x;
			if (x == 2)
			{
				chicken.push_back(make_pair(i, j));
			}
			else if (x == 1)
			{
				house.push_back(make_pair(i, j));
			}
			v[i].push_back(x);
		}
	}
	solve(0);
	cout << min_num;
	return 0;
}

/*
N*N도시 
도시의 빈 칸 치킨집 집 중 하나임 (r,c)형태로 나타내고 r행 c열 또는 위에서부터 r번째 칸, 왼쪽에서부터 c번째 칸 의미
r과 c는 1부터시작
치킨거리-> 집과 가장 가까운 치킨집 사이의 거리 즉, 집을 기준으로 정해지며, 각각의 집은 치킨 거리 갖고있음
이 도시의 치킨거리는 모든 집의 치킨 거리의 합
거리-> (r1-r2) +(c1-c2)
0은 빈칸 1은 집, 2는 치킨집

가장 적은 치킨집 수로 수익을 많이 낼 수 있는 개수 최대 M개를 출력

M개만 남겼을 때 가장 치킨도시값이 가장 클 때가 언제인가.

1. 2가 있는 위치를 다 기록한다.
2. 재귀를 사용해서 M개가 될때까지 모든 경우를 확인한다. 0번 1번 0번 2번... 1번 2번 이렇게 계속 확인
3. 합을 MAX로


*/