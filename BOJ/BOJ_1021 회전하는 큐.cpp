#include<iostream>
#include<deque>

using namespace std;
int main()
{
	//ť���� 3��������
	//1. ù��°���Ҹ� �̾Ƴ���. �� ���� �����ϸ� ���� ť�� ���Ұ� a1..ak���� a2...ak�Ͱ��̵ȴ�.(�Ǿտ� a1�� ���λ����.)
	//2. �������� ��ĭ �̵� a1...ak�� a2...aka1�� �ȴ�.
	//3.���������� ��ĭ �̵� a1...ak�� aka1...ak-1�̵�.

	//ó�� ���ԵǾ��ִ� �� N �����̰� �̾Ƴ������ϴ� ������ ��ġ �־���(ó�� ť������ ��ġ).
	//������� ���� �� ��� 2��,3�������� �ּڰ� ���

	deque<int>d;
	int N, M,x,count=0,index=0;
	cin >> N >> M;
	for (int i = 1; i <= N; ++i)
	{
		d.push_back(i);
	}
	while (M != 0)
	{
		cin >> x;
		for (int i = 0; i < d.size(); i++)
		{
			if (d[i] == x)
			{
				index = i;//������ġ�� index�� ÷���ư� �� ����
				break;
			}
		}

		if (index < d.size() - index)
		{
			//���� ��ġ �������� ��ü ���̿��� ���� ������ ������ ���� ���̿� ���� ����
			while (1)
			{
				if (d.front() == x)
				{
					d.pop_front();
					break;
				}
				count++;
				//�տ� �ִ� ���� �ڷ� �����鼭 �� �ո� �񱳸� ��.
				d.push_back(d.front());
				d.pop_front();
			}
		}
		else {
			while (1)
			{
				if (d.front() == x)
				{
					d.pop_front();
					break;
				}
				count++;
				//�ڿ��ִ� ���� �տ� �־���
				d.push_front(d.back());
				d.pop_back();
			}
		}
		M--;
	}
	cout << count;
	return 0;
}