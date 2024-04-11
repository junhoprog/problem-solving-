#include <string>
#include <vector>
#include<stack>
#include<iostream>
using namespace std;

vector<int> solution(vector<int> numbers) {

    int n = numbers.size();

    vector<int> answer;
    stack<pair<int, int>>s;//numbers안 숫자와, answer의 index로 구성

    for (int i = 0; i < numbers.size(); i++)
    {
        answer.push_back(0);
        while (1)
        {
            //top에 있는거랑 numbers랑 비교하는 과정반복
            if (i == 0)//처음 숫자는 그냥 넣기 위해 멈춤
            {
                break;
            }
            if (s.empty())//이미 다 뺐으면 멈추고
            {
                break;
            }
            if (s.top().second < numbers[i])
            {
                //first에는인덱스, second엔 숫자가 들어가는데
                answer[s.top().first] = numbers[i];//맨 위 숫자인덱스 자리에 해당 숫자를 넣어줌
                s.pop();
                //(이 과정을 계속 반복해서 더 작아질때까지)
            }
            else
            {
                break;
            }
        }
        s.push(make_pair(i, numbers[i]));

        if (i == numbers.size() - 1)//끝지점이면
        {
            while (!s.empty())
            {
                answer[s.top().first] = -1;
                s.pop();
            }
        }
        //스택에 그냥 다 넣는데 넣고나서 다음으로 넘어갔을 때 top이랑 비교하는 과정 반복
        //0:9
        //top에 있는거 비교하기
    }
    return answer;
}
int main()
{
    vector<int>v;
    v.push_back(2);
    v.push_back(3);
    v.push_back(3);
    v.push_back(5);
    vector<int>v2;
    v2 = solution(v);
    for (int i = 0; i < v2.size(); i++)
    {
        cout << v[i] << " ";
    }
}/*
 
 절반하면 n개가 나왔다면 2*n-(0,t)구간 빼면됨
 x,y에서
 x가 0일때  
 0-> r1-r2+1개*2
 */