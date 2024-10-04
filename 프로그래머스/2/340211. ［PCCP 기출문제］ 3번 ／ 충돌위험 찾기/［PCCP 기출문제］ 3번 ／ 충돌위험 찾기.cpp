#include <string>
#include <vector>
#include <unordered_map>

using namespace std;

unordered_map<int, pair<int, int>> am;
unordered_map<int, int> um;
int res = 0;

int makeHash(pair<int, int> p, int t) {
    return p.first * 10000000 + p.second * 100000 + t;
}

void simulate(vector<int> &route) {
    int t = 0;
    pair<int, int> end;
    
    for (int i = 0; i < route.size() - 1; i++) {
        pair<int, int> start = am[route[i]];
        pair<int, int> next = am[route[i + 1]];
        end = next;
        
        while (start != next) {
            int bh = makeHash(start, t);
            um[bh]++;
            if (um[bh] == 2) res++;
            
            int diffX = start.first - next.first;
            int diffY = start.second - next.second;
            
            if (diffX != 0) {
                diffX > 0 ? start.first-- : start.first++;
            }
            else if (diffY != 0) {
                diffY > 0 ? start.second-- : start.second++;
            }
            
            t++;
        }
    }
    int eh = makeHash(end, t);
    um[eh]++;
    if (um[eh] == 2) res++;
}

int solution(vector<vector<int>> points, vector<vector<int>> routes) {
    int answer = 0;
    
    for (int i = 1; i <= points.size(); i++) {
        am[i] = {points[i - 1][0], points[i - 1][1]};
    }
    
    for (auto route : routes) {
        simulate(route);
    }
    
    answer = res;
    
    return answer;
}