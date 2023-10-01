#include<iostream>
using namespace std;

int main()
{
	int N, num, num_sum = 0;
	float sum=0;
	string s,grade;
	cin >> N;
	for (int i = 0; i < N; i++)
	{
		cin >> s >> num >> grade;
		num_sum += num;
		if (grade == "A+")
		{
			sum += num*4.3;
		}
		else if(grade=="A0")
		{
			sum += num*4.0;
		}
		else if (grade == "A-")
		{
			sum += num * 3.7;
		}
		else if (grade == "B+")
		{
			sum += num * 3.3;
		}
		else if (grade == "B0")
		{
			sum += num * 3.0;
		}
		else if (grade == "B-")
		{
			sum += num * 2.7;
		}
		else if (grade == "C+")
		{
			sum += num * 2.3;
		}
		else if (grade == "C0")
		{
			sum += num * 2.0;
		}
		else if (grade == "C-")
		{
			sum += num * 1.7;
		}
		else if(grade=="D+")
		{
			sum += num * 1.3;
		}
		else if (grade == "D0")
		{
			sum += num * 1.0;
		}
		else if (grade == "D-")
		{
			sum += num * 0.7;
		}
		else {
			sum += 0;
		}
	}
	cout << fixed;
	cout.precision(2);
	cout << sum / num_sum;
	return 0;
}