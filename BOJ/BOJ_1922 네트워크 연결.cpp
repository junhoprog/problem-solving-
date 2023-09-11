#include<iostream>
#include<vector>

using namespace std;

int main()
{
	int N, M;
	cin >> N;
	cin >> M;
	int A, B, C, index = 0, min = 1000;
	int** w = new int* [N];
	for (int i = 0; i < N; i++)
	{
		w[i] = new int[N];
	}

	for (int i = 0; i < N; i++)
	{
		for (int j = 0; j < N; j++)
		{
			w[i][j] = 1000;//�ӵ� edge�� ���Ѵ��
		}
	}

	for (int i = 0; i < M; i++)
	{
		cin >> A >> B >> C;
		w[A - 1][B - 1] = w[B - 1][A - 1] = C;
	}

	vector<bool>vertex(N);
	for (int i = 0; i < N; i++)
	{
		vertex[i] = false;
	}

	vertex[index] = true;//1�� ó�� group�� ��
	int sum = 0, p = 0,cnt=1;

	while (cnt != N)//�׷��� �� ä���������� �ݺ�
	{
		min = 1000;//
		for (int i = 0; i < vertex.size(); i++)
		{
			if (vertex[i] == false)
			{
				continue;
			}
			for (int j = 0; j < N; j++) {
				if (w[i][j] < min && vertex[j]==false)//�ּ� w���� �����鼭 �׷쿡 ���� �ʴٸ�
				{
					min = w[i][j];
					p = j;
				}
			}

		}

		sum += min;
		vertex[p] = true;
		cnt++;
	}
	cout << sum;
	//1������ �����ؼ� �׷��� ����(1���� ª�� edge�� �� �� �� vertex�� �ڽ��� �׷����� ��ħ
	//��ģ �� �� �׷쿡�� ���� ª�� edge�߿� �׷��� �ƴ� vertex �ڽ��� �׷����� ��ħ

	return 0;
}