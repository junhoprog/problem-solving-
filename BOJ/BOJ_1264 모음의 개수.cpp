#include<iostream>
#include<cstring>
using namespace std;

int main()
{
	while (1) {
		char a[257];
		int count = 0;

		fgets(a, 257, stdin);// 문자열 a를 입력받는다.
		int len = strlen(a);
		if (a[0] == '#')  // #이 입력되면 프로그램 종료
		{
			break;
		}
		for (int i = 0; i < len; i++)
		{
			if (a[i] == 'a' || a[i] == 'e' || a[i] == 'i' || a[i] == 'o' || a[i] == 'u' || a[i] == 'A' || a[i] == 'E' || a[i] == 'I' || a[i] == 'O' || a[i] == 'U') {
				count++;
			}
		}
		cout << count << "\n";
	}
	return 0;
}