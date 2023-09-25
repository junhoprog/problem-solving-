#include<iostream>
#include<map>
#include<algorithm>
#include<vector>
using namespace std;

char odd;

int main()
{
	map<char, int>m;
	m.insert({ 'A',0 });
	m.insert({ 'B',0 });
	m.insert({ 'C',0 });
	m.insert({ 'D',0 });
	m.insert({ 'E',0 });
	m.insert({ 'F',0 });
	m.insert({ 'G',0 });
	m.insert({ 'H',0 });
	m.insert({ 'I',0 });
	m.insert({ 'J',0 });
	m.insert({ 'K',0 });
	m.insert({ 'L',0 });
	m.insert({ 'M',0 });
	m.insert({ 'N',0 });
	m.insert({ 'O',0 });
	m.insert({ 'P',0 });
	m.insert({ 'Q',0 });
	m.insert({ 'R',0 });
	m.insert({ 'S',0 });
	m.insert({ 'T',0 });
	m.insert({ 'U',0 });
	m.insert({ 'V',0 });
	m.insert({ 'W',0 });
	m.insert({ 'X',0 });
	m.insert({ 'Y',0 });
	m.insert({ 'Z',0 });
	string str;
	cin >> str;
	sort(str.begin(), str.end());//AACCC->ACCCA
	vector<char>v;//체크
	for (int i = 0; i < str.length(); i++)
	{
		m[str[i]]++;//해당 map에 알파벳 개수 추가

		if (v.empty())//비어있으면
		{
			v.push_back(str[i]);
		}

		for (int j = 0; j < v.size(); j++)
		{
			if (v[j] == str[i])//이미같은게 있다면
			{
				break;
			}
			else if (j == v.size() - 1)
			{
				v.push_back(str[i]);
			}
			else {
				continue;
			}
		}

	}
	
	int e_cnt = 0;//짝수개수
	int o_cnt = 0;//홀수 개수
	for (int i = 0; i < v.size(); i++)
	{
		if (m[v[i]] % 2 == 0)
		{
			e_cnt++;
		}

		else if (m[v[i]] % 2 == 1)
		{
			odd = v[i];
			o_cnt++;
		}
	}

	string res = str;
	int t = 0;
	res.clear();
	if (o_cnt >= 2)//홀수가 2개라면 x
	{
		::cout << "I'm Sorry Hansoo";
		return 0;
	}

	for (int i = 0; i < v.size(); i++)//모든 알파벳이 반은 나와야함. 홀수라면 1가지가 남음.(모든 알파벳 나온 후)
	{
		for (int j = 0; j < m[v[i]] / 2; j++)
		{
			res += v[i];
		}
	}

	for (int i = 0; i < v.size(); i++)//홀수 일때 남는 1개를 처리함
	{
		if (m[v[i]] % 2)
		{
			res += v[i];
		}
	}
	for (int i = v.size() - 1; i >= 0; i--)//나머지 거꾸로 출력시킴
	{
		for (int j = 0; j < m[v[i]] / 2; j++)
		{
			res += v[i];
		}
	}
	::cout << res;

	return 0;
}
