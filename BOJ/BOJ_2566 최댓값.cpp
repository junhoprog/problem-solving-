#include<iostream>
using namespace std;
int main()
{
	int num, max;
	int x, y;

	int** arr = new int* [9];
	for (int i = 0; i < 9; i++)
	{
		arr[i] = new int[9];
	}

	for (int i = 0; i < 9; i++)
	{
		for (int j = 0; j < 9; j++)
		{

			cin >> num;
			if (i == 0 && j == 0)
			{
				max = num;
				x = i;
				y = j;
			}

			arr[i][j] = num;
			if (max < num)
			{
				max = num;
				x = i;
				y = j;
			}
		}
	}
	cout << max << "\n" << x + 1 << " " << y + 1;
	return 0;
}