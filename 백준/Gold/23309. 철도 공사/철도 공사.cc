#include <iostream>
#include <unordered_map>
using namespace std;

struct Station {
    int id;
    Station* next;
    Station* prev;
    Station(int id) : id(id), next(nullptr), prev(nullptr) {}
};

int N, M;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);

    cin >> N >> M;

    unordered_map<int, Station*> stationMap;

    int firstStationID;
    cin >> firstStationID;
    Station* firstStation = new Station(firstStationID);
    stationMap[firstStationID] = firstStation;
    Station* lastStation = firstStation;

    for (int i = 1; i < N; ++i) {
        int stationID;
        cin >> stationID;
        Station* newStation = new Station(stationID);
        lastStation->next = newStation;
        newStation->prev = lastStation;
        stationMap[stationID] = newStation;
        lastStation = newStation;
    }

    firstStation->prev = lastStation;
    lastStation->next = firstStation;

    for (int i = 0; i < M; ++i) {
        char operation;
        cin >> operation;
        if (operation == 'B') {
            char direction;
            int i, j;
            cin >> direction >> i >> j;
            Station* station = stationMap[i];
            Station* newStation = new Station(j);

            if (direction == 'N') {
                cout << station->next->id << '\n';
                newStation->next = station->next;
                station->next->prev = newStation;
                station->next = newStation;
                newStation->prev = station;
            }
            else {
                cout << station->prev->id << '\n';
                newStation->prev = station->prev;
                station->prev->next = newStation;
                station->prev = newStation;
                newStation->next = station;
            }
            stationMap[j] = newStation;
        }
        else if (operation == 'C') {
            char direction;
            cin >> direction;
            int i;
            cin >> i;
            Station* station = stationMap[i];
            Station* targetStation;

            if (direction == 'N') {
                targetStation = station->next;
                cout << targetStation->id << '\n';
                station->next = targetStation->next;
                targetStation->next->prev = station;
            }
            else {
                targetStation = station->prev;
                cout << targetStation->id << '\n';
                station->prev = targetStation->prev;
                targetStation->prev->next = station;
            }
            stationMap.erase(targetStation->id);
            delete targetStation;
        }
    }

    for (auto& p : stationMap) {
        delete p.second;
    }

    return 0;
}
