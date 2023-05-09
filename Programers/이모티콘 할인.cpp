#include <string>
#include <vector>

using namespace std;

int emo_user = 0;
int price = 0;
vector<int>v;
int arr[4] = { 10,20,30,40 };
void dfs(vector<vector<int>> users, vector<int> emoticons)
{
	int temp_emouser = 0;
	int sum = 0;
	int* temp_price = new int[users.size()];
	for (int i = 0; i < users.size(); i++)
	{
		temp_price[i] = 0;
	}
	static bool* B = new bool[emoticons.size()];

	if (!v.empty())
	{
		for (int j = 0; j < users.size(); j++) {
			if (B[j] == 1)
			{
				continue;
			}

			else {
				for (int i = 0; i < emoticons.size(); i++)
				{

					if (users[j][0] <= v[i])
					{
						//할인율 만큼 더함.
						sum = sum + emoticons[i] * (100 - v[i]) / 100;//만약에 10퍼센트 였다면 90이 됨

						if (users[j][1] < sum)
						{
							temp_price[j] = 0;
							temp_emouser++;
							B[j] = 1;
						}

						else {
							temp_price[j] = sum;
							//더 비싸게 받으려면 할인 율 적을 때 ㅇㅋ 이면 확정
						}

					}

				}
			}

		}
		if (temp_emouser == users.size())
		{
			//만약에 모든 인원이 다 가입하면
			emo_user = temp_emouser;
			for (int i = 0; i < users.size(); i++) {
					price += temp_price[i];
				}
			return;
		}

	}

	//할인율이 더 작은 사람을 찾아서 계산시키기
	for (int i = 0; i < 4; i++)
	{
		v.push_back(arr[i]);
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

