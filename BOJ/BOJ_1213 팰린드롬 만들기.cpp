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
	vector<char>v;//üũ
	for (int i = 0; i < str.length(); i++)
	{
		m[str[i]]++;//�ش� map�� ���ĺ� ���� �߰�

		if (v.empty())//���������
		{
			v.push_back(str[i]);
		}

		for (int j = 0; j < v.size(); j++)
		{
			if (v[j] == str[i])//�̹̰����� �ִٸ�
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
	
	int e_cnt = 0;//¦������
	int o_cnt = 0;//Ȧ�� ����
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
	if (o_cnt >= 2)//Ȧ���� 2����� x
	{
		::cout << "I'm Sorry Hansoo";
		return 0;
	}

	for (int i = 0; i < v.size(); i++)//��� ���ĺ��� ���� ���;���. Ȧ����� 1������ ����.(��� ���ĺ� ���� ��)
	{
		for (int j = 0; j < m[v[i]] / 2; j++)
		{
			res += v[i];
		}
	}

	for (int i = 0; i < v.size(); i++)//Ȧ�� �϶� ���� 1���� ó����
	{
		if (m[v[i]] % 2)
		{
			res += v[i];
		}
	}
	for (int i = v.size() - 1; i >= 0; i--)//������ �Ųٷ� ��½�Ŵ
	{
		for (int j = 0; j < m[v[i]] / 2; j++)
		{
			res += v[i];
		}
	}
	::cout << res;

	return 0;
}
