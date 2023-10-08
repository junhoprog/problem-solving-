#include<iostream>
#include<string>
using namespace std;
int main()
{

	int M,x;
	string N;
	bool ignore[10] = { 0, };//처음엔 다 무시하지않음
	cin >> N;
	cin >> M;
	string channel = "";

	for (int i = 0; i < M; i++) {
		cin >> x;
		ignore[x] = 1;//무시할 번호
	}
	int cnt = 1;
	int count = 0;
	bool check = 0;//0이면 작 1이면 큰
	x = 0;

	if (stoi(N) == 100)
	{
		::cout << 0;
		return 0;
	}
	
	//8399 8400  8339 8340뒤에있는게 높은 숫자면 낮은걸 넣어서 빼는게더 빠르다.  8388 8389  8377  8400   9 8 이렇게 풀 수 없는 문제같음
	//8599 1 9 일때 꼭 5로 가는게 아니라 6으로가서 작게만든 후 빼주는게 더 빠름 

	for (int i = 0; i < N.length(); i++)
	{
		cnt = 1;
		if (ignore[N[i] - '0'] == 0 && x==0) {//해당 번째가 무시x라면
			
			channel += N[i];
			//::cout << channel << " ";
			count++;
			continue;
		}

		else {//경우 더 잡기
			//처음이 중요.
			while (1) {

				if (x == 0)//처음 바꾸는거라면
				{
					if (N[i]-cnt>=0&&ignore[(N[i] - '0') - cnt ] == 0)//무시해야하는 번호인데 cnt만큼 감소 후 발견된다면
					{
						//다음꺼는 커야함.
						check = 1;
						x++;
						channel += N[i] - cnt;
						//::cout << channel << " ";
						count++;
						break;
					}
					if (ignore[(N[i] - '0')+ cnt] == 0)//무시해야하는 번호가 cnt만큼 큰 곳이 된다면
					{
						//다음꺼는 작아야함.
						check = 0;
						x++;
						channel+= N[i] + cnt;
						//::cout << channel << " ";
						count++;
						break;
					}
				}

				else {//처음이 아니라면 check값에 맞춰서 넣어줘야함

					if (check == 1)
					{
						for (int j = 9; j >=0; j--)
						{
							if (ignore[j] == 0)//가장 큰 값을 찾을 때 무시된 곳이 아니라면
							{
								channel += to_string(j);
								//::cout << channel << " ";
								count++;
								break;
							}
						}
					}

					else if (check == 0)
					{
						for (int j = 0; j <= 9; j++)
						{
							if (ignore[j] == 0)
							{
								channel += to_string(j);
								//::cout << channel << " ";
								count++;
								break;
							}
						}
					}
					break;
				}
				cnt++;
			}
		}
	}
	//앞에 반복들은 같은 자릿수로 봤을 때

	if (stoi(N) >= 10) {
		//한자리수적은경우 ex)1000 0과 1 이 막혔다면  999+1이어야함
		//한자리 적은 경우에서 가장큰것 확인
		string least_channel = "";
		int count2 = 0;
		for (int i = 0; i < N.length() - 1; i++) {
			for (int j = 9; j >= 0; j--)
			{
				if (ignore[j] == 0)//가장 큰 값을 찾을 때 무시된 곳이 아니라면
				{
					least_channel += to_string(j);
					//::cout << least_channel << " ";
					count2++;
					break;
				}
			}
		}

		//한자리수 더 많은 경우 ex) 9999 인데 9가막혔다면 10000-1
		string many_channel = "";
		int count3 = 0;

		for (int i = 0; i < N.length() +1; i++) {
			if (i == 0)
			{
				for (int j = 1; j <= 9; j++)
				{
					if (ignore[j] == 0)
					{
						many_channel += to_string(j);
						//::cout << many_channel << " ";
						count3++;
						break;
					}
				}
			}
			else {
				for (int j = 0; j <= 9; j++)
				{
					if (ignore[j] == 0)
					{
						many_channel += to_string(j);
						//::cout << many_channel << " ";
						count3++;
						break;
					}
				}
			}
		}


		int temp = stoi(channel);
		int temp2 = stoi(least_channel);
		int temp3 = stoi(many_channel);

		if (temp > stoi(N))
		{
			count += temp - stoi(N);
		}
		else {
			count += (stoi(N) - temp);
		}

		if (temp2 > stoi(N))
		{
			count2 += temp2 - stoi(N);
		}
		else {
			count2 += (stoi(N) - temp2);
		}


		if (temp3 > stoi(N))
		{
			count3 += temp3 - stoi(N);
		}
		else {
			count3 += (stoi(N) - temp3);
		}

		count = min(count, count2);
		count = min(count, count3);
	}
	//::cout << "count는" << count << " 에요" << endl;
	if (stoi(N)>100&&stoi(N) - 100 < count)
	{
		::cout << stoi(N) - 100;
	}
	else if (x == 0)//번호를 누르기만함.
	{
		::cout << count;
	}
	else {
		::cout << count;
	}
	return 0;
}