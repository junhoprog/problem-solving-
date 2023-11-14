#include <string>
#include <vector>
#include<queue>
#include<iostream>
using namespace std;

vector<int> solution(vector<int> sequence, int k) {
    vector<pair<int, int>>result;
    queue<int>q;

    int sum = 0;
    int start = 0, end = 0;

    for (int i = 0; i < sequence.size(); i++)
    {
        sum += sequence[i];
        q.push(sequence[i]);
        end++;

        if (sum == k)
        {
            result.push_back(make_pair(start, end - 1));
            sum -= q.front();
            q.pop();
            start++;
            continue;
        }

        else if (sum > k) {
            //≥—¿∏∏È æ’ø° ª©±‚
            while (sum > k) {//≥—¿∏∏È ∞Ëº” æ’ø° ª©¡‹
                sum -= q.front();
                q.pop();
                start++;
            }
            if (sum == k)
            {
                result.push_back(make_pair(start, end - 1));
                sum -= q.front();
                q.pop();
                start++;
                continue;
                //ª©¡·¥ı¥œ ∞∞æ∆¡ˆ∏È
            }
        }
    }

    pair<int, int> min_num = make_pair(result[0].first, result[0].second);

    int temp_num;
    vector<int>answer;
    for (int i = 1; i < result.size(); i++)
    {
        if (min_num.second - min_num.first > result[i].second - result[i].first)
        {
            min_num.first = result[i].first;
            min_num.second = result[i].second;
        }
    }
    answer.push_back(min_num.first);
    answer.push_back(min_num.second);
    return answer;
}
int main()
{
    vector<int>v;
    v = solution({ 2, 2, 2, 2, 2 }, 6);
    for (int i = 0; i < v.size(); i++)
    {
        cout << v[i] << " ";
    }
    return 0;
}