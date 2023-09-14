#include<iostream>
#include<queue>
using namespace std;

	int N, K;
	bool visit[100001];
	void bfs(int a)
	{	
	queue<pair<int, int>>q;
	q.push(make_pair(a, 0));//현재위치 넣고 0으로 초기화

	while (!q.empty())
	{
		int x = q.front().first;//값
		int cnt = q.front().second;//이동시간
		q.pop();
		if (x == K)//동생찾으면 탐색종료
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
	visit[N] = true;//같은 수를 q에 여러번 넣는거 방지
	bfs(N);
	return 0;
}