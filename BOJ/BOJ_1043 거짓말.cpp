#include<iostream>
#include<vector>
using namespace std;

int n, m, x, f;
int num,party=0;
bool flag = false;
vector<int>fact;

void search(int i,vector<int> &fact,vector<int>v[])
{
	flag = false;
	for (int j = 0; j < v[i+1].size(); j++)//명수만큼 입력을 받을건데 만약에 fact안에 있는 인물이 하나라도 있다면 그 안에있는 얘들 다 fact 1로
	{
		if (fact[v[i+1][j]] == 1)
		{
			//사실을 아는 사람이 있다면
			flag = true;
		}
	}

	if (flag == true)
	{
		for (int j = 0; j < v[i + 1].size(); j++)
		{
			//cout << v[i + 1][j] << " ";
			fact[v[i + 1][j]] = 1;
		}
		//v에 있는 얘들 모두 fact에 박아.
	}
	//파티개수만큼 입력받음
}

int main()
{
	cin >> n >> m;
	cin >> f;
	vector<int>fact(n+1,0);
	for (int i = 0; i < f; i++)
	{
		cin >> x;
		fact[x] = 1;
	}

	vector<int>v[51];

	for (int i = 0; i < m; i++)
	{
		cin >> num;
		for (int j = 0; j < num; j++)
		{
			cin >> x;
			v[i + 1].push_back(x);
		}
	}

	for (int i = 0; i < n; i++)
	{
		for (int j = 0; j < m; j++)
		{
			search(j,fact,v);
		}
	}

	for (int i = 0; i < m; i++)
	{
		flag = false;
		for (int j = 0; j < v[i + 1].size(); j++)
		{
			if (fact[v[i + 1][j]] == 1)
			{
				flag = true;
				break;
			}
			else {
				continue;
			}
			//모든 v를 보는데 fact에 하나라도 값이 있는 것이라면 break;
		}
		if (flag == false) {
			//cout << i << " ";
			party++;
		}
	}
	cout << party;
	return 0;
}

