#include<iostream>
#include<string>
#include<algorithm>
using namespace std;

int main()
{
	string s;
	string temp;
	cin >> s;
	int x=0;
	for (int i = 0; i < s.size(); i++) {
		temp = s[i];
		x += stoi(temp);

	}
	cout << x;

}