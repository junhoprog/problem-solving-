#include<iostream>
#include<vector>
using namespace std;
int n;
vector<int>v;
vector<bool> visit;
int cnt = 0;
bool flag = false;

void check(int target)
{
	if (visit[target] == true && flag==false)//이미 방문했으면서 자기 자신으로 돌아온 곳이라면
	{
		cnt++;//수열 사이클이고
		flag = true;//표시
		return;
	}
		visit[target] = true;//해당 방문표시
		check(v[target - 1]);//다음 정점으로 이동
		//i->v[i-1]자리로 이동
		//visit을 사용해서 이미 이동했다는것을 보여줌
	
}
int main()
{
	int testcase,x;
	
	cin >> testcase;
	while (testcase > 0)
	{
		cin >> n;
		v.clear();
		visit.clear();
		cnt = 0;
		flag = false;
		//초기화

		for (int i = 0; i < n; i++)
		{
			cin >> x;
			v.push_back(x);
		}
		for (int i = 0; i <= n + 1; i++)
		{
			visit.push_back(false);
		}
		for (int i = 1; i <= n; i++)
		{
			if (visit[i] == false)//방문하지 않은 곳들만 본다.
			{
				flag = false;
				check(i);
			}
		}
		cout << cnt<<" ";
		testcase--;
	}
	return 0;
}