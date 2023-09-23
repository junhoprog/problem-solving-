#include<iostream>
#include<cmath>
#include<vector>
using namespace std;
int main()
{
	int t;
	double r;
	vector<int>v;
	int x1, y1, x2, y2;
	double r1, r2;
	cin >> t;
	while (t > 0)
	{
		cin >> x1 >> y1 >> r1 >> x2 >> y2 >> r2;//입력
		r = sqrt(pow(x1 - x2, 2) + pow(y1 - y2, 2));//점과 점사이거리

		double distance=0;
		distance=r1 < r2 ? r2 - r1 : r1 - r2;

		if (r==0&& r1==r2)//완전히 일치
		{
			v.push_back(-1);
		}

		else if (r < r1 + r2&& distance<r)//두 점이 만날 때
		{
			v.push_back(2);
		}

		else if (r == r1 + r2|| distance == r)//한 점만 만날 때
		{
			v.push_back(1);
		}

		else {
			v.push_back(0);
		}
		t--;

	}
	for (int i = 0; i < v.size(); i++)
	{
		cout << v[i] << endl;
	}
	return 0;
}