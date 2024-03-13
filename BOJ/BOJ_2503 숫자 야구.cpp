#include<iostream>
#include<vector>
#include<map>

using namespace std;

map<string, int> parsing(vector<string>v,map<string, int>result) {
	string temp="";
	for (int i = 0; i < v.size(); i++)
	{
		temp = "";
		for (int j = 0; j < v[i].size(); j++) {
			if (v[i][j] == '.')
			{
				j++;
				while (j != v[i].size())
				{
					temp += v[i][j];
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
	map<string,int>result;
	cin >> N;
	for (int i = 0; i < N; i++) {
		cin >> s;
		v.push_back(s);
	}
	result=parsing(v,result);

	for (auto iter = result.begin(); iter != result.end(); iter++)
	{
		cout << iter->first << " " << iter->second << endl;
	}
}

