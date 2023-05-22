#include <iostream>
#include<vector>
#include<map>
#include<string>

using namespace std;

map<string, int>m;
map<int, string>m2;
vector<string>v;

int main()
{
	ios_base::sync_with_stdio(0);
	cin.tie(0), cout.tie(0);
	//수록되어있는 포켓몬 N, 내가 맞춰야하는 문제의 개수 M
	//N개의 줄에 포켓몬의 번호가 1~N번 포켓몬이 한줄씩 입력으로돌어옴(모두영어 첫글자만 대문자고 나머지 소문자)
	//일부 포켓몬은 마지막 문자만 대문자일 수 있음. 이름 최대길이 20 최소 2
	//M개의 줄에 내가 맞춰야하는 문제 입력들어옴-> 알파벳으로 들어오면 포켓몬 번호 숫자로 들어오면 문자 출력

	int N, M;
	string s;

	cin >> N >> M;
	for (int i = 1; i <= N; i++)
	{
		cin >> s;
		m.insert({ s,i });
		m2.insert({ i,s });
	}
	
	for (int i = 0; i < M; i++)
	{
		cin >> s;
		if ('0' <= s[0] && s[0] <= '9')
		{
			cout <<m2[stoi(s)] << '\n';//숫자라면
			//정수
		}
		else {
			cout << m[s] << "\n";
		}
	}
		return 0;
}