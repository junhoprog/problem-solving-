#include<iostream>
#include<queue>
using namespace std;

	int N, K;
	bool visit[100001];
	void bfs(int a)
	{	
	queue<pair<int, int>>q;
	q.push(make_pair(a, 0));//������ġ �ְ� 0���� �ʱ�ȭ

	while (!q.empty())
	{
		int x = q.front().first;//��
		int cnt = q.front().second;//�̵��ð�
		q.pop();
		if (x == K)//����ã���� Ž������
		{
			cout << cnt;
			break;
		}
        if (x + 1 >= 0 && x + 1 < 100001) {
            if (!visit[x + 1]) {
                visit[x + 1] = true;
                q.push(make_pair(x + 1, cnt + 1));
            }
        }
        if (x - 1 >= 0 && x - 1 < 100001) {
            if (!visit[x - 1]) {
                visit[x - 1] = true;
                q.push(make_pair(x - 1, cnt + 1));
            }
        }
        if (2 * x >= 0 && 2 * x < 100001) {
            if (!visit[2 * x]) {
                visit[2 * x] = true;
                q.push(make_pair(2 * x, cnt + 1));
            }
        } 
    
	}
}

int main()
{
	cin >> N >> K;
	visit[N] = true;//���� ���� q�� ������ �ִ°� ����
	bfs(N);
	return 0;
}