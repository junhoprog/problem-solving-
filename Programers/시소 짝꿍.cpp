#include <string>
#include <vector>
#include<map>
#include<iostream>

using namespace std;

long long solution(vector<int> weights) {
    long long answer = 0;
    vector<long long>cnt(1001, 0);
    for (int i = 0; i < weights.size(); i++)
    {
        cnt[weights[i]]++;//100 180 360 ...각 cnt에 매핑되어 개수증가 
    }
    for (int i = 0; i < weights.size(); i++)
    {
        //현재 나온 수를 비율로 따져보았을 때 나올 수 있는 것은
        //2:3, 1:2, 3:4임
        if (weights[i] % 2 == 0)
        {
            //2:3일지 확인
            if ((weights[i] / 2) * 3 <= 1000)//cnt인덱스를 넘어가지 않게
            {
                answer += cnt[(weights[i] / 2) * 3];
            }//0이면 그 상태일테고 1이상이면 그 만큼 더해질것임.
        }
        if (weights[i] % 3 == 0)
        {
            //3:4일지 확인
            if ((weights[i] / 3) * 4 <= 1000)
                answer += cnt[(weights[i] / 3) * 4];//0이면 그 상태일테고 1이상이면 그 만큼 더해질것임.
        }

        if (weights[i] * 2 <= 1000)
            answer += cnt[weights[i] * 2];
        //1:2일지 확인
    }

    for (int i = 100; i <= 1000; i++)
    {
        //같은 수 인 숫자가 n(n>=2)개일 경우 nC2해줘야함.
        //n(n-1)/2
        if (cnt[i] > 1)
        {
            answer += (long long)(cnt[i] * (cnt[i] - 1)) / 2;//해당 부분 개수

        }
    }

    return answer;
}
int main()
{
    vector<int>v;
    v.push_back(100);
    v.push_back(180);
    v.push_back(360);
    v.push_back(100);
    v.push_back(270);
    cout << solution(v);
}