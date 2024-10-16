#include <vector>
#include <algorithm>
using namespace std;

int R, C;
int dx[4] = {1, -1, 0, 0};
int dy[4] = {0, 0, 1, -1};
bool visited[5][5];
int INF = 987654321;  // 무한대를 나타내는 값

// DFS를 통해 A와 B의 최적의 플레이를 계산
int dfs(int ar, int ac, int br, int bc, bool Aturn, vector<vector<int>>& board) {
    int x = Aturn ? ar : br;
    int y = Aturn ? ac : bc;

    // 이동할 수 없는 경우 종료
    if (visited[x][y]) return 0;

    visited[x][y] = true;
    vector<int> list;  // 가능한 결과들을 저장하는 리스트

    // 상하좌우 4방향 탐색
    for (int i = 0; i < 4; i++) {
        int nx = x + dx[i];
        int ny = y + dy[i];

        // 경계를 벗어나거나 이미 방문했거나 발판이 없는 경우 무시
        if (nx < 0 || ny < 0 || nx >= R || ny >= C || visited[nx][ny] || board[nx][ny] == 0) continue;

        int res;
        // A의 턴일 경우 다음 이동을 상대방의 턴으로 재귀 호출
        if (Aturn) {
            res = -dfs(nx, ny, br, bc, !Aturn, board);
        } else {  // B의 턴일 경우
            res = -dfs(ar, ac, nx, ny, !Aturn, board);
        }

        // 결과 값 처리
        if (res >= 0) res++;
        else res--;

        list.push_back(res);
    }

    visited[x][y] = false;  // 방문 복구

    // 승리와 패배를 구분해 최적 결과 선택
    int result;
    int pMax = -INF, pMin = INF;  // 양수인 값 (승리)
    int mMax = -INF, mMin = INF;  // 음수인 값 (패배)

    for (int num : list) {
        if (num > 0) {
            pMax = max(pMax, num);
            pMin = min(pMin, num);
        } else {
            mMax = max(mMax, num);
            mMin = min(mMin, num);
        }
    }

    // 승리와 패배 여부에 따른 결과 반환
    if (pMax == -INF && mMax == -INF) return 0;  // 이동할 수 없을 경우 종료
    else if (pMax == -INF) return mMin;  // 패배할 경우 최대한 오래 버팀
    else return pMin;  // 승리할 경우 최소 이동
}

int solution(vector<vector<int>> board, vector<int> aloc, vector<int> bloc) {
    R = board.size();
    C = board[0].size();

    // 초기화 작업: 발판이 없는 곳을 미리 방문한 것으로 처리
    for (int i = 0; i < R; i++) {
        for (int j = 0; j < C; j++) {
            visited[i][j] = (board[i][j] == 0);
        }
    }

    // A가 먼저 시작 (A의 차례)
    return abs(dfs(aloc[0], aloc[1], bloc[0], bloc[1], true, board));
}
