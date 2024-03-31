/*
#include<iostream>
#include<vector>
#include<algorithm>
#include<map>
using namespace std;
int x, N, M;
vector<int>v;
vector<int>cnt;
void search(int target,int N,map<int,int>m)
{
	int start = 0;//시작 위치
	int end = N - 1;//끝위치
	int flag = false;//찾았는지 여부
	int count = 0;//같은 숫자 개수
	while (start <= end)
	{
		count = 0;
		int mid = (start + end) / 2;
		if (v[mid] == target)
		{
			cnt.push_back(m[target]);
			flag = true;
			break;
		}
		else if (v[mid] < target)
		{
			start = mid + 1;
		}
		else if (v[mid] > target)
		{
			end = mid - 1;
		}
	}
	if (flag == false)
	{
		cnt.push_back(0);
	}
}
// -10 -10 2 3 3 6 7 10 10 10
int main()
{
	ios_base::sync_with_stdio(0);
	cin.tie(0); 
	cout.tie(0);
	cin >> N;
	map<int,int>m;
	for (int i = 0; i < N; i++)
	{
		cin >> x;
		v.push_back(x);
		m.insert({ x,++m[x] });
	}
	sort(v.begin(), v.end());
	cin >> M;
	vector<int>w;
	for (int i = 0; i < M; i++)
	{
		cin >> x;
		w.push_back(x);
	}
	for (int i = 0; i < M; i++)
	{
		search(w[i],N,m);
	}
	for (int i = 0; i < cnt.size(); i++)
	{
		cout << cnt[i] << " ";
	}
	return 0;
}*/


/*#include<iostream>
#include<vector>
#include<algorithm>

using namespace std;
int x, N, M;
vector<int>v;
vector<int>cnt;
void search(int target, int N)
{
	int start = 0;
	int end = N - 1;
	int flag = false;
	int count = 0;
	while (start <= end)
	{
		count = 0;
		int mid = (start + end) / 2;
		if (v[mid] == target)
		{
			//자신과 같은 숫자가 몇개인지 파악하고 해당 cnt개수를 넣어줌.

			int temp = mid;
			while (temp > -1)
			{
				if (v[temp] != target)
				{
					break;
				}
				else {
					count++;
				}

				temp--;
				//왼쪽 다른거 나올때까지

			}
			temp = mid + 1;
			//다시 원위치
			while (temp < v.size())
			{
				if (v[temp] != target)
				{
					break;
				}
				else {
					count++;
				}
				temp++;
				//오른쪽 다른거 나올때까지
			}
			cnt.push_back(count);
			flag = true;
			break;
		}
		else if (v[mid] < target)
		{
			start = mid + 1;
		}
		else if (v[mid] > target)
		{
			end = mid - 1;
		}
	}
	if (flag == false)
	{
		cnt.push_back(0);
	}
}

int main()
{
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	cin >> N;
	for (int i = 0; i < N; i++)
	{
		cin >> x;
		v.push_back(x);
	}
	sort(v.begin(), v.end());
	cin >> M;
	vector<int>w;
	for (int i = 0; i < M; i++)
	{
		cin >> x;
		w.push_back(x);
	}
	for (int i = 0; i < M; i++)
	{
		search(w[i], N);
	}
	for (int i = 0; i < cnt.size(); i++)
	{
		cout << cnt[i] << " ";
	}
	return 0;
}*/

#include<iostream>
#include<vector>
#include<map>
using namespace std;
int x, N, M;
vector<int>v;

// -10 -10 2 3 3 6 7 10 10 10
int main()
{
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	//시간초과를 줄일 수 있는 함수들.
	
	cin >> N;
	map<int, int>m;
	for (int i = 0; i < N; i++)
	{
		cin >> x;
		v.push_back(x);
		m.insert({ x,++m[x] });//해당 정수들의 개수를 저장해놓고
	}
	cin >> M;
	for (int i = 0; i < M; i++)
	{
		cin >> x;
		if (m.find(x) == m.end())
		{
			cout << 0 << " ";
		}
		else {//해당 정수가 발견되는 것들만 출력
			cout << m[x] << " ";
		}
	}
	return 0;
}