#include<iostream>
#include<string>
#include<algorithm>
using namespace std;
int main()
{
	//���ڿ����� �ܾ ������.
	//�ҹ���,����,����,Ư�����ڷ� �̷����
	//���۰��� ����x
	//<,>���ڿ����ִ� ��� �����ư��鼭 �����ϸ� <������ >���� �� ������ ������ ����.

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
				check = true;//check�� true�� �س��� ���� >���ö����� continue
				check2 = false;
				continue;
			}
			check =true;//check�� true�� �س��� ���� >���ö����� continue
			continue;
		}

		else if (str[i] == '>')
		{
			check = false;//�������� false
			index = i + 1;
			continue;
		}
		else if (check == true)//<>���̿� �� ����
		{
			continue;
		}

		if (str[i] == ' '&&check==false)//�ٱ��϶���
		{
			reverse(str.begin() + index, str.begin() + i);
			index = i + 1;
		}
		if (i == str.size() - 1)//�������� ��
		{
			reverse(str.begin() + index, str.end());
		}
		
		else if(check==false&&check2==false){//<>�ƴϸ鼭 ó�������ϴ� ���̶��
			index = i;
			check2 = true;
		}

		else if (check2 == true)
		{
			//�߰��������� �״�ΰ���
			continue;
		}
		

	}
	cout << str;
}

