#include<iostream>
#include<vector>
#include<algorithm>

using namespace std;
int main()
{
	//A등수 예상 B등수일 경우  |A-B|로 수치화  N명의 사람들의 불만도의 총 합을 최소로 하면서 학생들의 등수를 매기려고함
	int N,x;
	vector<int>v;
	cin >> N;
	for (int i = 0; i < N; i++)
	{
		cin >> x;
		v.push_back(x);
	}
	sort(v.begin(), v.end());
	long long int sum = 0;
	for (int i = 0; i < N; i++)
	{
		if (i + 1 - v[i] < 0)
		{
			sum += -1 * (i + 1 - v[i]);
		}
		else {
			sum += i + 1 - v[i];
		}
	}
	cout << sum;
	return 0;
		
}