#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;
int main()
{
	int N;
	cin >> N;
	vector<int>v;
	int x,min_num=200000,sum=0;

	for (int i = 0; i < N; i++)
	{
		cin >> x;
		v.push_back(x);//���� �ִ� ��ġ
	}
	sort(v.begin(), v.end());//����

	int result=0;
	int mid = (0 + v.size()) / 2;//�߰� ���� ã�´�.
	//�߰��� Ȱ��
	//Ȧ���� ����� 
	//¦���� ���ʿ����� ��
	if (v.size() % 2 == 1)
	{
		cout << v[mid];//��� ���̹Ƿ�
	}
	else {//¦���� �� ���ʰ� �������� ����
		int left = mid - 1;
		sum = 0;
		for (int i = 0; i < v.size(); i++)
		{
			sum += abs(v[i] - v[left]);//���ʰ��� ��
		}
		int sum2 = 0;
		int right = mid;
		for (int i = 0; i < v.size(); i++)
		{
			sum2 += abs(v[i] - v[right]);//�����ʰ��� ��
		}
		if (sum < sum2)//���ϰ�
		{
			cout << v[left];
		}
		else if(sum>sum2){
			cout << v[right];
		}
		else if (sum == sum2)//���� ��� ������ ���������ʹϱ� left���
		{
			cout << v[left];
		}
	}

	return 0;

}
