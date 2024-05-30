#include <string>
#include <vector>
#include <iostream>

using namespace std;

int result = 0;
int sum = 0;
void bfs(vector<int>numbers, int target, int cur)
{
    if (cur == numbers.size() - 1)//현재위치가 끝자리면 재귀를 끝내고 합한 값과 target비교 해야함.
    {
        for (int i = 0; i < 2; i++)
        {
            if (i == 0)//+일때
            {
                sum += numbers[cur];//먼저 +일때 더하고
                if (sum == target)//target과 비교해서 증가
                {
                    result++;
                }
                sum -= numbers[cur];//다시 이전으로 돌아가기
                //+x값을 넣어줌
            }
            if (i == 1)//-일때
            {
                sum -= numbers[cur];//-일때 빼주고
                if (sum == target)
                {
                    result++;//비교
                }
                sum += numbers[cur];//다시 이전상태
                //-x값을 넣어줌
            }
        }
    }

    // 1 1
    else {
        for (int i = 0; i < 2; i++)
        {
            if (i == 0)
            {
                sum += numbers[cur];
                bfs(numbers, target, cur + 1);//cur이 n-1때까지 재귀 진행 
                sum -= numbers[cur];
                //+x값을 넣어줌
            }

            if (i == 1)
            {
                sum -= numbers[cur];
                bfs(numbers, target, cur + 1);
                sum += numbers[cur];
                //-x값을 넣어줌
            }
        }
    }
}
int solution(vector<int> numbers, int target) {
    int answer = 0;
    int cur = 0;//현재 위치
    bfs(numbers, target, cur);
    answer = result;
    return answer;
}

int main()
{
    vector<int>v(5,1);
	cout << solution(v,3);
	return 0;
}
/*
0부터 n-1까지 수행하면서 재귀로 들어감
1 -1
1 1 1 1 1
1 1 1 1 -1 o
1 1 1 -1 1
1 1 1 -1 -1 이렇게 하나씩 넣어주면서 진행
*/