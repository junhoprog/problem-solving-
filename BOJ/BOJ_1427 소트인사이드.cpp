#include<iostream>
#include<vector>
#include<algorithm>
#include<string>
using namespace std;
int main()
{
	string s;
	cin >> s;
	vector<char>v;
	for (int i = 0; i < s.size(); i++)
	{
		v.push_back(s[i]);
	}
	sort(v.begin(),v.end() ,greater<>());
	for (int i = 0; i < v.size(); i++)
	{
		cout << v[i];
	}
		return 0;
}