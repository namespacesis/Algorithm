#include <string>
#include <vector>

using namespace std;

int dp[151][151];
int maxAlp = 0;
int maxCop = 0;

int solution(int alp, int cop, vector<vector<int>> problems) {
    
    for (const auto& p : problems) {
        maxAlp = max(maxAlp, p[0]);
        maxCop = max(maxCop, p[1]);
    }

    alp = min(alp, maxAlp);
    cop = min(cop, maxCop);

    for (int i = 0; i <= maxAlp; i++) {
        for (int j = 0; j <= maxCop; j++) {
            dp[i][j] = 1e9;
        }
    }
    
    dp[alp][cop] = 0;
    
    for (int i = alp; i <= maxAlp; i++) {
        for (int j = cop; j <= maxCop; j++) {
            
            //if (dp[i][j] == 1e9) continue;

            dp[i + 1][j] = min(dp[i + 1][j], dp[i][j] + 1);

            dp[i][j + 1] = min(dp[i][j + 1], dp[i][j] + 1);

            for (const auto& p : problems) {
                int alp_req = p[0];
                int cop_req = p[1];
                int alp_rwd = p[2];
                int cop_rwd = p[3];
                int cost = p[4];
                
                if (i >= alp_req && j >= cop_req) {
                    int next_alp = i + alp_rwd;
                    int next_cop = j + cop_rwd;
                    
                    next_alp = min(next_alp, maxAlp);
                    next_cop = min(next_cop, maxCop);
                    
                    dp[next_alp][next_cop] = min(dp[next_alp][next_cop], dp[i][j] + cost);
                }
            }
        }
    }
    
    return dp[maxAlp][maxCop];
}