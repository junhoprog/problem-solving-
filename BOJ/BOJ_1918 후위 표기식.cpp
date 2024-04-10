#include<iostream>
#include<stack>

using namespace std;



int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);

	string s;
	cin >> s;
	stack<char>str;
	char temp;
	for (int i = 0; i < s.size(); i++)
	{
		if (s[i] == 'A' || s[i] == 'B' || s[i] == 'C' || s[i] == 'D' || s[i] == 'E' || s[i] == 'F' || s[i] == 'G' || s[i] == 'H' || s[i] == 'I' || s[i] == 'J' || s[i] == 'K' || s[i] == 'L' || s[i] == 'M' || s[i] == 'N' || s[i] == 'O' || s[i] == 'P' || s[i] == 'Q' || s[i] == 'R' || s[i] == 'S' || s[i] == 'T' || s[i] == 'U' || s[i] == 'V' || s[i] == 'W' || s[i] == 'X' || s[i] == 'Y' || s[i] == 'Z')
		{
			cout << s[i];
			continue;
		}

		else if (s[i] == '(')
		{
			str.push(s[i]);
		}

		else if (s[i] == ')')
		{
			while (!str.empty() && str.top() != '(')
			{
				cout << str.top();
				str.pop();
			}
			str.pop();
		}

		else if (s[i] == '+' || s[i] == '-')
		{
			//(가 아니면 계속 빼줘도됨
			while (!str.empty() && str.top() !='(')
			{
				cout << str.top();
				str.pop();
			}
			str.push(s[i]);
		}

		else if (s[i] == '*' || s[i] == '/')
		{
			//D+A*B*C이면 앞부분*가 더 우선순위 높아서 얘를 처리하고 다음꺼가야함
			while (!str.empty() && (str.top() == '*' || str.top() == '/'))
			{
				cout << str.top();
				str.pop();
			}
			str.push(s[i]);
		}

	}

	while (!str.empty())
	{
		cout << str.top();
		str.pop();
	}
	//끝났는데 아직 스택에 남아있을 수도

	return 0;
}
//A+B*(C+D*E+F)
//ABCDE*+F+*+
/*

*, / 일때 앞에(이면 스택에 넣음
*,/인데앞에 ABC이면 앞에거 먼저 출력하고 *나오며
ABCDE*+
+*(+

*/
//A,B,C->그대로출력
//+,-는 스택에 저장
//*,/가 나왔을 때 스택에 +,-가 있다면 출력
//(가 나오면)가 나올때까지 다 담음
