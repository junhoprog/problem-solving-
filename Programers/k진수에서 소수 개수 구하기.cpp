#include <string>
#include <vector>
#include<iostream>
#include<string>
#include<math.h>
#include<algorithm>
using namespace std;


bool is_prime(long long num)//소수 여부 판단
{
    int cnt = 1;

    for (long long i = 2; i <= sqrt(num); i++)//자기자신을 제외한 1개만 나와야함 루트num전까지만 증가하면 됨
    {
        if (num % i == 0)//i로 나머지구했을 때 0이면 나눠떨어진다
        {
            cnt++;//cnt증가
            break;
        }
    }
    //cnt가 2인순간 자기자신을 제외한 하나 더 있는 것이므로 소수가 아닌 것.
    if (cnt == 1)//소수
    {
        return true;
    }
    else {
        return false;
    }

}

int sprit_num(string s)
{
    long long n = stoll(s);//string을 longlong형식으로 바꿈(int보단 커야하므로 자료형long long)
    int result = 0;
    long long num = 0;
    int cnt = 0;

    while (n != 0)//n이 0이되기전까지 반복
    {
        if (n % 10 == 0)//0을 기준으로 나눠줘야함.
        {
            if (num < 2)//1이면 소수가 아니기 때문에 변수 초기화시킴
            {
                cnt = 0;
                num = 0;
                n /= 10;//다음 수로 넘어감
                continue;
            }
            else {
                if (is_prime(num))//소수 확인
                {
                    result++;//소수 맞으면 result증가
                }
                //소수 여부 판단
                //조건확인
            }
            //변수 초기화
            cnt = 0;
            num = 0;
            n /= 10;
            continue;
        }

        else {
            //0이 아니면 다음으로 넘어가기전 숫자를 쌓아줘야함  11-> n%10-->2이면 211로 만들어주는 과정으로
            //n%10에 10^cnt만큼 곱하고 원래있던 숫자만큼 더해줌
            num += (n % 10) * pow(10, cnt);
            //num += n % 10;
            n /= 10;
            cnt++;//자릿수 증가
        }
    }
    //소수여부 판단
    if (is_prime(num))///0으로 나누지 못한 마지막 숫자를 소수 확인해줘야하기 때문에
                      //ex 211011이면 11은 확인 못할 수 있음
    {
        result++;
    }
    return result;

}
int solution(int n, int k) {
    int answer = -1;
    string s = "";

    while (n > 0) {
        s += to_string(n % k);//k진수 값을 s에 넣고
        n /= k;//k진수 만큼 나누는 과정 반복
    }

    reverse(s.begin(), s.end());//넣은 순서가 반대이므로 순서 reverse

    answer = sprit_num(s);

    return answer;
}
/*
양의 정수 n이 주어짐. 이 숫자를 k진수로 바꿨을 때 변환된 수 안에 아래조건에 맞는 소수가 몇개인지 알아본다.
1. 0p0 소수 양쪽에 0 있는
2. p0 소수 오른쪽에만 0이 있고 왼쪽엔 아무것도 없는 경우
3. 0p 소수 왼쪽만 9이 있고 오른쪽엔 아무것도 없는 경우
4. p처럼 소수 양쪽에 아무것도 없는 경우
p는 각 자릿수에 0을 포함하지 않는 소수임.
n을 k진수로 바꾸기
    k진수로 바꾼 수 특정 변수에 넣고
    위 조건에 하나라도 충족되는게 있는지 확인하기
    만약 0이 나올때까지
    if 211 0이 나왔으니 숫자는 초기화하고 저 조건에 충족하는지 확인
    0다음 숫자 2봤는데 다음이 0이며
*/
int main()
{
	cout << solution(437674,3);
	return 0;
}