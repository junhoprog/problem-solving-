/*
#include<iostream>
#include<map>
using namespace std;
int main()
{
	map<char, int>m;
	m.insert({ 'a', -1 });
	m.insert({ 'b',-1 });
	m.insert({ 'c',-1 });
	m.insert({ 'd',-1 });
	m.insert({ 'e',-1 });
	m.insert({ 'f', -1 });
	m.insert({ 'g',-1 });
	m.insert({ 'h',-1 });
	m.insert({ 'i',-1 });
	m.insert({ 'j',-1 });
	m.insert({ 'k', -1 });
	m.insert({ 'l',-1 });
	m.insert({ 'm',-1 });
	m.insert({ 'n',-1 });
	m.insert({ 'o',-1 });
	m.insert({ 'p', -1 });
	m.insert({ 'q',-1 });
	m.insert({ 'r',-1 });
	m.insert({ 's',-1 });
	m.insert({ 't',-1 });
	m.insert({ 'u', -1 });
	m.insert({ 'v',-1 });
	m.insert({ 'w',-1 });
	m.insert({ 'x',-1 });
	m.insert({ 'y',-1 });
	m.insert({ 'z',-1 });

	string str;
	cin >> str;
	for (int i = 0; i < str.length(); i++)
	{
		if (m[str[i]] == -1)
		{
			m[str[i]] = i;
		}
	}
	for (auto iter = m.begin(); iter != m.end(); iter++)
	{
		cout << iter->second << " ";
	}
	return 0;
}
//map���
*/
#include<iostream>
#include<string>
using namespace std;
int main()
{
	int alpha[26] = { -1, };
	string str;
	cin >> str;

	for (char i = 'a'; i <= 'z'; i++)
	{
		//i�� ��� �������� i�� �����Ѱ��� �߰��ϸ� �� ��ġ �����Ը���.
		if (str.find(i) == -1)
		{
			cout << -1 << " ";
		}
		else {
			cout << str.find(i) << " ";//ó�� �߰��� �͸� ����ϱ� ������ �� ������ ���� �ߺ�����x
		}
	}
	return 0;
}