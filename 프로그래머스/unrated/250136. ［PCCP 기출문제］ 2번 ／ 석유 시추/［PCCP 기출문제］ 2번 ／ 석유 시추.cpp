#include <string>
#include <vector>
#include <queue>
#include <set>
#include <algorithm>

using namespace std;

const int MAX = 501;

int dx[4] = { 1, -1, 0, 0 };
int dy[4] = { 0, 0, 1, -1 };

bool visited[MAX][MAX];

int maxOil[MAX];

int solution(vector<vector<int>> land) {
    int N = land.size();
    int M = land[0].size();

    for (int y = 0; y < N; y++) {
        for (int x = 0; x < M; x++) {
            if (!land[y][x] || visited[y][x]) {
                continue;
            }

            set<int> xSet;
            queue<pair<int, int>> q;

            q.push({ y, x });
            visited[y][x] = true;

            int cnt = 0;

            while (!q.empty()) {
                int curY = q.front().first;
                int curX = q.front().second;
                xSet.insert(curX);
                cnt++;
                q.pop();

                for (int i = 0; i < 4; i++) {
                    int nextY = curY + dx[i];
                    int nextX = curX + dy[i];

                    if (nextY < 0 || nextY >= N || nextX < 0 || nextX >= M) {
                        continue;
                    }

                    if (visited[nextY][nextX] || !land[nextY][nextX]) {
                        continue;
                    }

                    visited[nextY][nextX] = true;
                    q.push({ nextY, nextX });
                }
            }

            for (int x : xSet) {
                maxOil[x] += cnt;
            }
        }
    }

    sort(maxOil, maxOil + MAX);

    return maxOil[MAX - 1];
}