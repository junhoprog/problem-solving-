#include <string>
#include <vector>
#include<iostream>
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
    //적을 때 많을 때 고려
    while (1) {
        if (answer > size * 3)
        {
            return -1;
        }
        if (sum1 < sum2)
        {
            queue1.push_back(queue2[0]);//3 2 7 2 4
            sum1 += queue2[0];
            sum2 -= queue2[0];
            queue2.erase(queue2.begin());//6 5 1
            //cout<<sum1<<" "<<sum2<<" \n";
        }
        else if (sum1 > sum2) {
            queue2.push_back(queue1[0]);//2 7 2 4
            sum2 += queue1[0];
            sum1 -= queue1[0];
            queue1.erase(queue1.begin());//6 5 1 3
            //cout<<sum1<<" "<<sum2<<" \n";
        }
        else {
            break;//sum1==sum2
        }
        answer++;
    }
    return answer;
}
int solution(vector<int> queue1, vector<int> queue2) {
    int answer = 0;
    long long int sum1 = 0;
    long long int sum2 = 0;
    long long int total_sum = 0;
    long long int max = 0;
    init_sum(sum1, sum2, queue1, queue2, max);
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
    queue1.push_back(3);
    queue1.push_back(2);
    queue1.push_back(7);
    queue1.push_back(2);

    queue2.push_back(4);
    queue2.push_back(6);
    queue2.push_back(5);
    queue2.push_back(1);
    cout<<solution(queue1, queue2);
}