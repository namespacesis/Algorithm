#include <iostream>
#include <bitset>
#include <deque>

#define FastIO ios::sync_with_stdio(false), cin.tie(nullptr), cout.tie(nullptr);
#define INF 1e9
#define MAX_SIZE 1000

using namespace std;

struct Node {
    int x, y, cnt;
};

int T, R, C;
bitset<MAX_SIZE* MAX_SIZE> visited;
bitset<MAX_SIZE* MAX_SIZE> arr;
int cost[MAX_SIZE * MAX_SIZE];
int dx[4] = { 1, -1, 0, 0 };
int dy[4] = { 0, 0, 1, -1 };

inline int getIndex(int x, int y) {
    return y * C + x;
}

int main() {
    FastIO;

    cin >> T;

    while (T--) {
        cin >> R >> C;
        visited.reset();
        arr.reset();

        for (int i = 0; i < R; i++) {
            for (int j = 0; j < C; j++) {
                char input;
                cin >> input;
                if (input == '1') {
                    arr.set(getIndex(j, i));
                }
                cost[getIndex(j, i)] = INF;
            }
        }

        deque<Node> dq;

        for (int i = 0; i < R; i++) {
            dq.push_front({ 0, i, arr[getIndex(0, i)] });
            visited.set(getIndex(0, i));
            cost[getIndex(0, i)] = arr[getIndex(0, i)];
            dq.push_front({ C - 1, i, arr[getIndex(C - 1, i)] });
            visited.set(getIndex(C - 1, i));
            cost[getIndex(C - 1, i)] = arr[getIndex(C - 1, i)];
        }

        for (int j = 1; j < C - 1; j++) {
            dq.push_front({ j, 0, arr[getIndex(j, 0)] });
            visited.set(getIndex(j, 0));
            cost[getIndex(j, 0)] = arr[getIndex(j, 0)];
            dq.push_front({ j, R - 1, arr[getIndex(j, R - 1)] });
            visited.set(getIndex(j, R - 1));
            cost[getIndex(j, R - 1)] = arr[getIndex(j, R - 1)];
        }

        while (!dq.empty()) {
            Node cur = dq.front();
            dq.pop_front();

            for (int i = 0; i < 4; i++) {
                int nx = cur.x + dx[i];
                int ny = cur.y + dy[i];

                if (nx >= 0 && nx < C && ny >= 0 && ny < R) {
                    int index = getIndex(nx, ny);
                    int ncnt = cur.cnt + arr.test(index);
                    if (!visited.test(index) || ncnt < cost[index]) {
                        visited.set(index);
                        cost[index] = ncnt;
                        if (arr.test(index) == 0) {
                            dq.push_front({ nx, ny, ncnt });
                        }
                        else {
                            dq.push_back({ nx, ny, ncnt });
                        }
                    }
                }
            }
        }

        int res1 = 0;
        int res2 = 0;

        for (int i = 0; i < R; i++) {
            for (int j = 0; j < C; j++) {
                int index = getIndex(j, i);
                if (!arr.test(index)) {
                    if (cost[index] > res1) {
                        res1 = cost[index];
                        res2 = 1;
                    }
                    else if (cost[index] == res1) {
                        res2++;
                    }
                }
            }
        }

        cout << res1 << " " << res2 << "\n";
    }

    return 0;
}
