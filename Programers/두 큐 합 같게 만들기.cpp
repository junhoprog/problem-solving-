#include <string>
#include <vector>
#include<iostream>
#include<queue>
using namespace std;

void init_sum(long long int& sum1, long long int& sum2, vector<int>queue1, vector<int> queue2, long long int& max)
{
    for (int i = 0; i < queue1.size(); i++)
    {
        sum1 += queue1[i];
        if (max < queue1[i])
        {
            max = queue1[i];
        }
    }
    for (int i = 0; i < queue2.size(); i++)
    {
        sum2 += queue2[i];
        if (max < queue2[i])
        {
            max = queue2[i];
        }
    }
    // cout<<"\n";

}
int solve(int& size, int& answer, long long int& sum1, long long int& sum2, vector<int>queue1, vector<int> queue2)
{
    queue<int>q1;
    queue<int>q2;
    //queue�� ���ο� ���� q2,q1����

    for (int i = 0; i < queue1.size(); i++)
    {
        q1.push(queue1[i]);
    }

    for (int i = 0; i < queue2.size(); i++)
    {
        q2.push(queue2[i]);
    }
    //q1��q2�� ��������

    while (1) {
        //�� q�� ���� ���� ����� ���� ū���� ���� �Ϳ� �ִ� �����ʿ�

        if (answer > size * 3) // ���ϰ� �� Ƚ���� q1�� 3���̻� �ߴٸ� ����
        {
            return -1;
        }

        if (sum1 < sum2)
        {
            q1.push(q2.front());
            sum1 += q2.front();
            sum2 -= q2.front();
            q2.pop();
        }
        else if (sum1 > sum2) {
            q2.push(q1.front());
            sum2 += q1.front();
            sum1 -= q1.front();
            q1.pop();
        }
        //�� queue�� ���� �� ū q�� ���� q�� �ְ� ���� ���ϰ� ���� �۾�
        else {
            break;
            //�������ٸ� ����
        }
        answer++;//Ƚ�� ����
    }
    return answer;
}
int solution(vector<int> queue1, vector<int> queue2) {

    int answer = 0;
    long long int sum1 = 0;
    long long int sum2 = 0;
    long long int total_sum = 0;
    long long int max = 0;
    init_sum(sum1, sum2, queue1, queue2, max);//q1,q2 ���� ���ϱ�.
    total_sum = sum1 + sum2;
    int size = queue1.size();
    if (total_sum % 2 == 1)
    {
        return -1;
    }
    else if (total_sum / 2 < max)
    {
        return -1;
    }
    return solve(size, answer, sum1, sum2, queue1, queue2);
}

int main()
{
    vector<int>queue1;
    vector<int>queue2;
   
    cout << solution({ 3,2,7,2 }, {4,6,5,1});
}