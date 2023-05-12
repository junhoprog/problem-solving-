#include <string>
#include <vector>

using namespace std;
//cap=> 최대 실을 수 있는 상자양
//n=> n개의 집들 i번짼 i만큼 거리 갔다가 돌아올 때 재활용상자가져오려함
//각 집마다 배달할 재활용 택배 상자의 개수와 수거할 빈 재활용 택배상자의개수를 알 때 
//모든 배달을 마치고 돌아올 최소 이동거리?
int distance = 0;
int D_max = 0;
void delivery(vector<int> deliveries, vector<int> pickups) {
    D_max = n;
    int P_sum = 0;
    int D_sum = 0;
    int goal = n-1;
    int t;
    for (int j = goal - 1; j >= 0; j--)
    {
        if (pickups[j] != 0) {
            if (pickups[j]==cap&&P_sum==0)//아무것도 없는 상태에서 꽉차있다면?
            {
                P_sum += pickups[j];
                pickups[j] = 0;
                t = j;
                break;
            }
            else if()
            else if (pickups[j] < cap)//이미 몇개 들어있는 상태에서 
            {
                P_sum += pickups[j];
                pickups[j] = 0;
            }
            else if (pickups[j] == 0)
            {
                continue;
            }
        }

    }

    for (int i = n - 1; i >= 0; i--)
    {
        if (deliveries[i]+sum<cap)
        {

        }
        else {

        }
    }
}

/* 1. 만약 cap이랑 같은 수또는 더 많은 재활용 택배 상자가 한 곳에 있다면
    -> x에 도달하기전에 배달을 모두 완료한 뒤에  다 수거하기
    (목표에서 모두 내리거나 또는 가는 길에 내려서 개수 맞추거나 무조건 재활용 가져올 때 cap 꽉채우기)
*/
//deliveries=1,0,3,1,2
//pickups=0,3,0,4,0

long long solution(int cap, int n, vector<int> deliveries, vector<int> pickups) {
    long long answer = -1;
    delivery(deliveries,pickeups);
    answer = distance;
    return answer;
}