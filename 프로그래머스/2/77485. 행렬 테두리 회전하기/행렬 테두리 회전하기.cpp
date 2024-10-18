#include <string>
#include <vector>

using namespace std;

int arr[101][101];

int rotate(int x1, int y1, int x2, int y2) {
    int temp;
    int temp2 = arr[x1 + 1][y1];
    int res = temp2;
    for (int i = y1; i <= y2; i++) {
        temp = arr[x1][i];
        arr[x1][i] = temp2;
        temp2 = temp;
        res = min(res, temp2);
    }
    for (int i = x1 + 1; i <= x2; i++) {
        temp = arr[i][y2];
        arr[i][y2] = temp2;
        temp2 = temp;
        res = min(res, temp2);
    }
    for (int i = y2 - 1; i >= y1; i--) {
        temp = arr[x2][i];
        arr[x2][i] = temp2;
        temp2 = temp;
        res = min(res, temp2);
    }
    for (int i = x2 - 1; i >= x1 + 1; i--) {
        temp = arr[i][y1];
        arr[i][y1] = temp2;
        temp2 = temp;
        res = min(res, temp2);
    }
    return res;
}

vector<int> solution(int rows, int columns, vector<vector<int>> queries) {
    vector<int> answer;
    
    int n = 1;
    for (int i = 1; i <= rows; i++) {
        for (int j = 1; j <= columns; j++) {
            arr[i][j] = n;
            n++;
        }
    }
    
    for (int i = 0; i < queries.size(); i++) {
        int x1 = queries[i][0];
        int y1 = queries[i][1];
        int x2 = queries[i][2];
        int y2 = queries[i][3];
        int res = rotate(x1, y1, x2, y2);
        answer.push_back(res);
    }
    
    return answer;
}