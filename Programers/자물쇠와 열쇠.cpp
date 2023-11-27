#include <string>
#include <vector>
#include<iostream>

using namespace std;

int B;

void rotate_key(vector<vector<int>>& key) {
    vector<vector<int>> tmp(key.size(), vector<int>(key.size(), 0));//임시
    for (int i = 0; i < key.size(); i++) {
        for (int j = 0; j < key.size(); j++) {
            tmp[i][j] = key[key.size() - (j + 1)][i];//돌릴 때 기준 좌표 세우고 다른 부분이 key사이즈-(i+1) or key사이즈-(j+1)
        }
    }
    key = tmp;
}

bool check(vector<vector<int>>& lock, vector<vector<int>>& board, vector<vector<int>>& key, int y, int x) {
    bool ret = true;//발견 즉시 끝.

    for (int i = 0; i < key.size(); i++) {
        for (int j = 0; j < key.size(); j++) {
            board[i + y][j + x] += key[i][j];//특정 위치에 보드 새기기
        }
    }

    // 가운데 lock 영역이 모두 1이면 true, 아니면 false
    for (int i = 0; i < lock.size(); i++) {
        for (int j = 0; j < lock.size(); j++) {
            if (board[i + key.size() - 1][j + key.size() - 1] != 1) {//0이 하나라도 있다면 false 1이면 걍 열려있는거니까
                ret = false;
                break;
            }
        }
    }

    for (int i = 0; i < key.size(); i++) {
        for (int j = 0; j < key.size(); j++) {
            board[i + y][j + x] -= key[i][j];//원래대로 되돌리기.
        }
    }

    return ret;
}

bool solution(vector<vector<int>> key, vector<vector<int>> lock) {
    B = 2 * (key.size() - 1) + lock.size(); //2 3 2

    vector<vector<int>> board(B, vector<int>(B, 0));

    // 가운데에 lock 영역 두기 
    for (int i = 0; i < lock.size(); i++) {
        for (int j = 0; j < lock.size(); j++) {
            board[i + key.size() - 1][j + key.size() - 1] = lock[i][j];//가운데 부분에 lock
        }
    }

    for (int r = 0; r < 4; r++) { // key 4번 회전
        for (int i = 0; i <= B - key.size(); i++) { // key를 처음부터 끝까지 슬라이딩
            for (int j = 0; j <= B - key.size(); j++) {
                if (check(lock, board, key, i, j)) return true;//모든 보드 다 돌아보기// i와 j에 옮긴 x,y,위치 넣음
            }
        }

        rotate_key(key);//돌리기
    }

    return false;
}

int main()
{
    if (solution({ {0,0,0},{1,0,0},{0,1,1} }, { {1,1,1},{1,1,0},{1,0,1} }))
        cout << "true";
    else
        cout << "false";
}