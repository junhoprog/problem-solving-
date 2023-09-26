#include<iostream>
using namespace std;
int R, C;
bool move(int x,int y,int i,int**map,int count)
{
	bool check = 0;
	int temp=x+2*i;
	//i�� 1
	for (int j = 0; j <= i; j++)//�����¿츦 Ȯ���ϴµ� �ϳ���0�̳����� break
	{
		
		
		if (x + j >= R || y + j >= C||y-j<0 || temp >= R)//����� Ȯ������ �� �Ѵ´ٸ� ���ʿ� �Ұ���.
		{
			//cout <<"�ʰ�  " << x + j << " " << y + j << " " << y - j <<" "<<temp << endl;
			
			check = 0;
			break;
		}

		if (map[x+j][y - j] == 1)
		{
			check = 1;
		}
		else {
			check = 0;
			break;
		}

		if (map[x + j][y+j] == 1)
		{
			check = 1;
		}
		else {
			check = 0;
			break;
		}
		
		if (map[temp-j][y + j] == 1)//���� 1�̶��
		{
			check = 1;
		}
		else {
			check = 0;
			break;
		}

		if (map[temp-j][y-j] == 1)
		{
			check = 1;
		}
		else {
			check = 0;
			break;
		}
	}
	return check;
}

int main()
{

	int cnt=0;
	cin >> R >> C;
	string s;
	if (R < C)//1�� ������ �ľǽ� �ִ����� ������ ������ �ľ�
	{
		cnt = R;
	}
	else {
		cnt = C;
	}
	int cnt1 = 0, cnt2 = 0;
	int max_cnt1=0,max_cnt2= 0;
	int** map = new int*[R];//���̾Ʊ��� �����Ҵ�
	for (int i = 0; i < R; i++)
	{
		map[i] = new int[C];
	}

	for (int i = 0; i < R; i++)//�ʿ� ���̾� ���
	{
		cin >> s;
		for (int j = 0; j < s.length(); j++)
		{
			map[i][j] = (int)(s[j] - '0');
		}
	}

	cnt = cnt / 2 + 1;//2

	bool size_check = 0;
	int res = 0;

		for (int i = 0; i < cnt; i++)
		{
			// ��� ������ �˷��ִ� i
			size_check = 0;
			for (int x = 0; x < R-i; x++)
			{
				for (int y = 0; y < C-i; y++)
				{
					if (x + i >= R || y+i >= C)//����� Ȯ������ �� �Ѵ´ٸ� ���ʿ� �Ұ���.
					{
						size_check = 1;
						break;
					}
					
					if (move(x, y+i, i, map,cnt))//���̾� ã�� �Լ�, ã�Ҵٸ�
					{
						//cout <<i <<" " << x << " " << y << endl;
						size_check = 1;//ã�Ҵ� ǥ���ؼ� ������ �ٽ� ����
						res = i+1;
						break;
					}
				}
				if (size_check == 1)
				{
					break;
				}
			}
			
		}
		cout << res;
	return 0;
}