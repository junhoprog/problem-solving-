/*#include<iostream>
#include<vector>
#include<algorithm>
#include<cmath>
using namespace std;

int main()
{
	int N;
	int x;
	vector<int>v;
	vector<int>v2;
	vector<int>v3;

	cin >> N;
	for (int i = 0; i < N; i++)
	{
		cin >> x;
		v.push_back(x);
	}
	v2 = v;

	sort(v2.begin(), v2.end());
	
	int count = 0;//����� ����
	int cnt = 0;//�ֺ�

	for (int i = 0; i < v2.size(); i++)
	{
		if (v2.size()==1)//1���� �� ���� �ֺ�
		{
			//1���϶�
			v3.push_back(v2[i]);
			break;
		}
		else {
			if (i == 0)
			{
				//��������쿡�� i=0�϶�
				count++;
				continue;
			}

			if (v2[i - 1] == v2[i])
			{
				count++;
			}
			else {
				// �����ʴٸ� cnt
				if (cnt == count)//cnt�� ���ٸ� �ֺ��� �������� ��������°ű⶧���� �־���
				{
					v3.push_back(v2[i - 1]);
				}

				else if (cnt < count)//cnt�� �� Ŀ���� �ֺ��� �ٲ���� �빮�� ���� �ٽó־���
				{
					v3.clear();
					v3.push_back(v2[i-1]);
					cnt = count;
				}
			}
		}
	}
	for (int i = 0; i < v3.size(); i++)
	{
		cout << v3[i] << " ";
	}
	cout << endl;
	double sum = 0;
	for (int i = 0; i < N; i++) {
		sum += v[i];
	}
	sum = round(sum / N);
	// -0 ��� ����
	if (sum == -0) {
		sum = 0;
	}
	cout << endl;
	cout << sum<<endl;
	cout << v2[v2.size() / 2]<<endl;
	if (v3.size() >1)
	{
		cout << v3[1] << endl;
	}
	else {
		cout << v3[0] << endl;
	}

	if (N == 1)
	{
		cout << 0;
	}
	else {
		cout << v2[v2.size() - 1] - v2[0];
		
	}return 0;
}*/

#include<iostream>
#include<vector>
using namespace std;
int main()
{
	vector<int>v2;
	vector<int>v3;
	v2.push_back(2);
	for (int i = 3; i < 100001; i++)
	{
		for (int j = 0; j <v2.size(); j++) {
			if (i % v2[j] == 0)
			{
				break;
			}
			if (j == v2.size() - 1)
			{
				v2.push_back(i);
			}
		}
	}
	int t,N;
	vector<int>v;
	cin >> t;
	for (int i = 0; i < t; i++)
	{
		cin >> N;
		v.push_back(N);
	}
	t = 0;
	int check = 0;
	int cnt = 0;
	while (t<v.size())
	{
		cnt = 0;
	for (int i = 0; i < v2.size(); i++)
	{
		cnt = 0;
		check = 0;
		while (v[t] % v2[i] == 0)
		{
			v[t] /= v2[i];
			cnt++;
			check = 1;
		}

		if (check == 1) { cout << v2[i] << " " << cnt << endl; }
		if (v[t] == 1)
		{
			break;
		}

	}
	t++;
	}

	return 0;
}