#include <iostream>
#include <vector>
#include <algorithm>

class FastIO {
private:
    static const int BUFFER_SIZE = 1 << 17;
    char read_buffer[BUFFER_SIZE];
    char write_buffer[BUFFER_SIZE];
    int read_ptr, read_len;
    int write_ptr;

    void fill_buffer() {
        read_len = fread(read_buffer, 1, BUFFER_SIZE, stdin);
        read_ptr = 0;
    }

    void flush_buffer() {
        fwrite(write_buffer, 1, write_ptr, stdout);
        write_ptr = 0;
    }

    char get_char() {
        if (read_ptr == read_len) fill_buffer();
        if (read_len == 0) return EOF;
        return read_buffer[read_ptr++];
    }

    void put_char(char c) {
        if (write_ptr == BUFFER_SIZE) flush_buffer();
        write_buffer[write_ptr++] = c;
    }

public:
    FastIO() : read_ptr(0), read_len(0), write_ptr(0) {}
    ~FastIO() { flush_buffer(); }

    FastIO& operator>>(int& n) {
        n = 0;
        char c = get_char();
        while (c < '0' || c > '9') c = get_char();
        while (c >= '0' && c <= '9') {
            n = n * 10 + (c - '0');
            c = get_char();
        }
        return *this;
    }
    
    FastIO& operator>>(long long& n) {
        n = 0;
        char c = get_char();
        while (c < '0' || c > '9') c = get_char();
        while (c >= '0' && c <= '9') {
            n = n * 10 + (c - '0');
            c = get_char();
        }
        return *this;
    }

    FastIO& operator<<(int n) {
        if (n == 0) { put_char('0'); return *this; }
        char temp[11];
        int i = 0;
        while (n > 0) {
            temp[i++] = (n % 10) + '0';
            n /= 10;
        }
        while (i-- > 0) {
            put_char(temp[i]);
        }
        return *this;
    }

    FastIO& operator<<(char c) {
        put_char(c);
        return *this;
    }
};

using namespace std;
using ll = long long;

const int MAX_N = 100001;
const int MAX_K = 18;

int N;
ll E[MAX_N];
vector<pair<int, int>> graph[MAX_N];
bool visited[MAX_N];
int parent[MAX_N][MAX_K];
ll cost[MAX_N][MAX_K];

void dfs(int idx) {
    for (auto& e : graph[idx]) {
        int next_node = e.first;
        int next_cost = e.second;

        if (visited[next_node]) continue;

        visited[next_node] = true;
        parent[next_node][0] = idx;
        cost[next_node][0] = next_cost;
        dfs(next_node);
    }
}

int main() {
    FastIO fio;

    fio >> N;

    for (int i = 1; i <= N; i++) {
        fio >> E[i];
    }
    
    int a, b, c;
    for (int i = 0; i < N - 1; i++) {
        fio >> a >> b >> c;
        graph[a].push_back({b, c});
        graph[b].push_back({a, c});
    }

    visited[1] = true;
    dfs(1);

    for (int k = 1; k < MAX_K; k++) {
        for (int i = 1; i <= N; i++) {
            int p = parent[i][k - 1];
            if (p != 0) {
                parent[i][k] = parent[p][k - 1];
                cost[i][k] = cost[i][k - 1] + cost[p][k - 1];
            }
        }
    }

    for (int i = 1; i <= N; i++) {
        int cur = i;
        ll energy = E[i];
        
        for (int k = MAX_K - 1; k >= 0; k--) {
            if (parent[cur][k] != 0 && cost[cur][k] <= energy) {
                energy -= cost[cur][k];
                cur = parent[cur][k];
            }
        }
        fio << cur << '\n';
    }

    return 0;
}