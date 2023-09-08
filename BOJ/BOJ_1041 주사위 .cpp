#include<iostream>
#include<algorithm>
#include<vector>

using namespace std;
int main()
{
	int A, B, C, D, E, F;
	long long int n;
	long long int sum = 0;
	int min = 0;
	int max = 0;
	cin >> n;
	cin >> A >> B >> C >> D >> E >> F;
	if (n == 1)
	{
		max = A;
		if (max < B)
		{
			max = B;
		}
		if (max < C)
		{
			max = C;
		}
		if (max < D)
		{
			max = D;
		}
		if (max < E)
		{
			max = E;
		}
		if (max < F)
		{
			max = F;
		}

		if (max == A)
		{
			sum = B + C + D + E + F;
		}
		else if (max == B)
		{
			sum = A + C + D + E + F;
		}
		else if (max == C)
		{
			sum = A + B + D + E + F;
		}
		else if (max == D)
		{
			sum = A + C + B + E + F;
		}
		else if (max == E)
		{
			sum = A + C + D + B + F;
		}
		else if (max == F)
		{
			sum = A + C + D + E + B;
		}
		cout << sum;
		return 0;
	}

	min = A;

	if (min > B)
	{
		min = B;
	}
	if (min > C)
	{
		min = C;
	}
	if (min > D)
	{
		min = D;
	}
	if (min > E)
	{
		min = E;
	}
	if (min > F)
	{
		min = F;
	}


	sum += (4 * (n - 1) * (n - 2) + (n - 2) * (n - 2)) * min;

	min = A + D;
	if (min > A + E)
	{
		min = A + E;
	}
	if (min > A + C)
	{
		min = A + C;
	}

	if (min > A + B)
	{
		min = A + B;
	}
	if (min > F + B)
	{
		min = F + B;
	}

	if (min > E + D)
	{
		min = E + D;
	}

	if (min > E + C)
	{
		min = E + C;
	}
	if (min > D + B)
	{
		min = D + B;
	}
	if (min > C + B)
	{
		min = C + B;
	}

	if (min > D + F)
	{
		min = D + F;
	}
	if (min > C + F)
	{
		min = C + F;
	}
	if (min > F + E)
	{
		min = F + E;
	}
	sum += (4 * (2 * n - 3)) * min;

	min = A + D + E;
	if (min > A + C + E)
	{
		min = A + C + E;
	}
	if (min > A + C + B)
	{
		min = A + C + B;
	}
	if (min > A + B + D)
	{
		min = A + B + D;
	}

	if (min > E + D + F)
	{
		min = E + D + F;
	}
	if (min > F + E + C)
	{
		min = E + F + C;
	}
	if (min > F + B + C)
	{
		min = F + B + C;
	}
	if (min > F + B + D)
	{
		min = F + B + D;
	}

	sum += 4 * min;
	cout << sum;
	return 0;
}