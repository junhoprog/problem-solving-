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
				//temp�� ���� ������
				if (result.find(temp) != result.end())//map���� ������ã�Ҵٸ�
				{
					result[temp]++;
				}
				else {//ã�� ���ϸ�
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

