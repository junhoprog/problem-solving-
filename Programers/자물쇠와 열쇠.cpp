#include <string>
#include <vector>
#include<iostream>

using namespace std;

int B;

void rotate_key(vector<vector<int>>& key) {
    vector<vector<int>> tmp(key.size(), vector<int>(key.size(), 0));//�ӽ�
    for (int i = 0; i < key.size(); i++) {
        for (int j = 0; j < key.size(); j++) {
            tmp[i][j] = key[key.size() - (j + 1)][i];//���� �� ���� ��ǥ ����� �ٸ� �κ��� key������-(i+1) or key������-(j+1)
        }
    }
    key = tmp;
}

bool check(vector<vector<int>>& lock, vector<vector<int>>& board, vector<vector<int>>& key, int y, int x) {
    bool ret = true;//�߰� ��� ��.

    for (int i = 0; i < key.size(); i++) {
        for (int j = 0; j < key.size(); j++) {
            board[i + y][j + x] += key[i][j];//Ư�� ��ġ�� ���� �����
        }
    }

    // ��� lock ������ ��� 1�̸� true, �ƴϸ� false
    for (int i = 0; i < lock.size(); i++) {
        for (int j = 0; j < lock.size(); j++) {
            if (board[i + key.size() - 1][j + key.size() - 1] != 1) {//0�� �ϳ��� �ִٸ� false 1�̸� �� �����ִ°Ŵϱ�
                ret = false;
                break;
            }
        }
    }

    for (int i = 0; i < key.size(); i++) {
        for (int j = 0; j < key.size(); j++) {
            board[i + y][j + x] -= key[i][j];//������� �ǵ�����.
        }
    }

    return ret;
}

bool solution(vector<vector<int>> key, vector<vector<int>> lock) {
    B = 2 * (key.size() - 1) + lock.size(); //2 3 2

    vector<vector<int>> board(B, vector<int>(B, 0));

    // ����� lock ���� �α� 
    for (int i = 0; i < lock.size(); i++) {
        for (int j = 0; j < lock.size(); j++) {
            board[i + key.size() - 1][j + key.size() - 1] = lock[i][j];//��� �κп� lock
        }
    }

    for (int r = 0; r < 4; r++) { // key 4�� ȸ��
        for (int i = 0; i <= B - key.size(); i++) { // key�� ó������ ������ �����̵�
            for (int j = 0; j <= B - key.size(); j++) {
                if (check(lock, board, key, i, j)) return true;//��� ���� �� ���ƺ���// i�� j�� �ű� x,y,��ġ ����
            }
        }

        rotate_key(key);//������
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