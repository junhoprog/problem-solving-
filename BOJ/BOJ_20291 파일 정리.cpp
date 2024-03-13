#include<iostream>
#include<vector>
#include<map>

using namespace std;

map<string, int> parsing(vector<string>v, map<string, int>result) {//.이후 문자를 골라서 map에 매핑시키고 있다면 추가 없다면 새로 만듦
	string temp = "";
	for (int i = 0; i < v.size(); i++)//갯수만큼 반복
	{
		temp = "";
		for (int j = 0; j < v[i].size(); j++) {//해당 문자열의 수만큼 반복
			if (v[i][j] == '.')//반복 중 .발견하면 그 이후 문자고려
			{
				j++;//.다음 문자로 이동
				while (j != v[i].size())//끝이 나올때까지
				{
					temp += v[i][j];//temp를 만듦.
					j++;
				}
				//temp에 값이 들어가있음
				if (result.find(temp) != result.end())//map에서 데이터찾았다면
				{
					result[temp]++;
				}
				else {//찾지 못하면
					result.insert({ temp,1 });
				}
				break;
			}

		}
	}
	return result;
}

int main()
{
	int N;
	string s;
	vector<string>v;
	map<string, int>result;
	cin >> N;
	for (int i = 0; i < N; i++) {
		cin >> s;
		v.push_back(s);
	}
	result = parsing(v, result);

	for (auto iter = result.begin(); iter != result.end(); iter++)//for문에 auto를 사용해 자동으로 iter라 증가하도록 만듦
	{
		cout << iter->first << " " << iter->second << endl;
	}
}
