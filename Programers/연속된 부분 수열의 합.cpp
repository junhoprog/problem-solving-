#include <string>
#include <vector>
#include<queue>
#include<iostream>
using namespace std;

vector<int> solution(vector<int> sequence, int k) {
    vector<pair<int, int>>result;//시작,끝 인덱스를 담을 vector
    queue<int>q;

    int sum = 0;
    int start = 0, end = 0;

    for (int i = 0; i < sequence.size(); i++)
    {
        sum += sequence[i];//sum에 수를 계속 더함
        q.push(sequence[i]);//저장 후 이후에 저장또는 삭제함
        end++;//끝을 계속 늘림.

        if (sum == k)//같아지면 결과에 추가
        {
            result.push_back(make_pair(start, end - 1));
            sum -= q.front();//큐 맨 앞에 있는 수 빼고 총 합도 줄임
            q.pop();
            start++;//q를 뺀만큼 start도 늘림
            continue;
        }

        else if (sum > k) {
            //넘으면 앞에 빼기
            while (sum > k) {//넘으면 계속 앞에 빼줌
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
                //빼줬더니 같아지면
            }
        }
    }

    pair<int, int> min_num = make_pair(result[0].first, result[0].second);//최소 부분수열을 찾기 위해 결과 시작,끝인덱스를 넣음

    int temp_num;
    vector<int>answer;
    for (int i = 1; i < result.size(); i++)
    {
        if (min_num.second - min_num.first > result[i].second - result[i].first)//끝-시작이 최소인 결과를 찾음
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