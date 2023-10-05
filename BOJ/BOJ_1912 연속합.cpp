#include<iostream>
using namespace std;
int main()
{
	int N,max_num;
	cin >> N;
	int arr[100001] = { 0, };
	int DP[100001] = { 0, };
	for (int i = 0; i < N; i++) {
		cin >> arr[i];
		DP[i] = arr[i];
	}
	max_num = arr[0];//제일 큰 연속된 수의 합을 max_num 기록

	for (int i = 1; i < N; i++) {
		DP[i] = max(DP[i], DP[i - 1] + arr[i]);//더 큰 값을 DP[i]에 기록
		if (DP[i] > max_num) {
			max_num = DP[i];
		}
	}
	cout << max_num << endl;
	return 0;
}

