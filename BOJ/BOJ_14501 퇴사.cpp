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
		for (int j = 0; j < i; j++) {//이전꺼를 다시 돌아보면서 큰것있으면 다시 넣음
			if (time[j] + j <= i && i + time[i] <= n + 1) {//일하는 양이 넘지 않으면서 현재 인덱스보다 더 크지않은.
				DP[i] = max(DP[i], DP[j] + pay[i]);//둘중에더 큰것을 현재 dp에 넣음
			}
		}
	}

	int answer = 0;
	for (int i = 0; i <= n; i++) {//나온 수 중에 가장 큰것 뽑음
		answer = max(answer, DP[i]);
	}
	cout << answer;
	return 0;
}