#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;
vector<int> A;
int N, K, T;
void input()
{
    ios::sync_with_stdio(0), cin.tie(0);
    cin >> N >> K >> T;
    A = vector<int>(N);
    for (int &a : A)
    {
        cin >> a;
    }
}
bool solve()
{
    sort(A.begin(), A.end());
    int start = 0, end = N - 1;

    while (start < end)
    {
        int gap = min(A[start], K - A[end]);

        T -= gap;
        if (T < 0) // 횟수를 넘어간다면
        {
            return false;
        }

        A[end] += gap;
        A[start] -= gap;

        if (A[start] == 0) // 비어있다면
        {
            ++start;
        }
        if (A[end] == K) // 터졌다면
        {
            --end;
        }
    }
    return A[start] == 0 || A[start] == K; // 터졌거나 비어있다면
}
int main()
{
    input();
    cout << (solve() ? "YES" : "NO");
    return 0;
}