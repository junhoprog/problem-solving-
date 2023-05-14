#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;
int main()
{

	int L, n, cnt = 0;
	cin >> L;
	vector<int>v(L);

	for (int i = 0; i < L; i++)
	{
		cin >> v[i];
	}
	cin >> n;
	if (v[0]>n)
	{
		v.emplace(v.begin(), 0);
		L += 1;
	}
	sort(v.begin(), v.end());

	for (int i = 0; i < L; i++)
	{
		if (v[i] == n)
		{
			cnt = 0;
			break;
		}
		else if (v[i] < n && n < v[i + 1])
		{
			for (int k = v[i] + 1; k <= n; k++) {//�պκ�
				for (int j = v[i] + 1; j < v[i + 1]; j++)
				{
					//v[i]=33 v[i+1]=100
					//n�� 59

					if (j < n)
					{
						continue;
					}
					else if (k >= j)
					{
						continue;
						//����
					}
					else {
						cnt++;
					}
					//�޺κ�

				}
			}
			break;
		}
	}
	//n�� �����ؾ��� 10�� �� 11 12x
	cout << cnt;
	return 0;
}