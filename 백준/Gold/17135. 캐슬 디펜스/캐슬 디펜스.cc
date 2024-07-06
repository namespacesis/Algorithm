#include <iostream>
#include <vector>
#include <algorithm>
#include <cstring>
#include <cmath>

using namespace std;

#define FastIO ios::sync_with_stdio(false), cin.tie(nullptr), cout.tie(nullptr);

struct Node {
    int x, y;
};

int N, M, D;
int arr[17][17];
int temp[17][17];
int res;

vector<Node> enemies;

void moveEnemies() {
    vector<Node> newEnemies;
    for (auto& enemy : enemies) {
        if (enemy.x + 1 <= N) {
            newEnemies.push_back({ enemy.x + 1, enemy.y });
        }
    }
    enemies = newEnemies;
}

int attack(int archer1, int archer2, int archer3) {
    bool isKilled[17][17];
    memset(isKilled, false, sizeof(isKilled));

    int killed = 0;
    vector<int> archers = { archer1, archer2, archer3 };

    for (int archer : archers) {
        int minDist = D + 1;
        int targetX = -1, targetY = -1;

        for (auto& enemy : enemies) {
            int dist = abs(N + 1 - enemy.x) + abs(archer - enemy.y);
            if (dist <= D) {
                if (dist < minDist) {
                    minDist = dist;
                    targetX = enemy.x;
                    targetY = enemy.y;
                }
                else if (dist == minDist && enemy.y < targetY) {
                    targetX = enemy.x;
                    targetY = enemy.y;
                }
            }
        }

        if (targetX != -1 && !isKilled[targetX][targetY]) {
            isKilled[targetX][targetY] = true;
            killed++;
        }
    }

    vector<Node> remainingEnemies;
    for (auto& enemy : enemies) {
        if (!isKilled[enemy.x][enemy.y]) {
            remainingEnemies.push_back(enemy);
        }
    }
    enemies = remainingEnemies;

    return killed;
}

int simulation(int x, int y, int z) {
    memcpy(temp, arr, sizeof(arr));
    enemies.clear();

    for (int i = 1; i <= N; i++) {
        for (int j = 1; j <= M; j++) {
            if (arr[i][j] == 1) {
                enemies.push_back({ i, j });
            }
        }
    }

    int totalKilled = 0;

    while (!enemies.empty()) {
        totalKilled += attack(x, y, z);
        moveEnemies();
    }

    return totalKilled;
}

int main() {
    FastIO;

    cin >> N >> M >> D;

    for (int i = 1; i <= N; i++) {
        for (int j = 1; j <= M; j++) {
            cin >> arr[i][j];
        }
    }

    int answer = 0;

    for (int i = 1; i <= M; i++) {
        for (int j = i + 1; j <= M; j++) {
            for (int k = j + 1; k <= M; k++) {
                answer = max(answer, simulation(i, j, k));
            }
        }
    }

    cout << answer << "\n";

    return 0;
}
