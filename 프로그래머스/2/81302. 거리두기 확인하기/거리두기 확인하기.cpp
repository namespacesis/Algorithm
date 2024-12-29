#include <string>
#include <vector>
#include <cstring>
#include <queue>

using namespace std;

struct Node {
    int x;
    int y;
    int cnt;
};

bool visited[5][5];
int dx[4] = {0, 0, 1, -1};
int dy[4] = {1, -1, 0, 0};

bool bfs(vector<vector<string>> places, int idx, int x, int y) {
    queue<Node> q;
    q.push({x, y, 0});
    visited[x][y] = true;
    
    while (!q.empty()) {
        Node cur = q.front();
        q.pop();
        
        if (cur.cnt >= 2) continue;
        
        for (int i = 0; i < 4; i++) {
            int nx = cur.x + dx[i];
            int ny = cur.y + dy[i];
            
            if (0 > nx || nx >= 5 || 0 > ny || ny >= 5) continue;
            if (visited[nx][ny]) continue;
            
            if (places[idx][nx][ny] == 'P') {
                return false;
            }
            
            if (places[idx][nx][ny] == 'X') continue;
            
            visited[nx][ny] = true;
            q.push({nx, ny, cur.cnt + 1});
        }
    }
    
    return true;
}

vector<int> solution(vector<vector<string>> places) {
    vector<int> answer;
    
    for (int i = 0; i < 5; i++) {
        bool check = true;
        for (int j = 0; j < 5; j++) {
            if (!check) break;
            for (int k = 0; k < 5; k++) {
                if (places[i][j][k] == 'P') {
                    memset(visited, false, sizeof(visited));
                    bool flag = bfs(places, i, j, k);
                    if (!flag) {
                        check = false;
                        break;
                    }
                }
            }
        }
        if (!check) answer.push_back(0);
        else answer.push_back(1);
    }
    
    return answer;
}