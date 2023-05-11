#include<iostream>
using namespace std;

int main()
{
	int hour, minute, cook;

	cin >> hour >> minute >> cook;

	while (cook > 0) {
		if (cook >= 60)
		{
			hour++;
			cook -= 60;
			continue;
		}
		else {
			if (minute + cook >= 60)
			{
				hour++;
				minute = cook - (60 - minute);
				cook = -1;
			}
			else {
				minute = cook + minute;
				cook = -1;
			}
		}

	}
	if (hour >= 24)
	{
		hour = hour - 24;
	}
	cout << hour << " " << minute;
	return 0;
}