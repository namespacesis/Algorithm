#include <iostream>
#include <cstring>

using namespace std;

int N;
int travel_cost[16][16];
int visited[16][(1 << 16) - 1];
const int MAXN = 17000001;
int all_visit;

int TravelCities(int now_city, int vis) {

    if (vis == all_visit) {
        if (travel_cost[now_city][0] != 0)
            return travel_cost[now_city][0];
        else
            return MAXN;
    }

    int& ret = visited[now_city][vis];
    if (ret != -1)
        return ret;

    ret = MAXN;
    for (int i = 0; i < N; ++i)
        if ((~vis & (1 << i)) && travel_cost[now_city][i] != 0)
            ret = min(ret, TravelCities(i, vis | (1 << i)) + travel_cost[now_city][i]);

    return ret;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);

    cin >> N;

    all_visit = (1 << N) - 1;

    for (int i = 0; i < N; ++i)
        for (int j = 0; j < N; ++j)
            cin >> travel_cost[i][j];

    memset(visited, -1, sizeof(visited));

    cout << TravelCities(0, 1) << "\n";
    return 0;
}