#include<iostream>
#include<vector>
using namespace std;
int main()
{
	//|�� ������ �󸶳� �ִ���
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

	int temp_i, temp_j;//��� ���� �־�� ����
	for (int i = 0; i < N; i++)
	{
		temp_i=i;

		for (int j = 0; j < M; j++)
		{
			temp_j = j;

			if (room[i][j] == '-'&&visit[i][j]==false)//-�̸鼭 �湮���� �ʾҴٸ�
			{
				while (1)
				{
					if (room[i][j] == '-' && visit[i][j] == false)//�湮���� �ʾ����鼭 -����
					{
						visit[i][j] = true;
						j++;
						//���������� �� ���鼭 visit�� j������Ŵ
					}
					else {
						j = temp_j;//�ٽ� ���� ������ ���ư���
						cnt++;// cnt����
						break;
					}
				}
			}

			else if (room[i][j] == '|' && visit[i][j] == false)// |�̸鼭 �湮���� �ʾҴٸ�
			{
				while (1)
				{
					if (room[i][j] == '|' && visit[i][j] == false)
					{
						visit[i][j] = true;
						i++;
						//���������� �� ���鼭 visit�� j������Ŵ
					}
					else {
						i = temp_i;
						cnt++;
						break;
					}
				}
				//�Ʒ��� �� ���鼭 visit�� i������Ŵ
			}
		}
	}
	cout << cnt;
	return 0;
}