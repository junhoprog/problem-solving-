#include<iostream>
#include<cstring>
using namespace std;

int main()
{
	while (1) {
		char a[257];
		int count = 0;

		fgets(a, 257, stdin);// ���ڿ� a�� �Է¹޴´�.
		int len = strlen(a);
		if (a[0] == '#')  // #�� �ԷµǸ� ���α׷� ����
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