#include<iostream>
#include<vector>
using namespace std;
void dp(int** P, int k, int n)
{
	int sum = 0;
	if (k != 0)
	{
		dp(P, k - 1, n);//�ش���
		for (int i = 1; i <= n; i++)
		{
			for (int j = 1; j <= i; j++)
			{
				sum += P[k - 1][j];
			}
		}

		//k���� 0���� ������ 0���̸� 1~n������ ���ؼ� ���� p[k][n]�� �ֱ�
	}
	else {
		for (int i = 1; i <= n; i++) {
			P[0][i] = i;
		}
		//k�� 0���� ���� ���� �־��ְ� �̰����� �������� ä����
	}
	//��� �س���
}

int main()
{
	//a�� bȣ�� ����� a-1���� 1ȣ���� bȣ���� 
	//������� ���� �ո�ŭ ������� �����;��Ѵ�.

	//0�� iȣ->i��
	int T, k, n, d = 0;
	cin >> T;
	int* arr = new int[T];

	while (T > 0) {
		cin >> k;
		cin >> n;
		int** P = new int* [k];
		for (int i = 0; i < k; i++)
		{
			P[i] = new int[n + 1];
		}
		dp(P, k, n);
		arr[d] = P[k][n];
		d++;
		T--;
	}
	for (int i = 0; i < d; i++)
	{
		cout << arr[i] << endl;
	}
	return 0;
}