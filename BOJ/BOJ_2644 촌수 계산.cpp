#include<iostream>
#include<vector>

using namespace std;

bool flag = false;
vector<int>v[10000];
vector<int>v2;
vector<bool>visit;
void dfs(int n,int x,int y)
{
	visit[x] = true;
	//7
	//7 2
	for (int i = 0; i < v[x].size(); i++)
	{
		if (flag == true)
		{
			return;
		}
		if (visit[v[x][i]] == false)//�湮���� ���� ���̾����.
		{
			v2[v[x][i]] = v2[x] + 1;//�� �̼��� 1�� ���Ѹ�ŭ
			if (v[x][i] == y)
			{
				cout << v2[v[x][i]];
				flag = true;
				return;
			}
			
			dfs(n, v[x][i], y);

		}		
	}
	//7���� �����ؼ� 0��°�� 1������
	//x�� ������
	//
}
int main()
{
	int n;
	cin >> n;
	int target_x, target_y;
	cin >> target_x >> target_y;
	int m;
	cin >> m;
	int x, y;
	vector<bool>visit2(n+1, false);
	visit = visit2;
	vector<int> v3[10000];//-> ��������Ʈ
	vector<int> v4(n+1,0);
	v2 = v4;
	for (int i = 0; i < m; i++)
	{
		cin >> x >> y;
		v[x].push_back(y);
		v[y].push_back(x);
	}
	dfs(n,target_x,target_y);

	if (flag == false)
	{
		cout << -1;
	}
	return 0;
}