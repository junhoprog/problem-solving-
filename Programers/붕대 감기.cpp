#include <string>
#include <vector>
#include<iostream>

using namespace std;

int solution(vector<int> bandage, int health, vector<vector<int>> attacks) {
    int time = bandage[0];//time에 연속으로 마추면 추가 힐후에 다시 초기화
    int sec_heal = bandage[1];
    int add_heal = bandage[2];
    int answer = 0;
    int present_health = health;
    //공격 시간과 피해량
    int end = attacks[attacks.size() - 1][0];
    int cnt = 0;//시간을 잼.
    int n = 0;//공격 단계
    for (int i = 1; i <= end; i++)
    {
        if (attacks[n][0] == i)
        {
            //공격 시간이면
            present_health -= attacks[n][1];
            //std:: cout << present_health << " ";
            n++;
            cnt = 0;
            continue;
        }
        //cout << health << " " << present_health<<endl;
        //20
        if (health == present_health) {
            continue;
        }

        if (present_health <= 0)
        {
            break;
        }

        cnt++;
        present_health += sec_heal;

        if (cnt == time)//t에 도달했다면
        {
            present_health += add_heal;
            cnt = 0;
        }
        if (present_health > health)
        {
            present_health = health;
        }
        //std::cout << present_health << " ";
    }

    if (present_health <= 0)
    {
        answer = -1;
    }
    else {
        answer = present_health;
    }

    return answer;
}

/*
붕대감기: t초동안  1초마다 x만큼 체력회복
t초 연속 붕대 -> y만큼의 추가회복 =>x+y(최대체력보다 커지기x)
기술사용중 공격받으면 기술 취소 공격 당하는 중엔 체력회복x
공격당해 기술 취소, 끝이나면 바로 사용가능 ->연속 성공시간도 0초기화
공격받으면 정해진 피해량만큼 체력줆 0이되면 죽어서 체력x

*/
int main()
{
    vector<int> bandage;
    int health;
    vector<vector<int>> attacks;
    bandage.push_back(1);
    bandage.push_back(10);
    bandage.push_back(10);
    health = 5;
    vector<int>v;
    v.push_back(97);
    v.push_back(4);
    attacks.push_back(v);
    v.clear();
    v.push_back(99);
    v.push_back(4);
    attacks.push_back(v);
    std::cout << solution(bandage,health,attacks);
}