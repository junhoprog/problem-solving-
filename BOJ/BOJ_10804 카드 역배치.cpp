#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;
int main()
{
	vector<int>v;
	int x, y;
	for (int i = 0; i < 20; i++)
	{
		v.push_back(i+1);
	}
	for (int i = 0; i < 10; i++) {
		cin >> x >> y;
		reverse(v.begin() + x - 1, v.begin() + y);
	}
	for (int i = 0; i < 20; i++)
	{
		cout << v[i] << " ";
	}
	return 0;
}