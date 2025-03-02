#include <iostream>

#define FastIO ios::sync_with_stdio(false), cin.tie(nullptr)
#define endl '\n'
#define ll long long

using namespace std;

int N, cnt;
ll res = -1;

void backTracking(ll num, int size)
{
    if (size == 0) {
        if (cnt == N)
            res = num;
        cnt++;
        return;
    }

    int last = num % 10;
    if (num == 0) last = 10;
    for (int i = 0; i < last; i++) {
        ll nextNum = (num * 10) + i;
        if (num == 0 && i == 0) continue;

        backTracking(nextNum, size - 1);
    }
}

int main() {
    FastIO;

    cin >> N;

    for (int i = 0; i <= 10; i++) {
        backTracking(0, i);
    }

    cout << res << endl;

    return 0;
}