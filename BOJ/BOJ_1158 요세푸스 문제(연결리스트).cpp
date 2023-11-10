#include<iostream>
#include<vector>
using namespace std;

typedef struct Node {
	int num;
	Node* nextNode;
}node;

int main()
{
	int N, K,cnt=0;
	cin >> N >> K;
	vector<int>v;

	node* HEAD;//ó������ Ȯ�γ��
	node* PREV;//������
	node* NEXT;//���ο��带 ������

	for (int i = 1; i <= N; i++)
	{
		NEXT->num = i;
		NEXT->nextNode = NULL;

		PREV = HEAD;
		for (int j = 1; j <= i; j++)
		{
			//HEAD���������̵�
			if (PREV->nextNode == NULL)//��
			{
				PREV->nextNode = NEXT;
			}
			PREV= PREV->nextNode;
			if (j == N)
			{
				NEXT->nextNode = HEAD;
				HEAD->num = HEAD->nextNode->num;
				HEAD->nextNode = HEAD->nextNode->nextNode;
			}
		}
	}
	PREV = HEAD;
	node* DEL;

	while(1)
	{
		int count = 1;
		if (count == 3)
		{
			DEL = PREV;
			v.push_back(DEL->num);
			if (PREV == DEL)
			{
				break;
			}
			PREV = PREV->nextNode;
			count = 1;
			continue;
		}
		PREV = PREV->nextNode;
		count++;
	}

	return 0;
}