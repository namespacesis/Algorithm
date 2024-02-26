#include <iostream>
#include <cmath>

using namespace std;

int first[500001];
int second[1000001];
long long tree[500001];
int N, val;
long long res = 0;

long long sum(int idx) {
    long long temp = 0;
    while (idx) {
        temp += tree[idx];
        idx = idx - (idx & -idx);
    }
    return temp;
}

void update(int idx) {
    while (idx <= N) {
        tree[idx] += 1;
        idx = idx + (idx & -idx);
    }
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);

    cin >> N;

    for (int i = 1; i <= N; i++) {
        cin >> first[i];
    }

    for (int i = 1; i <= N; i++) {
        cin >> val;
        second[val] = i;
    }

    for (int i = 1; i <= N; i++) {
        int arrive = second[first[i]];
        update(arrive);
        res += (i - sum(arrive));
    }

    cout << res << "\n";
    return 0;
}