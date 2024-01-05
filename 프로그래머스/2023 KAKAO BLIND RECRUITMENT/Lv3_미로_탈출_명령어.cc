#include <iostream>
#include <string>
#include <algorithm>

using namespace std;

int dx[4] = {1, 0, 0, -1};
int dy[4] = {0, -1, 1, 0};
char dAlpha[4] = {'d', 'l', 'r', 'u'};
string answer = "z";

bool isValid(int nx, int ny, int n, int m) {
    return 1 <= nx && nx <= n && 1 <= ny && ny <= m;
}

void dfs(int n, int m, int x, int y, int r, int c, string prev_s, int cnt, int k) {
    if (k < cnt + abs(x - r) + abs(y - c)) return;
    if (x == r && y == c && cnt == k) {
        answer = min(answer, prev_s);
        return;
    }
    for (int i = 0; i < 4; i++) {
        int nx = x + dx[i];
        int ny = y + dy[i];
        if (isValid(nx, ny, n, m) && prev_s + dAlpha[i] < answer) {
            dfs(n, m, nx, ny, r, c, prev_s + dAlpha[i], cnt + 1, k);
        }
    }
}

string solution(int n, int m, int x, int y, int r, int c, int k) {
    int dist = abs(x - r) + abs(y - c);
    if (dist > k || (k - dist) % 2 == 1) {
        return "impossible";
    }

    dfs(n, m, x, y, r, c, "", 0, k);
    return answer;
}