#include<iostream>
#include<vector>
using namespace std;

int main()
{
	//���帹�� ���������̺��̴� ��������ã��
	//������ �������� ��Ÿ�� 1��°���� i,0���� i,���̼��Ф����� ��Ÿ��
	// A���� B�� �� �մ� ������ �Ƿ��� �� ������ �մ� ������ A�� B�� ������ �ٸ� ���������� �����ų� �������Ȥ��ƾ���
	//-> 565 (X) A5 4 B5 (OK)
	int N,h;
	vector<int>v;
	cin >> N;
	for (int i = 0; i < N; i++) {
		cin >> h;
		v.push_back(h);
	}

	int cnt = 0;
	int max = 0;
	bool check = false;


	//6 4 2-> 2�� ����
	//2 6 4 4�� ����
	for (int i = 0; i < N; i++)
	{
		//ó������ ����
		cnt = 0;//���̴� �ǹ����� �ľ� �ʱ�ȭ
		for (int j = i-1; j >=0; j--)
		{
			check = false;
			//�ڽ��� ���� ������ ������ ����
				//�ڽ��� ��ġ�� ���� �ǹ����� ũ��


				for (int t = i-1; t>=j+1; t--)
					//��ǥ ������ �߰� Ȯ��
				{
					if (v[t] >= v[j])
					{
						check = true;
						break;
					}
				}

				if (check == true)
				{
					continue;
				}
				else {
					cnt++;
				}
		}

		for (int j = i + 1; j < N; j++)
		{
			check = false;
			//�ڽ��� ���� ������ �������� ����
				//�ڽ��� ��ġ�� ���� �ǹ����� ũ��
			for (int t = i+1; t <j; t++)
				//��ǥ ������ �߰� Ȯ��
			{
				if (v[t] >= v[j])
				{
					check = true;
					break;
				}
			}

			if (check == true)
			{
				continue;
			}
			else {
				cnt++;
			}
			//i+1���� ������
		}


		if (max < cnt)
		{
			max = cnt;
		}

	}

	cout << max;
	return 0;
}