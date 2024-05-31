#include <iostream>
#include <queue>
#include <vector>

#define fastIO ios::sync_with_stdio(false), cin.tie(nullptr), cout.tie(nullptr)
#define MAXN 1000
#define INF 1e9

using namespace std;

int n, m, A, B;
vector<int> fl[101], elevator[100001];
int cnt[101], parent[101];
int last;

int bfs() {
    int mn = INF;
    queue<int> q;

    for (int i = 0; i < elevator[A].size(); i++) {
        bool flag = false;
        for (int j = 0; j < elevator[B].size(); j++) {
            if (elevator[A][i] == elevator[B][j]) {
                flag = true;
            }
        }
        if (flag) {
            last = elevator[A][i];
            return mn = 1;
        }
        else {
            cnt[elevator[A][i]] = 1;
            q.push(elevator[A][i]);
        }
    }

    while (!q.empty()) {
        int ele = q.front();
        q.pop();

        for (int i = 0; i < fl[ele].size(); i++) {
            int other = fl[ele][i];
            if (other == B) {
                last = ele;
                return mn = cnt[ele];
            }
            else {
                for (int j = 0; j < elevator[other].size(); j++) {
                    if (cnt[elevator[other][j]] == 0) {
                        cnt[elevator[other][j]] = cnt[ele] + 1;
                        parent[elevator[other][j]] = ele;
                        q.push(elevator[other][j]);
                    }
                }
            }
        }
    }

    return mn;
}

void print(int num) {
    if (num == 0) return;
    print(parent[num]);
    cout << num << "\n";
}

int main() {
    fastIO;
    int x, y, ans;

    cin >> n >> m;

    for (int i = 1; i <= m; i++) {
        cin >> x >> y;

        while (x <= n) {
            fl[i].push_back(x);
            elevator[x].push_back(i);
            x += y;
        }
    }

    cin >> A >> B;

    ans = bfs();
    if (ans >= INF) {
        cout << "-1\n";
    }
    else {
        cout << ans << "\n";
        print(last);
    }

    return 0;
}
