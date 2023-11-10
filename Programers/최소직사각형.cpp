#include<iostream>
#include<vector>
using namespace std;
int main()
{
	vector<vector<int>>v = { {10, 7},{12, 3},{8, 15},{14, 7},{5, 15} };
	
	for (int i = 0; i < v.size(); i++)
	{
		if (v[i][0] < v[i][1])
		{
			continue;
		}
		else {
			int temp = v[i][0];
			v[i][0] = v[i][1];
			v[i][1] = temp;
		}
	}
	int max1 = v[0][0];
	for (int i = 1; i < v.size(); i++)
	{
		if (max1 < v[i][0])
		{
			max1 = v[i][0];
		}
	}

	int max2 = v[0][1];
	for (int i = 1; i < v.size(); i++)
	{
		if (max2 < v[i][1])
		{
			max2 = v[i][1];
		}
	}

	int answer = 0;
	answer = max2 * max1;
	cout << answer;
	return 0;
}