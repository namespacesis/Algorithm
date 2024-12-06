#include <iostream>
#include <vector>
#include <algorithm>

#define FastIO ios::sync_with_stdio(false), cin.tie(nullptr);
#define endl '\n'

using namespace std;

int N;
int M;

int main() {
    FastIO;

    cin >> N;

    vector<int> cranes(N);

    for (int i = 0; i < N; i++) {
        cin >> cranes[i];
    }

    sort(cranes.begin(), cranes.end());

    cin >> M;

    vector<int> boxes(M);

    for (int i = 0; i < M; i++) {
        cin >> boxes[i];
    }

    sort(boxes.begin(), boxes.end(), greater<int>());

    vector<int> cranesCnt(N, 0);

    for (int i = 0; i < M; i++) {
        for (int j = 0; j < N; j++) {
            if (cranes[j] >= boxes[i]) {
                int cnt = cranesCnt[j];
                int idx = j;
                for (int k = j + 1; k < N; k++) {
                    if (cranesCnt[k] <= cnt) {
                        cnt = cranesCnt[k];
                        idx = k;
                    }
                }
                cranesCnt[idx]++;
                break;
            }
        }
    }

    int res = 0;
    int cnt = 0;

    for (int i = 0; i < N; i++) {
        res = max(res, cranesCnt[i]);
        cnt += cranesCnt[i];
    }

    if (cnt < M) res = -1;

    cout << res << endl;

    return 0;
}
