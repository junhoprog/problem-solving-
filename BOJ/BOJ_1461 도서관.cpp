#include<iostream>
#include<vector>
#include<algorithm>

using namespace std;

int main()
{
	int M, N, x;
	cin >> N >> M;//��� ����, ���ٴ� �� ��
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
			num = i + 1;//��ȯ�� Ȯ��
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
	int max_num = max(abs(v[0]), abs(v[v.size() - 1]));//�� ��ġ�� �˾Ƽ� �� ���� �������� �����ؾ���.

	while (1)
	{
		if (check2 == true)//��� ����� ���
		{
			break;
		}

		//cout <<"minus���� " << sum <<endl;
		if (minus_cnt % M != 0 && check == 0)//�������� ���� ���
		{
			temp -= minus_cnt % M;

			check = 1;

			//��
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
			//���Ŀ� �� �������
			else {
				sum += 2 * abs(v[num - minus_cnt % M]);
				continue;
			}
		}

		else if (minus_cnt % M == 0 && check == 0)
		{
			//���������ٴ°� �� ���İ� �ִٴ°�.
			check = 1;
		}


		if (check == 1 && temp - M > 0)//�� ������ �ƴ϶��
		{
			sum += 2 * abs(v[temp - M]);
			temp -= M;
		}

		else if (temp - M < 0)//
		{
			check = 0;
			break;
		}

		else if (check == 1 && temp - M == 0)//�������̶��
		{
			if (abs(v[0]) == max_num)//���� �� ������ ���̳ʽ����̸�
			{
				sum += max_num;//�� �� ����
			}

			else {
				sum += 2 * abs(v[0]);//�׷��������� �պ�
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
		if (check3 == true)//��� ������ ���
		{
			break;
		}

		//cout << "plus���� " << sum << endl;
		if (plus_cnt % M != 0 && check == 0)
		{
			temp += plus_cnt % M;
			check = 1;

			//��
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
			//���Ŀ� �� �������
			else {
				sum += 2 * abs(v[t + plus_cnt % M]);
				continue;
			}
		}
		else if (plus_cnt % M == 0 && check == 0)
		{
			check = 1;
		}

		if (check == 1 && temp + M < v.size() - 1)//�� ������ �ƴ϶��
		{
			sum += 2 * abs(v[temp + M]);
			temp += M;
		}
		else if (temp + M > v.size() - 1)//�ι����°Ͱ� �ѹ����°͵� Ȯ���ؾ���.
		{
			check = 0;
			break;
		}
		else if (check == 1 && temp + M == v.size() - 1)//�������̶��
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