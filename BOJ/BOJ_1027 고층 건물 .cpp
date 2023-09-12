#include<iostream>
#include<vector>
using namespace std;

int main()
{
	//가장많은 고층빌딩이보이는 고층빌딩찾기
	//빌딩은 선분으로 나타냄 1번째빌딩 i,0부터 i,높이선분ㄴ으로 나타냄
	// A에서 B볼 수 잇는 빌딩이 되려면 두 지붕을 잇는 선분이 A와 B를 제외한 다른 고층빌딩을 지나거나 접하지안ㄶ아야함
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


	//6 4 2-> 2를 못봄
	//2 6 4 4를 못봄
	for (int i = 0; i < N; i++)
	{
		//처음부터 진행
		cnt = 0;//보이는 건물개수 파악 초기화
		for (int j = i-1; j >=0; j--)
		{
			check = false;
			//자신이 보는 곳에서 왼쪽을 볼때
				//자신의 위치가 보는 건물보다 크면


				for (int t = i-1; t>=j+1; t--)
					//목표 빌딩에 중간 확인
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
			//자신이 보는 곳에서 오른쪽을 볼때
				//자신의 위치가 보는 건물보다 크면
			for (int t = i+1; t <j; t++)
				//목표 빌딩에 중간 확인
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
			//i+1부터 끝까지
		}


		if (max < cnt)
		{
			max = cnt;
		}

	}

	cout << max;
	return 0;
}