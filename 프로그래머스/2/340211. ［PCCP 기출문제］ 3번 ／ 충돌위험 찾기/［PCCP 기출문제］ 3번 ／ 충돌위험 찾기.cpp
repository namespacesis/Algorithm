#include <vector>
#include <unordered_map>

using namespace std;

unordered_map<int, pair<int, int>> pointMap;
unordered_map<int, unordered_map<int, int>> grid;
int res = 0;

void simulate(vector<int>& route) {
    pair<int, int> curPos = pointMap[route[0]];
    int t = 0;
    
    for (int i = 1; i < route.size(); i++) {
        pair<int, int> nextPos = pointMap[route[i]];
        
        while (curPos != nextPos) {
            grid[t][curPos.first * 1000 + curPos.second]++;
            if (grid[t][curPos.first * 1000 + curPos.second] == 2) res++;
            
            if (curPos.first != nextPos.first)
                curPos.first += (curPos.first < nextPos.first) ? 1 : -1;
            else
                curPos.second += (curPos.second < nextPos.second) ? 1 : -1;
            
            t++;
        }
    }
    grid[t][curPos.first * 1000 + curPos.second]++;
    if (grid[t][curPos.first * 1000 + curPos.second] == 2) res++;
}

int solution(vector<vector<int>> points, vector<vector<int>> routes) {
    int n = points.size();
    int x = routes.size();
    
    for (int i = 0; i < n; i++) {
        pointMap[i + 1] = {points[i][0], points[i][1]};
    }
    
    for (auto& route : routes) {
        simulate(route);
    }
    
    return res;
}
