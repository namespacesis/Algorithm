#include <iostream>
#include <vector>
#include <queue>
#include <unordered_map>
#include <unordered_set>
#include <tuple>

using namespace std;

int bfs(const unordered_map<int, vector<int>>& station_to_lines,
    const unordered_map<int, vector<int>>& line_to_stations,
    int start, int end) {

    queue<tuple<int, int, int>> q;
    unordered_set<int> visited_stations;
    unordered_set<int> visited_lines;
    q.push({ start, -1, 0 });
    visited_stations.insert(start);

    while (!q.empty()) {
        auto [current_station, current_line, transfers] = q.front();
        q.pop();

        if (current_station == end) {
            return transfers;
        }

        for (int line : station_to_lines.at(current_station)) {
            if (line != current_line && visited_lines.find(line) == visited_lines.end()) {
                visited_lines.insert(line);
                for (int next_station : line_to_stations.at(line)) {
                    if (next_station == end) {
                        return transfers;
                    }
                    if (visited_stations.find(next_station) == visited_stations.end()) {
                        visited_stations.insert(next_station);
                        q.push({ next_station, line, transfers + 1 });
                    }
                }
            }
        }
    }

    return -1;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);

    int N;
    cin >> N;

    unordered_map<int, vector<int>> station_to_lines;
    unordered_map<int, vector<int>> line_to_stations;

    for (int line_num = 1; line_num <= N; ++line_num) {
        int K;
        cin >> K;
        vector<int> stations(K);
        for (int i = 0; i < K; ++i) {
            cin >> stations[i];
        }
        line_to_stations[line_num] = stations;
        for (int station : stations) {
            station_to_lines[station].push_back(line_num);
        }
    }

    int destination;
    cin >> destination;

    if (destination == 0) {
        cout << 0 << "\n";
        return 0;
    }

    int result = bfs(station_to_lines, line_to_stations, 0, destination);
    cout << result << "\n";

    return 0;
}
