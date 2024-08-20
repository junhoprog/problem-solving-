#include<iostream>
#include<vector>
#include<algorithm>

using namespace std;

int oper[4] = {0,0,0,0}; 
int min_num = 1000000001;
int max_num = -1000000001;
vector<int>v;
int N;

void sol(int result, int index)
{
	if (index == N - 1)
	{
		min_num = min(min_num, result);
		max_num = max(max_num, result);
	}

	else {
		for (int i = 0; i < 4; i++)
		{
			if (oper[i]> 0)
			{
				oper[i]--;
				switch (i) {
					case 0:
						sol(result + v[index+1],index + 1);
						break;
					case 1:
						sol(result - v[index + 1], index + 1);
						break;
					case 2:
						sol(result * v[index + 1], index + 1);
						break;
					case 3:
						sol(result / v[index + 1], index + 1);
						break;
				}
				oper[i]++;
			}
		}
	}

}

int main()
{
	int x;
	cin >> N;
	for (int i = 0; i < N; i++)
	{
		cin >> x;
		v.push_back(x);
	}

	for (int i = 0; i < 4; i++)
	{
		cin >> oper[i];
	}

	sol(v[0],0);
	cout << max_num<<"\n"<< min_num;

}
