#include<iostream>
using namespace std;
int main()
{
	int N, M, T, j=0, s;
	long long sum = 1;
	cin >> T;
	s = T;
	long long* arr = new long long[T];

	while (T--) {
		sum = 1;
		int r = 1;
		cin >> N >> M;

		for (int i = M; i > M - N; i--)
		{
			sum *= i;
			sum /= r++;
		}
		arr[j] = sum;
		j++;
	}
	for (j = 0; j < s; j++)
	{
		cout << arr[j] << endl;
	}
	//��ġ�� �ʰ� N���� �ٸ� �����
	return 0;
}