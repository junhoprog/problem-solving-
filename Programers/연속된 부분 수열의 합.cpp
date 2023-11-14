#include <string>
#include <vector>
#include<queue>
#include<iostream>
using namespace std;

vector<int> solution(vector<int> sequence, int k) {
    vector< pair <vector<int>, pair<int, int> > >result;
    queue<int>q;
    vector<int>temp;
    int sum = 0;
    int start = 0 , end = 0;
    for (int i = 0; i < sequence.size(); i++)
    {
        temp.clear();
        
        sum += sequence[i];
        q.push(sequence[i]);
        end++;

        if (sum < k)
        {
            continue;
        }
        else if (sum == k)
        {
            for (int  t= start; t < end; t++)
            {
                temp.push_back(sequence[t]);
            }
            result.push_back(make_pair(temp, make_pair(start, end-1)));
            sum -= q.front();
            q.pop();
            start++;
            continue;
        }
        else {
            //≥—¿∏∏È æ’ø° ª©±‚
            while (sum > k) {//≥—¿∏∏È ∞Ëº” æ’ø° ª©¡‹
                sum -= q.front();
                q.pop();
                start++;
            }
            if (sum == k)
            {
                for (int t = start; t < end; t++)
                {
                    temp.push_back(sequence[t]);
                }
                result.push_back(make_pair(temp, make_pair(start,end-1) ) );
                sum -= q.front();
                q.pop();
                start++;
                continue;
                //ª©¡·¥ı¥œ ∞∞æ∆¡ˆ∏È
            }
        }
    }
    /*for (int i = 0; i < result.size(); i++)
    {
        cout << result[i].second.first << " " << result[i].second.second << "\n";
    }*/

    pair<int,int> min_num=make_pair(result[0].second.first, result[0].second.second);

    int temp_num;
    vector<int> answer;
    for (int i = 1; i < result.size(); i++)
    {
        if (min_num.second-min_num.first > result[i].second.second - result[i].second.first)
        {
            min_num.first = result[i].second.first;
            min_num.second = result[i].second.second;
        }
    }
    answer.push_back(min_num.first);
    answer.push_back(min_num.second);
    //v.push_back(make_pair([1,1,1,2],start,end));
    //3,4 start=2 end 3
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