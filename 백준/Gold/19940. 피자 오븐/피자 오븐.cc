#include <iostream>
#include <queue>

#define FastIO ios::sync_with_stdio(false), cin.tie(nullptr);

using namespace std;

struct Info {
    int ADDH;
    int ADDT;
    int MINT;
    int ADDO;
    int MINO;
    int time;
};

int T;
int N;
Info arr[61];
bool visited[61];

int main() {
    FastIO;

    cin >> T;

    queue<Info> q;
    q.push({ 0, 0, 0, 0, 0, 0 });

    while (!q.empty()) {
        Info cur = q.front();
        q.pop();

        if (cur.time < 0 || cur.time > 60) continue;

        if (visited[cur.time]) continue;

        visited[cur.time] = true;
        arr[cur.time] = cur;

        q.push({ cur.ADDH, cur.ADDT, cur.MINT, cur.ADDO, cur.MINO + 1, cur.time - 1 });
        q.push({ cur.ADDH, cur.ADDT, cur.MINT, cur.ADDO + 1, cur.MINO, cur.time + 1 });
        q.push({ cur.ADDH, cur.ADDT, cur.MINT + 1, cur.ADDO, cur.MINO, cur.time - 10 });
        q.push({ cur.ADDH, cur.ADDT + 1, cur.MINT, cur.ADDO, cur.MINO, cur.time + 10 });
        q.push({ cur.ADDH + 1, cur.ADDT, cur.MINT, cur.ADDO, cur.MINO, cur.time + 60 });
    }

    while (T--) {
        cin >> N;

        int M = N / 60;
        int S = N % 60;

        cout << arr[S].ADDH + M << " " << arr[S].ADDT << " " << arr[S].MINT << " " << arr[S].ADDO << " " << arr[S].MINO << "\n";
    }

    return 0;
}
