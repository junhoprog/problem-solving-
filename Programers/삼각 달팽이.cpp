#include <string>
#include <vector>
#include<iostream>
using namespace std;

vector<int> solution(int n) {
    vector<int> answer;
    vector<vector<int>> map(n, vector<int>(n, 0));
    int num = 1;
    int x = 0, y = 0;
    int sum = 0;
    int temp = n;
    for (int i = 1; i <= n; i++)//ó�� n������ �ձ��ϱ�
    {
        sum += i;
    }
    while (n > 0) {
        //n�� 0�� �ɶ�����
        
        //����
        for (int i = 0; i < n; i++)//n��ŭ ���η� �������鼭 �� �ֱ�
        {
            map[x++][y] = num++;
        }
        x--;//x++�� ���� �� �� �� Ŀ���־ �Ѱ� ����
        if (num > sum)//���࿡ num�� ������ ����
        {
            break;
        }
        y++;//���� ���η� �������� y������Ŵ
        n--;//6->5->...Ƚ�� ���̱�
        //x=5 y=1
        
    //����
        for (int i = 0; i < n; i++)//n��ŭ ���η� �� �ֱ�
        {
            map[x][y++] = num++;
        }
        y--;//y++�� �� ���� Ŀ���ִ°� ���̱�
        if (num > sum)//������ ���߱�
        {
            break;
        }
        //x=5 y=5
        x--;
        y--;
        n--;
        //�밢��
        for (int i = 0; i < n; i++)//���� �밢�� �̵�
        {
            map[x--][y--] = num++;
        }
        x++;//���θ�ŭ �ø�.
        y++;
        if (num > sum)
        {
            break;
        }
        x++;
        n--;
    }

    for (int i = 0; i < temp; i++)
    {
        for (int j = 0; j < temp; j++)
        {
            if (map[i][j] == 0)
            {
                continue;
            }
            else {
                answer.push_back(map[i][j]);
            }
        }
    }
    return answer;
}
int main()
{
    vector<int>v;

    v = solution(6);
    for (int i = 0; i < v.size(); i++)
    {
        cout << v[i] << " ";
    }
    return 0;
}