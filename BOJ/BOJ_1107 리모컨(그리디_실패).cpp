#include<iostream>
#include<string>
using namespace std;
int main()
{

	int M,x;
	string N;
	bool ignore[10] = { 0, };//ó���� �� ������������
	cin >> N;
	cin >> M;
	string channel = "";

	for (int i = 0; i < M; i++) {
		cin >> x;
		ignore[x] = 1;//������ ��ȣ
	}
	int cnt = 1;
	int count = 0;
	bool check = 0;//0�̸� �� 1�̸� ū
	x = 0;

	if (stoi(N) == 100)
	{
		::cout << 0;
		return 0;
	}
	
	//8399 8400  8339 8340�ڿ��ִ°� ���� ���ڸ� ������ �־ ���°Դ� ������.  8388 8389  8377  8400   9 8 �̷��� Ǯ �� ���� ��������
	//8599 1 9 �϶� �� 5�� ���°� �ƴ϶� 6���ΰ��� �۰Ը��� �� ���ִ°� �� ���� 

	for (int i = 0; i < N.length(); i++)
	{
		cnt = 1;
		if (ignore[N[i] - '0'] == 0 && x==0) {//�ش� ��°�� ����x���
			
			channel += N[i];
			//::cout << channel << " ";
			count++;
			continue;
		}

		else {//��� �� ���
			//ó���� �߿�.
			while (1) {

				if (x == 0)//ó�� �ٲٴ°Ŷ��
				{
					if (N[i]-cnt>=0&&ignore[(N[i] - '0') - cnt ] == 0)//�����ؾ��ϴ� ��ȣ�ε� cnt��ŭ ���� �� �߰ߵȴٸ�
					{
						//�������� Ŀ����.
						check = 1;
						x++;
						channel += N[i] - cnt;
						//::cout << channel << " ";
						count++;
						break;
					}
					if (ignore[(N[i] - '0')+ cnt] == 0)//�����ؾ��ϴ� ��ȣ�� cnt��ŭ ū ���� �ȴٸ�
					{
						//�������� �۾ƾ���.
						check = 0;
						x++;
						channel+= N[i] + cnt;
						//::cout << channel << " ";
						count++;
						break;
					}
				}

				else {//ó���� �ƴ϶�� check���� ���缭 �־������

					if (check == 1)
					{
						for (int j = 9; j >=0; j--)
						{
							if (ignore[j] == 0)//���� ū ���� ã�� �� ���õ� ���� �ƴ϶��
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
	//�տ� �ݺ����� ���� �ڸ����� ���� ��

	if (stoi(N) >= 10) {
		//���ڸ���������� ex)1000 0�� 1 �� �����ٸ�  999+1�̾����
		//���ڸ� ���� ��쿡�� ����ū�� Ȯ��
		string least_channel = "";
		int count2 = 0;
		for (int i = 0; i < N.length() - 1; i++) {
			for (int j = 9; j >= 0; j--)
			{
				if (ignore[j] == 0)//���� ū ���� ã�� �� ���õ� ���� �ƴ϶��
				{
					least_channel += to_string(j);
					//::cout << least_channel << " ";
					count2++;
					break;
				}
			}
		}

		//���ڸ��� �� ���� ��� ex) 9999 �ε� 9�������ٸ� 10000-1
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
	//::cout << "count��" << count << " ����" << endl;
	if (stoi(N)>100&&stoi(N) - 100 < count)
	{
		::cout << stoi(N) - 100;
	}
	else if (x == 0)//��ȣ�� �����⸸��.
	{
		::cout << count;
	}
	else {
		::cout << count;
	}
	return 0;
}