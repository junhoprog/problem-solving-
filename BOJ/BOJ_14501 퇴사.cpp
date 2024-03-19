#include<iostream>
#include<vector>
using namespace std;

int main()
{
	int DP[16] = { 0, };
	int pay[16] = { 0, };
	int time[16] = { 0, };
	int n;
	cin >> n;
	
	for (int i = 1; i <= n; i++) {
		cin >> time[i] >> pay[i];
		for (int j = 0; j < i; j++) {//�������� �ٽ� ���ƺ��鼭 ū�������� �ٽ� ����
			if (time[j] + j <= i && i + time[i] <= n + 1) {//���ϴ� ���� ���� �����鼭 ���� �ε������� �� ũ������.
				DP[i] = max(DP[i], DP[j] + pay[i]);//���߿��� ū���� ���� dp�� ����
			}
		}
	}

	int answer = 0;
	for (int i = 0; i <= n; i++) {//���� �� �߿� ���� ū�� ����
		answer = max(answer, DP[i]);
	}
	cout << answer;
	return 0;
}