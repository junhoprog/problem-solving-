#include <string>
#include <vector>
#include <queue>
#include<iostream>
using namespace std;

int search(int t, string s)
{
    string s1 = "";//비교할 길이(기준)

    int cnt = 0;//문자열 압축 길이
    int count = 1;//문자열 압축 횟수
    int remain = 0;
    bool flag = 1;

    s1 = s.substr(0, t);//처음엔 t압축길이만큼 0부터 s1에 넣고
    for (int i = t; i <= s.length(); i += t)//비교할 대상을 t부터s사이즈만큼 반복하는데 이때 t씩 확인할 거라서 i+=t해줌
    {
        flag = 1;
        remain = 0;
        //초기화
        if (s.substr(i, t).compare(s1) == 0)//기준 문자열과 비교할 문자열을 비교해서 같으면
        {
            count++;//압축 횟수 증가
        }
        else {//다르다면
            flag = 0;//flag0으로 표사
            remain = s.substr(i, t).length();//비교할 문자열의 길이를 저장해놓고
            if (count != 1)//압축횟수가 2이상이면
            {
                cnt += s1.length() + to_string(count).length();//10abc-> 횟수를 문자열로 만들어서 길이+s1의 길이만큼 cnt에 증가시킴
                s1 = s.substr(i, t);//기준 문자열을 비교 문자열로 변경
            }
            else {
                cnt += s1.length();//반복된게 없으니 현재 문자열 길이만 cnt에 추가
                s1 = s.substr(i, t);//기준 문자열을 비교 문자열로 변경
            }
            count = 1;//count1로 초기화
        }
    }
    if (flag == 0)//끝났을 때 다르면
    {
        cnt += remain;//만약 압축할 길이가 3인데 2개가 남았을 때 cnt에 remain길이만큼 더하기 위해(3일지 2일지 모르니까) 
    }
    return cnt;
}
int solution(string s) {
    int answer = 100000;
    int result = 1001;//문자열 길이를 담을 변수
    if (s.length() == 1)//s의 길이가 1이면 그대로 나올테니까 1반환
    {
        return 1;
    }
    for (int i = 1; i <= s.size() / 2; i++)//s의길이 반이상을 압축시키지 못함 abab-> 3개씩 압축 x
    {
        result = search(i, s);//문자열 압축 길이와 문자열 함수제공후 압축된 길이 저장
        if (answer > result)
        {
            answer = result;
        }

    }
    return answer;
}
int main()
{
    cout << solution("aabbaccc");
}

