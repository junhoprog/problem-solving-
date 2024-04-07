#include <string>
#include <vector>
#include <vector>
#include<iostream>
#include<map>
using namespace std;

int solution(vector<string> friends, vector<string> gifts) {

    int answer = 0;
    map<pair<string, string>, int>m;//선물 준 기록
    map<string, int>v;//선물지수
    map<string, int>next;
    for (int i = 0; i < friends.size(); i++)
    {
        v[friends[i]] = 0;//선물지수 초기화
        next[friends[i]] = 0;//다음달 선물 초기화

        for (int j = 0; j < friends.size(); j++)
        {
            m[{friends[i], friends[j]}]=0;
        }
    }

    for (int i = 0; i < gifts.size(); i++)
    {
        for (int j = 0; j < gifts[i].size(); j++)
        {
            if (gifts[i][j] == ' ')
            {
                string A;
                string B;
                A = gifts[i].substr(0, j);
                B = gifts[i].substr(j + 1, gifts.size() - j + 2);
                //cout << A << " " << B<<endl;
                m[{A, B}]++;

                v[A]++;
                v[B]--;
            }
        }
    }

    //다음달이 되었을 때 주고받는것 확인
    for (int i = 0; i < friends.size(); i++)
    {
        for (int j = i+1; j < friends.size(); j++)
        {
            if (m[{friends[i], friends[j]}] < m[{friends[j], friends[i]}])
            {
                //cout << friends[i] << " " << friends[j] <<1 <<endl;
                next[friends[j]]++;
            }
            else if(m[{friends[i], friends[j]}] > m[{friends[j], friends[i]}])
            {
                //cout << friends[i] << " " << friends[j] <<2 << endl;
                next[friends[i]]++;
            }
            else {
                //같으면 선물지수로 비교
                if (v[friends[i]] < v[friends[j]])
                {
                    //cout << friends[i] << " " << friends[j] << 3 << endl;
                    next[friends[j]]++;
                }
                else if (v[friends[i]] > v[friends[j]])
                {
                    //cout << friends[i] << " " << friends[j] << 4 << endl;
                    next[friends[i]]++;
                }
            }
        }
    }
    int max = 0;
    for (int i = 0; i < next.size(); i++)
    {
        //cout << next[friends[i]]<< " ";
        if (max < next[friends[i]])
        {
            max = next[friends[i]];
        }
    }
    answer = max;
    return answer;
}
//가장많은 받은 친구

/*
두 사람 주고받은 기록 -> 두사람사이 더 많은 선물 준 사람 선물받음
기록x, 같다면 선물 지수가 더 큰 사람이 작은 사람에게 선물 받음
선물 지수: 이번달까지. 자신이 친구들에게 준 선물의 수에서 받은 선물의 수를 뺀 값.
선물 지수도 같다면 주고받지 x

a b-> a가 b에게 선물을 줌.
결과:  최대 받은 선물의 수
*/
int main()
{
    vector<string>friends;
    
    friends.push_back("muzi");
    friends.push_back("ryan");
    friends.push_back("frodo");
    friends.push_back("neo");
    
    vector<string>gifts;
    
    gifts.push_back("muzi frodo");
    gifts.push_back("muzi frodo");
    gifts.push_back("ryan muzi");
    gifts.push_back("ryan muzi");
    gifts.push_back("ryan muzi");
    gifts.push_back("frodo muzi");
    gifts.push_back("frodo ryan");
    gifts.push_back("neo muzi");
    cout << solution(friends,gifts);
}