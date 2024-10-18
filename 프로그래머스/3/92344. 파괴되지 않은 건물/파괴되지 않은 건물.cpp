#include <string>
#include <vector>
#include <iostream>

using namespace std;

int arr[1001][1001];

int solution(vector<vector<int>> board, vector<vector<int>> skill) {
    int answer = 0;
    
    int r = board.size();
    int c = board[0].size();
    
    for (int i = 0; i < skill.size(); i++) {
        int type = skill[i][0];
        int r1 = skill[i][1];
        int c1 = skill[i][2];
        int r2 = skill[i][3];
        int c2 = skill[i][4];
        int degree = skill[i][5];
        if (type == 1) {
            degree = -degree;
        }
        
        arr[r1][c1] += degree;
        arr[r2 + 1][c2 + 1] += degree;
        arr[r2 + 1][c1] += -degree;
        arr[r1][c2 + 1] += -degree;
    }
    
    for (int i = 0; i < r + 1; i++) {
        for (int j = 0; j < c; j++) {
            arr[i][j + 1] += arr[i][j];
        }
    }
    
    for (int i = 0; i < c + 1; i++) {
        for (int j = 0; j < r; j++) {
            arr[j + 1][i] += arr[j][i];
        }
    }
    
    for (int i = 0; i < r; i++) {
        for (int j = 0; j < c; j++) {
            if (board[i][j] + arr[i][j] > 0) {
                answer++;
            }
        }
    }
    
    return answer;
}