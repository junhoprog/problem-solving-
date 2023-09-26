#include<iostream>
using namespace std;
int R, C;
bool move(int x,int y,int i,int**map,int count)
{
	bool check = 0;
	int temp=x+2*i;
	//i는 1
	for (int j = 0; j <= i; j++)//상하좌우를 확인하는데 하나라도0이나오면 break
	{
		
		
		if (x + j >= R || y + j >= C||y-j<0 || temp >= R)//사이즈를 확인했을 때 넘는다면 애초에 불가능.
		{
			//cout <<"초과  " << x + j << " " << y + j << " " << y - j <<" "<<temp << endl;
			
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
		
		if (map[temp-j][y + j] == 1)//밑이 1이라면
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
	if (R < C)//1의 개수를 파악시 최대사이즈가 가능한 개수를 파악
	{
		cnt = R;
	}
	else {
		cnt = C;
	}
	int cnt1 = 0, cnt2 = 0;
	int max_cnt1=0,max_cnt2= 0;
	int** map = new int*[R];//다이아광산 동적할당
	for (int i = 0; i < R; i++)
	{
		map[i] = new int[C];
	}

	for (int i = 0; i < R; i++)//맵에 다이아 기록
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
			// 몇번 도는지 알려주는 i
			size_check = 0;
			for (int x = 0; x < R-i; x++)
			{
				for (int y = 0; y < C-i; y++)
				{
					if (x + i >= R || y+i >= C)//사이즈를 확인했을 때 넘는다면 애초에 불가능.
					{
						size_check = 1;
						break;
					}
					
					if (move(x, y+i, i, map,cnt))//다이아 찾는 함수, 찾았다면
					{
						//cout <<i <<" " << x << " " << y << endl;
						size_check = 1;//찾았다 표시해서 사이즈 다시 조정
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