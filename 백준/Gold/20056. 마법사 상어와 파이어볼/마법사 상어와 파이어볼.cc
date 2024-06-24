#include <iostream>
#include <vector>

using namespace std;

#define FastIO ios::sync_with_stdio(false), cin.tie(nullptr), cout.tie(nullptr);

struct Ball {
    int r, c, m, s, d;
};

int N, M, K;
vector<Ball> arr[51][51];
vector<Ball> balls;
int dx[8] = { -1, -1, 0, 1, 1, 1, 0, -1 };
int dy[8] = { 0, 1, 1, 1, 0, -1, -1, -1 };

void moveBalls() {
    for (int i = 0; i < balls.size(); i++) {
        Ball& ball = balls[i];

        int nr = (ball.r + dx[ball.d] * ball.s + N * ball.s) % N;
        int nc = (ball.c + dy[ball.d] * ball.s + N * ball.s) % N;

        if (nr < 0) nr += N;
        if (nc < 0) nc += N;

        ball.r = nr;
        ball.c = nc;

        arr[nr][nc].push_back(ball);
    }
}

void mergeAndSplitBalls() {
    vector<Ball> newBalls;

    for (int r = 0; r < N; r++) {
        for (int c = 0; c < N; c++) {
            if (arr[r][c].size() > 1) {
                int sumM = 0, sumS = 0, count = arr[r][c].size();
                bool allEven = true, allOdd = true;

                for (Ball& ball : arr[r][c]) {
                    sumM += ball.m;
                    sumS += ball.s;
                    if (ball.d % 2 == 0) allOdd = false;
                    else allEven = false;
                }

                int newM = sumM / 5;
                int newS = sumS / count;

                if (newM > 0) {
                    for (int i = 0; i < 4; i++) {
                        int newD = (allEven || allOdd) ? i * 2 : i * 2 + 1;
                        newBalls.push_back({ r, c, newM, newS, newD });
                    }
                }
            }
            else if (arr[r][c].size() == 1) {
                newBalls.push_back(arr[r][c][0]);
            }
            arr[r][c].clear();
        }
    }
    balls = newBalls;
}

int main() {
    FastIO;

    cin >> N >> M >> K;

    for (int i = 0; i < M; i++) {
        int r, c, m, s, d;
        cin >> r >> c >> m >> s >> d;
        balls.push_back({ r, c, m, s, d });
    }

    for (int i = 0; i < K; i++) {
        moveBalls();
        mergeAndSplitBalls();
    }

    int result = 0;

    for (Ball& ball : balls) {
        result += ball.m;
    }

    cout << result << "\n";

    return 0;
}
