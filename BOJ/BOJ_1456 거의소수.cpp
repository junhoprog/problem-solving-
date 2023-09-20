
//� ���� �Ҽ��� N���� ���϶�, �� ���� ���� �Ҽ�����Ѵ�.

#include<iostream>
#include<cmath>
#include<vector>

using namespace std;

int check_sqrt_count(long long int input, long long int min, long long int max) {
	//input �Ҽ�, max B
	int count = 0;
	int num = 2;
	//input 3 
	while (1) {
		long long int pow_num = pow(input, num);
		if (pow_num <= max && pow_num >= min) {
			count++;
		}
		if (pow_num >= max) break;
		num++;
	}
	return count;
}


int main()
{
	long long int A, B, cnt = 0, count = 0;
	vector<long long int>v;
	cin >> A >> B;
	int temp;
	cnt += check_sqrt_count(2,A, B);
	if (B!= 1) {
		v.push_back(2);

		for (long long int i = 3; i <= sqrt(B); i++)
		{
			for (long long int j = 0; j <= v.size(); j++) {
				if (i % v[j] == 0)//�Ҽ��� �ƴϱ� ������ �ѱ�
				{
					break;
				}
				if (j == v.size() - 1)//������ ���� �Ҽ�
				{
					v.push_back(i);
					cnt += check_sqrt_count(i,A, B);
				}
			}
		}
	}
	else {
		cout << 0;
		return 0;
	}
	cout << cnt;
	return 0;
}