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
		//���⼭ ��� �Ÿ� Ȯ��
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
N*N���� 
������ �� ĭ ġŲ�� �� �� �ϳ��� (r,c)���·� ��Ÿ���� r�� c�� �Ǵ� ���������� r��° ĭ, ���ʿ������� c��° ĭ �ǹ�
r�� c�� 1���ͽ���
ġŲ�Ÿ�-> ���� ���� ����� ġŲ�� ������ �Ÿ� ��, ���� �������� ��������, ������ ���� ġŲ �Ÿ� ��������
�� ������ ġŲ�Ÿ��� ��� ���� ġŲ �Ÿ��� ��
�Ÿ�-> (r1-r2) +(c1-c2)
0�� ��ĭ 1�� ��, 2�� ġŲ��

���� ���� ġŲ�� ���� ������ ���� �� �� �ִ� ���� �ִ� M���� ���

M���� ������ �� ���� ġŲ���ð��� ���� Ŭ ���� �����ΰ�.

1. 2�� �ִ� ��ġ�� �� ����Ѵ�.
2. ��͸� ����ؼ� M���� �ɶ����� ��� ��츦 Ȯ���Ѵ�. 0�� 1�� 0�� 2��... 1�� 2�� �̷��� ��� Ȯ��
3. ���� MAX��


*/