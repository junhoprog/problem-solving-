#include<iostream>
#include<vector>
using namespace std;

int n;
vector<int>v[9];
bool visited[9] = {0,};
int seat[4] = { 0,0,0,0 };
int S[9];
int j = 0;
int out = 0;
int score=0;
int M_score=0;
int ening = 0;
void playGame()
{
	static int s=0;
	int t = 0;
	while (1) {
		for (int i = s; i < 9; i++)
		{
			if (S[i] == 0)
			{

				out++;
				if (out == 3)
				{
					ening++;
					s = i + 1;
					t = 1;
					break;
				}
			}

			else if (S[i] == 1)
			{
				if (seat[3] == 1)
				{
					seat[0] = 0;
					score++;
				}
				else {

				}
			}

			else if (S[i] == 2)
			{

			}

			else if (S[i] == 3)
			{

			}
			else if (S[i] == 4)
			{
				for (int i = 1; i <= 3; i++)
				{
					if (seat[i] == 1)
					{
						seat[i] = 0;
						score++;
					}
				}

			}
			
		}
		if (t == 1)
		{
			break;
		}
		s = 0;
	}

	M_score = max(score, M_score);
}
void permutation(int index)
{
	if (index == 9)
	{
		playGame();
		//game시작
	}
	else {
		for (int i = 0; i < 9; i++)
		{

			if (visited[i] == 0)
			{
				visited[i] = 1;
				S[index] = v[j][i];
				permutation(index + 1);
				visited[i] = 0;
			}
		}
	}
}

int main()
{
	cin >> n;
	for (int i = 0; i < n; i++)
	{
		for (int t = 0; t < 9; t++)
		{
			cin >> v[i][t];
		}
	}
	S[3] = v[j][0];
	visited[0] = 1;
	permutation(0);
	return 0;
}