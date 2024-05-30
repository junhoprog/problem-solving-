#include <string>
#include <vector>
#include<iostream>
#include<map>
#include<algorithm>

using namespace std;

map<string, int>m;
string temp="";
vector<string> answer;

bool compare(pair<string, int>a, pair<string, int>b)
{
    return a.second > b.second;
}
void search(vector<string> orders, int i,int j, int index,int cnt)
{
    if (cnt == i)//세트 개수만큼했다면
    {
        m[temp]++;//현재 위치 개수 더하기
        return;
    }
    for (int t = index; t < orders[j].size(); t++)//순열 실행
    {
        temp += orders[j][t];
        search(orders, i, j, t+1, cnt+1);//다음 세트 위치로 이동
        temp.erase(cnt,cnt+1;//현재위치 제거
    }//ACD B->C->D->E
}

vector<string> solution(vector<string> orders, vector<int> course) {
    int index = 0;
    for (auto i : course)//course에 있는 것을 i에 넣어 반복
    {
        sort(orders[j].begin(), orders[j].end());//현재 orders를 정렬한 후
        for (int j = 0; j < orders.size(); j++)//모든 orders를 확인하기 위해 반복
        {
            //i보다 작으면 다음으로 넘어가기
            if (orders[j].size() < i)
            {
                continue;
            }
            //i랑 같다면 그냥 넣기
            else if (orders[j].size() == i)
            {
                m[orders[j]]++;
            }
                //i보다 클 때
            else
            {
                search(orders, i, j, index, 0);
            }            
        }
    }
    vector<pair<string, int>> sortNum;//세트들중에 2개이상인 것을 이 곳에 정리해서 2,3,4세트에서 가장 많이 주문 된 것만 선별할 것임.
    for (auto order : m)//mpa에 있는 내용들을 order에 넣어주며
    {
        if (order.second > 1)//갯수가 2개이상이면
            sortNum.push_back(make_pair(order.first, order.second));//sortNum에 넣어주고
        sort(sortNum.begin(), sortNum.end());//
    }
    sort(sortNum.begin(), sortNum.end(), compare);//갯수 기준으로 정렬
    
    for (int i = 0; i < course.size(); i++)//세트갯수 별로 세트 메뉴를 찾을건대
    {
        int max = 0;
        for (int j = 0; j < sortNum.size(); j++)//전체에서
        {
            if (sortNum[j].first.size() != course[i])//같은 세트사이즈가 아니면 다음으로 넘기고
            {
                continue;
            }
            else if(max==0)//같은 세트 사이즈인데 처음 나온거면
            {
                answer.push_back(sortNum[j].first);//answer에 넣어주고
                max = sortNum[j].second;//max적용
            }
            else if (max == sortNum[j].second)//max가 같다는것은 다음 나온 내용과 같은 최대크기인 문자열이기에
            {
                answer.push_back(sortNum[j].first);//해당문자열도 넣음
            }
            else {//같은 course지만 최대값보다 작으면 이후부턴 하는 의미없음
                break;
            }
        }
    }
    sort(answer.begin(), answer.end());//나온 결과들을 정렬
    return answer;
}
int main()
{
    vector<string>orders = { "ABCFG", "AC", "CDE", "ACDE", "BCFG", "ACDEH" };
    vector<int>course = { 2,3,4 };
    vector<string>answer;
    answer= solution(orders,course);
    for (auto i : answer) {
        cout << i << " ";
    }
}