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

	node* HEAD;//처음임을 확인노드
	node* PREV;//현재노드
	node* NEXT;//새로운노드를 담을거

	for (int i = 1; i <= N; i++)
	{
		NEXT->num = i;
		NEXT->nextNode = NULL;

		PREV = HEAD;
		for (int j = 1; j <= i; j++)
		{
			//HEAD에서부터이동
			if (PREV->nextNode == NULL)//끝
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