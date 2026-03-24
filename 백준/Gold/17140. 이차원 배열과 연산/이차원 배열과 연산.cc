#include <bits/stdc++.h>

#define FastIO ios::sync_with_stdio(false), cin.tie(nullptr)
#define endl '\n'
#define ll long long

using namespace std;

struct Node {
    int num;
    int cnt;

    bool operator<(const Node& other) const {
        if (cnt == other.cnt) {
            return num < other.num;
        }
        return cnt < other.cnt;
    }
};

int r, c, k;
int arr[101][101];
int valCnt[101];
int rowCnt = 3;
int colCnt = 3;
int maxVal = 0;

void calcR() {
    vector<Node> v;
    int col = 0;
    for (int i = 1; i <= rowCnt; ++i) {
        for (int j = 1; j <= colCnt; ++j) {
            valCnt[arr[i][j]]++;
            arr[i][j] = 0;
        }

        for (int j = 1; j <= maxVal; ++j) {
            if (valCnt[j] > 0) {
                v.push_back({j, valCnt[j]});
            }
            valCnt[j] = 0;
        }

        sort(v.begin(), v.end());

        int idx = 0;

        for (auto n : v) {
            ++idx;
            arr[i][idx] = n.num;
            ++idx;
            arr[i][idx] = n.cnt;
            maxVal = max(maxVal, n.cnt);
        }

        col = max(col, idx);
        v.clear();
    }

    colCnt = max(colCnt, col);
}

void calcC() {
    vector<Node> v;
    int row = 0;
    for (int i = 1; i <= colCnt; ++i) {
        for (int j = 1; j <= rowCnt; ++j) {
            valCnt[arr[j][i]]++;
            arr[j][i] = 0;
        }

        for (int j = 1; j <= maxVal; ++j) {
            if (valCnt[j] > 0) {
                v.push_back({j, valCnt[j]});
            }
            valCnt[j] = 0;
        }

        sort(v.begin(), v.end());

        int idx = 0;

        for (auto n : v) {
            ++idx;
            arr[idx][i] = n.num;
            ++idx;
            arr[idx][i] = n.cnt;
            maxVal = max(maxVal, n.cnt);
        }

        row = max(row, idx);
        v.clear();
    }

    rowCnt = max(rowCnt, row);
}

int main() {
    FastIO;

    cin >> r >> c >> k;

    for (int i = 1; i <= 3; ++i) {
        for (int j = 1; j <= 3; ++j) {
            cin >> arr[i][j];
            maxVal = max(maxVal, arr[i][j]);
        }
    }

    int sc = 101;
    int res = -1;

    while (sc) {
        if (arr[r][c] == k) {
            res = 101 - sc;
            break;
        }
        
        if (rowCnt >= colCnt) calcR();
        else calcC();
        
        sc--;
    }

    cout << res << endl;

    return 0;
}