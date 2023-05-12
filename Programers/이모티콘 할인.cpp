#include <string>
#include <vector>

using namespace std;

int emo_user = 0;
int price = 0;
vector<int>v;
int arr[4] = { 10,20,30,40 };
void dfs(vector<vector<int>> users, vector<int> emoticons)
{
	int emo_tmp = 0;
	int price_tmp = 0;

	if (v.size() == emoticons.size())
	{
		for (int i = 0; i < users.size(); i++) {
			int sum = 0;

			for (int j = 0; j < emoticons.size(); j++) {
				if (users[i][0] <= v[j]) {
					sum = sum + emoticons[j] * (100 - v[j]) / 100;
				}
			}

			if (sum >= users[i][1]) { emo_tmp++; }
			else { price_tmp = price_tmp + sum; }
			


			if (emo_user < emo_tmp) {
				emo_user = emo_tmp;
				price = price_tmp;
			}
			
			else if (emo_user == emo_tmp && price < price_tmp) {
				price = price_tmp;
			}
			//계속 최신화
			return;

		}
	}

	//할인율이 더 작은 사람을 찾아서 계산시키기
	for (int i = 0; i < 4; i++)
	{
		v.push_back(arr[i]);//1111-> 2111....이 과정 계속 반복
		dfs(users, emoticons);
		v.pop_back();
	}
	//v에 
}
vector<int> solution(vector<vector<int>> users, vector<int> emoticons) {
	vector<int> answer;

	dfs(users,emoticons);
	answer.push_back(emo_user);
	answer.push_back(price);
	return answer;
}

