#include<iostream>
#include<vector>
#include<string>
using namespace std;

bool search(int j, vector<string>v, vector<string>w, vector<pair<int, int>>xy)
{
	int s1 = 0, b1 = 0;//해당숫자가 가능한 숫자인지 판단.

	char A, B, C;//각 자리 숫자를 넣고
	for (int e = 0; e < v.size(); e++) {//확인하는 수만큼 반복.
		A = v[e][0], B = v[e][1], C = v[e][2];
		s1 = 0, b1 = 0;
		for (int q = 0; q < 3; q++)
		{
			//각 자리를 확인한다.
			if (w[j][q] == A)//같은 수인게 하나라도 있다면
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
		if (s1 == xy[e].first && b1 == xy[e].second && e != v.size() - 1) {//e가 다 커지지않았다면
			continue;
		}
		else if (s1 == xy[e].first && b1 == xy[e].second && e == v.size() - 1)//모든 조건만족한다면
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
	if (s[0] == '0' || s[1] == '0' || s[2] == '0')//0인것 모두 없애기
	{
		return true;
	}
	else if (s[0] == s[1] || s[1] == s[2] || s[0] == s[2]) {//같은게 하나라도 있다면
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
	vector<string>v;//유추할 숫자
	for (int i = 0; i < n; i++)
	{
		cin >> num >> s >> b;
		str = to_string(num);//숫자를 문자열로
		v.push_back(str);//문자열 넣어주고
		xy.push_back(make_pair(s, b));//strike, ball수 넣기
	}

	vector<string>w;//비교할 숫자들.
	for (int i = 123; i < 988; i++)
	{
		str = to_string(i);
		w.push_back(str);
	}

	//123을 했을 때 1s, 1b아닌것들을 지운다.
	for (int j = 0; j < w.size(); j++)//모든 원소를 확인한다.
	{
		//먼저 같은 숫자가 하나라도 있는지확인
		if (check(w[j]))
		{
			//같은게 하나라도 있다면
			continue;
		}

		//123부터해서 다 넣었을 때 
		if (search(j, v, w, xy))//만약 다 만족하는 수라면.
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
