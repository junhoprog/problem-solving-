#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;

#include <string>
#include <vector>

using namespace std;

vector<int> solution(vector<int> answers) {
    vector<int> answer;
    int man1[5] = { 1,2,3,4,5 };
    int man2[8] = { 2,1,2,3,2,4,2,5 };
    int man3[10] = { 3,3,1,1,2,2,4,4,5,5 };
    vector<int>v;
    int j = 0;
    int cnt1 = 0, cnt2 = 0, cnt3 = 0;
    for (int i = 0; i < answers.size(); i++)
    {
        if (j == 5)
        {
            j = 0;
        }
        if (answers[i] == man1[j])
        {
            cnt1++;
        }
        j++;
    }

    j = 0;
    for (int i = 0; i < answers.size(); i++)
    {
        if (j == 8)
        {
            j = 0;
        }
        if (answers[i] == man2[j])
        {
            cnt2++;
        }
        j++;
    }

    j = 0;
    for (int i = 0; i < answers.size(); i++)
    {
        if (j == 10)
        {
            j = 0;
        }
        if (answers[i] == man3[j])
        {
            cnt3++;
        }
        j++;
    }
    if (cnt1 == cnt2 && cnt2 == cnt3)
    {
        answer.push_back(1);
        answer.push_back(2);
        answer.push_back(3);
    }
    else if (cnt1 > cnt3 && cnt1 == cnt2)
    {
        answer.push_back(1);
        answer.push_back(2);

    }
    else if (cnt2 > cnt1 && cnt2 == cnt3)
    {

        answer.push_back(2);
        answer.push_back(3);
    }
    else if (cnt1 > cnt2 && cnt1 == cnt3)
    {
        answer.push_back(1);
        answer.push_back(3);
    }
    else if (cnt1 > cnt2 && cnt1 > cnt3)
    {
        answer.push_back(1);
    }
    else if (cnt2 > cnt1 && cnt2 > cnt3)
    {
        answer.push_back(2);
    }
    else if (cnt3 > cnt2 && cnt1 < cnt3)
    {
        answer.push_back(3);
    }
    return answer;
}


int main() {
    vector<int>answer;
    answer.push_back(1);
    answer.push_back(3);
    answer.push_back(2);
    answer.push_back(4);
    answer.push_back(2);
    vector<int>temp;
    temp = solution(answer);
    for (int i = 0; i < temp.size(); i++)
    {
        cout << temp[i] << " ";
    }
}