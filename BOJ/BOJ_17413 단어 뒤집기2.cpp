#include<iostream>
#include<string>
#include<algorithm>
using namespace std;
int main()
{
	//문자열에서 단어만 뒤집기.
	//소문자,숫자,공백,특수문자로 이루어짐
	//시작과끝 공백x
	//<,>문자열에있는 경우 번갈아가면서 등장하며 <등장후 >등장 두 문자의 개수는 같다.

	string str;
	getline(cin, str);
	bool check = false;
	bool check2 = false;
	int index = 0;

	for (int i = 0; i < str.size(); i++)
	{
		if (str[i] == '<')
		{
			if (i != 0)
			{
				reverse(str.begin()+index, str.begin() + i);
				check = true;//check를 true로 해놓고 다음 >나올때까지 continue
				check2 = false;
				continue;
			}
			check =true;//check를 true로 해놓고 다음 >나올때까지 continue
			continue;
		}

		else if (str[i] == '>')
		{
			check = false;//나왔으니 false
			index = i + 1;
			continue;
		}
		else if (check == true)//<>사이에 글 무시
		{
			continue;
		}

		if (str[i] == ' '&&check==false)//바깥일때만
		{
			reverse(str.begin() + index, str.begin() + i);
			index = i + 1;
		}
		if (i == str.size() - 1)//끝지점일 때
		{
			reverse(str.begin() + index, str.end());
		}
		
		else if(check==false&&check2==false){//<>아니면서 처음시작하는 곳이라면
			index = i;
			check2 = true;
		}

		else if (check2 == true)
		{
			//중간지점들은 그대로가기
			continue;
		}
		

	}
	cout << str;
}

