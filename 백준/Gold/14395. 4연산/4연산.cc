#include <iostream>
#include <queue>
#include <unordered_set>

#define FastIO ios::sync_with_stdio(false), cin.tie(nullptr), cout.tie(nullptr);
#define ll long long

using namespace std;

struct Node {
    ll x;
    string path;
};

ll s, t;
unordered_set<ll> us;

string bfs() {
    queue<Node> q;
    q.push({s, ""});
    us.insert(s);

    while (!q.empty()) {
        Node cur = q.front();
        q.pop();

        if (cur.x == t) {
            return cur.path;
        }

        ll nx;

        nx = cur.x * cur.x;

        if (us.find(nx) == us.end()) {
			us.insert(nx);
			q.push({nx, cur.path + "*"});
		}

        nx = cur.x + cur.x;

        if (us.find(nx) == us.end()) {
            us.insert(nx);
            q.push({ nx, cur.path + "+" });
        }

        nx = 0;

        if (us.find(nx) == us.end()) {
			us.insert(nx);
			q.push({ nx, cur.path + "-" });
		}

        if (cur.x != 0) {
            nx = 1;

            if (us.find(nx) == us.end()) {
                us.insert(nx);
                q.push({ nx, cur.path + "/" });
            }
        }
    }

    return "-1";
}

int main() {
    FastIO;

    cin >> s >> t;

    if (s == t) {
        cout << 0 << "\n";
    }
    else {
        cout << bfs() << "\n";
    }

    return 0;
}
