#include <iostream>
#include <vector>
#include <queue>
#include <algorithm>

#define FastIO ios::sync_with_stdio(false), cin.tie(nullptr), cout.tie(nullptr);

using namespace std;

int H, W;
int arr[1000][1000];
int result[1000][1000];

struct Light {
    int x, y, brightness;
};

void place_light(int x, int y, int c) {
    queue<pair<int, int>> q;
    q.push({ x, y });
    result[x][y] = max(result[x][y], c);

    vector<int> dx = { 0, 0, 1, -1 };
    vector<int> dy = { 1, -1, 0, 0 };

    while (!q.empty()) {
        auto [cx, cy] = q.front(); q.pop();
        for (int dir = 0; dir < 4; ++dir) {
            int nx = cx + dx[dir];
            int ny = cy + dy[dir];
            if (nx >= 0 && nx < H && ny >= 0 && ny < W && arr[nx][ny] != -1) {
                int new_brightness = result[cx][cy] - 1;
                if (new_brightness > result[nx][ny]) {
                    result[nx][ny] = new_brightness;
                    q.push({ nx, ny });
                }
            }
        }
    }
}

int min_lights() {
    vector<Light> lights;

    for (int i = 0; i < H; ++i) {
        for (int j = 0; j < W; ++j) {
            if (arr[i][j] > 0) {
                lights.push_back({ i, j, arr[i][j] });
            }
        }
    }

    sort(lights.begin(), lights.end(), [](const Light& a, const Light& b) {
        return a.brightness > b.brightness;
        });

    int count = 0;
    for (const auto& light : lights) {
        if (result[light.x][light.y] < arr[light.x][light.y]) {
            place_light(light.x, light.y, light.brightness);
            count++;
        }
    }

    for (int i = 0; i < H; ++i) {
        for (int j = 0; j < W; ++j) {
            if (arr[i][j] != -1 && result[i][j] != arr[i][j]) {
                return -1;
            }
        }
    }

    return count;
}

int main() {
    FastIO;

    cin >> H >> W;

    for (int i = 0; i < H; ++i) {
        for (int j = 0; j < W; ++j) {
            cin >> arr[i][j];
        }
    }

    int res = min_lights();
    cout << res << "\n";

    return 0;
}