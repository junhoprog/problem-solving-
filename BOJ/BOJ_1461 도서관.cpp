#include<iostream>
#include<vector>
#include<algorithm>

using namespace std;

int main()
{
	int M, N, x;
	cin >> N >> M;//몇개의 도서, 들고다닐 권 수
	vector<int>v;

	for (int i = 0; i < N; i++)
	{
		cin >> x;
		v.push_back(x);
	}

	sort(v.begin(), v.end());

	int minus_cnt = 0, plus_cnt = 0;
	int num = 0;
	bool check2 = false;
	bool check3 = false;
	for (int i = 0; i < v.size(); i++)
	{
		if (v[i] < 0)
		{
			minus_cnt++;
		}
		else if (v[i] > 0)
		{
			plus_cnt++;
		}

		if (v.size() > 1&&i!=N-1&&v[i] < 0 && v[i + 1]>0)
		{
			num = i + 1;//전환점 확인
		}
		else if (i == 0 && v[i] > 0)
		{
			num = i;
			check2 = true;
		}
		else if (i == N - 1 && v[N - 1] < 0)
		{
			num = i+1;
			check3 = true;
		}
	}

	bool check = false;
	int sum = 0, temp = num;
	int max_num = max(abs(v[0]), abs(v[v.size() - 1]));//의 위치도 알아서 그 곳을 마지막에 가게해야함.

	while (1)
	{
		if (check2 == true)//모두 양수일 경우
		{
			break;
		}

		//cout <<"minus에요 " << sum <<endl;
		if (minus_cnt % M != 0 && check == 0)//나머지가 있을 경우
		{
			temp -= minus_cnt % M;

			check = 1;

			//끝
			if (temp <= 0)
			{
				if (abs(v[0]) == max_num)
				{
					sum += max_num;
				}

				else {
					sum += 2 * abs(v[0]);
				}

				check = 0;
				break;
			}
			//이후에 더 있을경우
			else {
				sum += 2 * abs(v[num - minus_cnt % M]);
				continue;
			}
		}

		else if (minus_cnt % M == 0 && check == 0)
		{
			//나머지없다는건 그 이후가 있다는것.
			check = 1;
		}


		if (check == 1 && temp - M > 0)//끝 지점이 아니라면
		{
			sum += 2 * abs(v[temp - M]);
			temp -= M;
		}

		else if (temp - M < 0)//
		{
			check = 0;
			break;
		}

		else if (check == 1 && temp - M == 0)//끝지점이라면
		{
			if (abs(v[0]) == max_num)//가장 긴 구간이 마이너스쪽이면
			{
				sum += max_num;//한 번 더함
			}

			else {
				sum += 2 * abs(v[0]);//그렇지않으면 왕복
			}
			check = 0;
			break;
		}
	}
	if (check3 != 1)
	{
		temp = num - 1;
	}
	int t = temp;
	while (1)
	{
		if (check3 == true)//모두 음수일 경우
		{
			break;
		}

		//cout << "plus에요 " << sum << endl;
		if (plus_cnt % M != 0 && check == 0)
		{
			temp += plus_cnt % M;
			check = 1;

			//끝
			if (temp >= N - 1)
			{
				if (abs(v[N - 1]) == max_num)
				{
					sum += max_num;
				}

				else {
					sum += 2 * abs(v[N - 1]);
				}
				break;
			}
			//이후에 더 있을경우
			else {
				sum += 2 * abs(v[t + plus_cnt % M]);
				continue;
			}
		}
		else if (plus_cnt % M == 0 && check == 0)
		{
			check = 1;
		}

		if (check == 1 && temp + M < v.size() - 1)//끝 지점이 아니라면
		{
			sum += 2 * abs(v[temp + M]);
			temp += M;
		}
		else if (temp + M > v.size() - 1)//두번가는것과 한번가는것도 확인해야함.
		{
			check = 0;
			break;
		}
		else if (check == 1 && temp + M == v.size() - 1)//끝지점이라면
		{
			if (abs(v[v.size() - 1]) == max_num)
			{
				sum += max_num;
			}

			else {
				sum += 2 * abs(v[v.size() - 1]);
			}
			break;
		}
	}
	cout << sum;
	return 0;
}