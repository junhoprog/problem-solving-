#include<iostream>
#include<vector>
using namespace std;
int main()
{
	//|가 밑으로 얼마나 있느지
	int N, M,cnt=0;
	cin >> N >> M; 
	char room[51][51];
	bool visit[51][51];
	char c;
	for (int i = 0; i < N; i++)
	{
		for (int j = 0; j < M; j++)
		{
			cin >> c;
			room[i][j] = c;
			visit[i][j] = false;
		}
	}

	int temp_i, temp_j;//잠시 값을 넣어둘 변수
	for (int i = 0; i < N; i++)
	{
		temp_i=i;

		for (int j = 0; j < M; j++)
		{
			temp_j = j;

			if (room[i][j] == '-'&&visit[i][j]==false)//-이면서 방문하지 않았다면
			{
				while (1)
				{
					if (room[i][j] == '-' && visit[i][j] == false)//방문하지 않았으면서 -리먄
					{
						visit[i][j] = true;
						j++;
						//오른쪽으로 쭉 가면서 visit과 j증가시킴
					}
					else {
						j = temp_j;//다시 원래 값으로 돌아가고
						cnt++;// cnt증가
						break;
					}
				}
			}

			else if (room[i][j] == '|' && visit[i][j] == false)// |이면서 방문하지 않았다면
			{
				while (1)
				{
					if (room[i][j] == '|' && visit[i][j] == false)
					{
						visit[i][j] = true;
						i++;
						//오른쪽으로 쭉 가면서 visit과 j증가시킴
					}
					else {
						i = temp_i;
						cnt++;
						break;
					}
				}
				//아래로 쭉 가면서 visit과 i증가시킴
			}
		}
	}
	cout << cnt;
	return 0;
}