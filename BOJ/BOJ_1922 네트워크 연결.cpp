#include<iostream>
#include<vector>

using namespace std;

int main()
{
	int N, M;
	cin >> N;
	cin >> M;
	int A, B, C, index = 0, min = 1000;
	int** w = new int* [N];
	for (int i = 0; i < N; i++)
	{
		w[i] = new int[N];
	}

	for (int i = 0; i < N; i++)
	{
		for (int j = 0; j < N; j++)
		{
			w[i][j] = 1000;//머든 edge를 무한대로
		}
	}

	for (int i = 0; i < M; i++)
	{
		cin >> A >> B >> C;
		w[A - 1][B - 1] = w[B - 1][A - 1] = C;
	}

	vector<bool>vertex(N);
	for (int i = 0; i < N; i++)
	{
		vertex[i] = false;
	}

	vertex[index] = true;//1이 처음 group에 들어감
	int sum = 0, p = 0,cnt=1;

	while (cnt != N)//그룹이 다 채워질때까지 반복
	{
		min = 1000;//
		for (int i = 0; i < vertex.size(); i++)
		{
			if (vertex[i] == false)
			{
				continue;
			}
			for (int j = 0; j < N; j++) {
				if (w[i][j] < min && vertex[j]==false)//최소 w보다 작으면서 그룹에 있지 않다면
				{
					min = w[i][j];
					p = j;
				}
			}

		}

		sum += min;
		vertex[p] = true;
		cnt++;
	}
	cout << sum;
	//1번부터 시작해서 그룹을 형성(1번이 짧은 edge를 고른 후 그 vertex를 자신의 그룹으로 합침
	//합친 후 그 그룹에서 가장 짧은 edge중에 그룹이 아닌 vertex 자신의 그룹으로 합침

	return 0;
}