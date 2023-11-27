#include <string>
#include <vector>
#include<iostream>
using namespace std;

vector<int> solution(int n) {
    vector<int> answer;
    vector<vector<int>> map(n, vector<int>(n, 0));
    int num = 1;
    int x = 0, y = 0;
    int sum = 0;
    int temp = n;
    for (int i = 1; i <= n; i++)//처음 n까지의 합구하기
    {
        sum += i;
    }
    while (n > 0) {
        //n이 0이 될때까지
        
        //세로
        for (int i = 0; i < n; i++)//n만큼 세로로 내려가면서 수 넣기
        {
            map[x++][y] = num++;
        }
        x--;//x++로 인해 한 개 더 커져있어서 한개 줄임
        if (num > sum)//만약에 num이 넘으면 멈춤
        {
            break;
        }
        y++;//다음 가로로 가기위해 y증가시킴
        n--;//6->5->...횟수 줄이기
        //x=5 y=1
        
    //가로
        for (int i = 0; i < n; i++)//n만큼 가로로 수 넣기
        {
            map[x][y++] = num++;
        }
        y--;//y++로 한 개더 커져있는것 줄이기
        if (num > sum)//넘으면 멈추기
        {
            break;
        }
        //x=5 y=5
        x--;
        y--;
        n--;
        //대각선
        for (int i = 0; i < n; i++)//왼쪽 대각선 이동
        {
            map[x--][y--] = num++;
        }
        x++;//줄인만큼 늘림.
        y++;
        if (num > sum)
        {
            break;
        }
        x++;
        n--;
    }

    for (int i = 0; i < temp; i++)
    {
        for (int j = 0; j < temp; j++)
        {
            if (map[i][j] == 0)
            {
                continue;
            }
            else {
                answer.push_back(map[i][j]);
            }
        }
    }
    return answer;
}
int main()
{
    vector<int>v;

    v = solution(6);
    for (int i = 0; i < v.size(); i++)
    {
        cout << v[i] << " ";
    }
    return 0;
}