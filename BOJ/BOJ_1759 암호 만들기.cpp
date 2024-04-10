#include<iostream>
#include<algorithm>
using namespace std;
int j=0, m=0;
char moeum[5] = { 'a','e','i','o','u' };

void swap(int& a, int& b)
{
	int temp = a;
	a = b;
	b = temp;
}
void combination(char arr[], int depth,int next, int n, int r)
{
	if (depth == r)
	{
		m = 0;
		j = 0;
		for (int i = 0; i < r; i++)
		{
			if (arr[i] == 'a' || arr[i] == 'e' || arr[i] == 'i' || arr[i] == 'o' || arr[i] == 'u')
			{
				m++;
			}
			else {
				j++;
			}
		}
		if (m >= 1 && j >= 2)
		{
			for (int i = 0; i < r; i++)
			{
				cout << arr[i];
			}
		
			cout << "\n";
		}
		return;
	}

	for (int i = next; i <=n-r+depth; i++)//모음 최소 1개, 자음 최소 2개 포함되어야함.
	{
		swap(arr[i], arr[depth]);
		combination(arr, depth + 1,i+1, n, r);
		swap(arr[i], arr[depth]);
	}
}
int main()
{
	int r, n;
	char x;
	cin >> r>>n;

	char arr[15];
	for (int i = 0; i < n; i++)
	{
		cin >> x;
		arr[i] = x;
	}
	sort(arr, arr + n);
	combination(arr, 0,0, n, r);
	return 0;
}