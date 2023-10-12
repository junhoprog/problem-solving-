#include<iostream>
#include<string>
using namespace std;

bool check(int i, bool ignore[])
{
	string s = to_string(i);//현재값을 string화 시킨 후
	for (int j = 0; j < s.length(); j++)
	{
		if (ignore[s[j] - '0']) {//현재값은 숫자가 문자화된것이기때문에 일시적으로 '0'해줘서 숫자로 만듦
			return false;//무시되어있는 숫자가 한개라도 있다면 false
		}
	}
	return true;
}

int main()
{
	int N, M, x, temp;
	int min_cnt = 1000000;
	cin >> N;
	cin >> M;
	bool ignore[10] = { 0, };
	for (int i = 0; i < M; i++)
	{
		cin >> x;
		ignore[x] = true;
	}

	string s = to_string(N);//N을 스트링으로

	min_cnt = abs(N - 100);//목표값은 100부터 시작하기때문에 100만큼 빼준 값이 최소 cnt
	for (int i = 0; i < 1000001; i++)
	{
		if (check(i, ignore)) {//문자열마다 비교해서 동일한지여부파악
			temp = abs(N - i) + to_string(i).length();//목표값까지 더하거나 빼는거+ 누르는 버튼
			min_cnt = min(min_cnt, temp);//원래 최소cnt와 현재값 비교해서 작은 값이 횟수
		}
	}
	cout << min_cnt;
	return 0;
}