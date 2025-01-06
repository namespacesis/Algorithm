#include <iostream>
#include <queue>
#include <vector>
#include <algorithm>
#include <cstring>
#include <limits>

#define FastIO ios::sync_with_stdio(false), cin.tie(nullptr)
#define endl '\n'
using namespace std;

static const int INF = numeric_limits<int>::max();

// 우선순위 큐에 넣을 노드 정보
//  - x, y : 모서리(격자선 교차점)의 좌표
//  - t    : 지금까지 회전 횟수
struct Node {
    int x, y, t; // t = 회전횟수
    Node(int _x, int _y, int _t) : x(_x), y(_y), t(_t) {}
};

// 우선순위 큐에서 회전 횟수(t)가 작은 순으로 정렬
struct cmp {
    bool operator()(const Node &a, const Node &b) {
        return a.t > b.t;
    }
};

int N, M;

// '\' -> 0, '/' -> 1
int arr[501][501];   // 타일 정보 (N×M)
int dp[501][501];    // dp[x][y] = (x,y)까지 최소 회전 횟수

// 이동 방향 4가지 (자바 코드와 동일)
int dx[4] = {-1, +1, +1, -1};
int dy[4] = {+1, +1, -1, -1};

// needRotate(x, y, d) : (x,y)에서 방향 d로 이동시, 지나가는 타일이 회전이 필요한지 여부
bool needRotate(int x, int y, int d) {
    // d==0 -> 위+오른쪽 → 지나가는 타일 = arr[x-1][y]
    // d==1 -> 아래+오른쪽 -> 지나가는 타일 = arr[x][y]
    // d==2 -> 아래+왼쪽 -> 지나가는 타일 = arr[x][y-1]
    // d==3 -> 위+왼쪽 -> 지나가는 타일 = arr[x-1][y-1]
    if (d == 0) {
        // x-1 >= 0, y >= 0
        return arr[x-1][y] == 0; // '\'인지(==0)? => 회전 필요(true) 
    } else if (d == 1) {
        // x >= 0, y >= 0
        return arr[x][y] == 1;   // '/'인지(==1)? => 회전 필요(true)
    } else if (d == 2) {
        // x >= 0, y-1 >= 0
        return arr[x][y-1] == 0; 
    } else {
        // d == 3
        // x-1 >= 0, y-1 >= 0
        return arr[x-1][y-1] == 1; 
    }
}

// 다익스트라(또는 0-1 BFS 유사) 방식으로 최소 회전 횟수 탐색
void zeroOneBfs() {
    // dp[x][y] = INF 로 초기화
    for(int i=0; i<=N; i++){
        for(int j=0; j<=M; j++){
            dp[i][j] = INF;
        }
    }
    dp[0][0] = 0;

    priority_queue<Node, vector<Node>, cmp> pq;
    pq.push(Node(0, 0, 0));

    while(!pq.empty()) {
        Node cur = pq.top();
        pq.pop();

        int x = cur.x;
        int y = cur.y;
        int t = cur.t;

        // 이미 더 좋은(회전수 적은) 경로가 dp[x][y]에 있으면 패스
        if(dp[x][y] < t) continue;

        // 목표 도착점: (N, M)에 도달하면 멈춰도 됨
        if(x == N && y == M) break;

        // 4가지 방향으로 이동
        for(int d=0; d<4; d++){
            int nx = x + dx[d];
            int ny = y + dy[d];
            // 범위 체크: (0 <= nx <= N, 0 <= ny <= M)
            if(nx < 0 || nx > N || ny < 0 || ny > M) continue;

            // 이동에 필요한 회전 증가 여부
            int cost = needRotate(x, y, d) ? 1 : 0;
            int nt = t + cost;

            if(dp[nx][ny] > nt){
                dp[nx][ny] = nt;
                pq.push(Node(nx, ny, nt));
            }
        }
    }
}

int main(){
    FastIO;

    cin >> N >> M;
    // arr[][]: N행 M열
    for(int i=0; i<N; i++){
        string row;
        cin >> row;
        for(int j=0; j<M; j++){
            if(row[j] == '/') arr[i][j] = 1;
            else arr[i][j] = 0;  // '\' 
        }
    }

    // 최소 회전 횟수 구하기
    zeroOneBfs();

    // dp[N][M] == INF 이면 도달 불가
    if(dp[N][M] == INF) {
        cout << "NO SOLUTION" << endl;
    } else {
        cout << dp[N][M] << endl;
    }

    return 0;
}
