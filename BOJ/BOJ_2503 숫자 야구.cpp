#include<iostream>
#include<vector>
#include<string>
using namespace std;

bool search(int j, vector<string>v, vector<string>w, vector<pair<int, int>>xy)
{
	int s1 = 0, b1 = 0;//�ش���ڰ� ������ �������� �Ǵ�.

	char A, B, C;//�� �ڸ� ���ڸ� �ְ�
	for (int e = 0; e < v.size(); e++) {//Ȯ���ϴ� ����ŭ �ݺ�.
		A = v[e][0], B = v[e][1], C = v[e][2];
		s1 = 0, b1 = 0;
		for (int q = 0; q < 3; q++)
		{
			//�� �ڸ��� Ȯ���Ѵ�.
			if (w[j][q] == A)//���� ���ΰ� �ϳ��� �ִٸ�
			{
				if (q == 0) {
					s1++;
				}
				else {
					b1++;
				}
			}
			else if (w[j][q] == B)
			{
				if (q == 1) {
					s1++;
				}
				else {
					b1++;
				}
			}
			else if (w[j][q] == C)
			{
				if (q == 2) {
					s1++;
				}
				else {
					b1++;
				}
			}

		}
		if (s1 == xy[e].first && b1 == xy[e].second && e != v.size() - 1) {//e�� �� Ŀ�����ʾҴٸ�
			continue;
		}
		else if (s1 == xy[e].first && b1 == xy[e].second && e == v.size() - 1)//��� ���Ǹ����Ѵٸ�
		{
			return true;
		}
		else {
			return false;
		}


	}
}
bool check(string s)
{
	if (s[0] == '0' || s[1] == '0' || s[2] == '0')//0�ΰ� ��� ���ֱ�
	{
		return true;
	}
	else if (s[0] == s[1] || s[1] == s[2] || s[0] == s[2]) {//������ �ϳ��� �ִٸ�
		return true;
	}

	else { return false; }
}
int main()
{
	int n, s, b, num, cnt = 0;
	string str;
	cin >> n;
	vector<pair<int, int>>xy;
	vector<string>v;//������ ����
	for (int i = 0; i < n; i++)
	{
		cin >> num >> s >> b;
		str = to_string(num);//���ڸ� ���ڿ���
		v.push_back(str);//���ڿ� �־��ְ�
		xy.push_back(make_pair(s, b));//strike, ball�� �ֱ�
	}

	vector<string>w;//���� ���ڵ�.
	for (int i = 123; i < 988; i++)
	{
		str = to_string(i);
		w.push_back(str);
	}

	//123�� ���� �� 1s, 1b�ƴѰ͵��� �����.
	for (int j = 0; j < w.size(); j++)//��� ���Ҹ� Ȯ���Ѵ�.
	{
		//���� ���� ���ڰ� �ϳ��� �ִ���Ȯ��
		if (check(w[j]))
		{
			//������ �ϳ��� �ִٸ�
			continue;
		}

		//123�����ؼ� �� �־��� �� 
		if (search(j, v, w, xy))//���� �� �����ϴ� �����.
		{
			cnt++;
		}
		else {
			continue;
		}
	}

	cout << cnt;
	return 0;
}
