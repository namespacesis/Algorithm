#include <iostream>
#include <vector>
#include <string>
#include <set>
#include <algorithm>

using namespace std;

#define FastIO ios::sync_with_stdio(false), cin.tie(nullptr)
#define endl '\n'

int L;
vector<string> board;
bool usedBlock[5] = { false };
vector<vector<string>> block(5, vector<string>());
set<string> visited;
string minAns;

bool inRange(int r, int c) {
    return r >= 0 && r < L && c >= 0 && c < L;
}

bool check(int startR, int startC, int blockNum) {
    for (int i = 0; i < block[blockNum].size(); ++i) {
        for (int j = 0; j < block[blockNum][i].size(); ++j) {
            if (block[blockNum][i][j] == '#' && !inRange(startR + i, startC + j)) {
                return false;
            }
            if (block[blockNum][i][j] == '#' && board[startR + i][startC + j] != '0') {
                return false;
            }
        }
    }
    return true;
}

void fill(int startR, int startC, int blockNum) {
    for (int i = 0; i < block[blockNum].size(); ++i) {
        for (int j = 0; j < block[blockNum][i].size(); ++j) {
            if (block[blockNum][i][j] == '#') {
                board[startR + i][startC + j] = (char)(blockNum + 1 + '0');
            }
        }
    }
}

void empty(int startR, int startC, int blockNum) {
    for (int i = 0; i < block[blockNum].size(); ++i) {
        for (int j = 0; j < block[blockNum][i].size(); ++j) {
            if (block[blockNum][i][j] == '#') {
                board[startR + i][startC + j] = '0';
            }
        }
    }
}

string getBoard() {
    string s;
    for (const auto& row : board) {
        s += row;
    }
    return s;
}

bool solved() {
    for (int i = 0; i < 5; ++i) {
        if (!usedBlock[i]) return false;
    }
    for (int i = 0; i < L; ++i) {
        for (int j = 0; j < L; ++j) {
            if (board[i][j] == '0') return false;
        }
    }
    return true;
}

void dfs(int cnt) {
    string current = getBoard();

    if (solved()) {
        if (minAns.empty() || current < minAns) {
            minAns = current;
        }
        return;
    }

    if (visited.find(current) != visited.end()) return;
    visited.insert(current);

    if (!minAns.empty() && current > minAns) return;

    for (int r = 0; r < L; ++r) {
        for (int c = 0; c < L; ++c) {
            if (board[r][c] == '0') {
                for (int blockNum = 0; blockNum < 5; ++blockNum) {
                    if (usedBlock[blockNum]) continue;

                    int startC;
                    for (int i = 0; i < block[blockNum][0].size(); ++i) {
                        if (block[blockNum][0][i] == '#') {
                            startC = c - i;
                            break;
                        }
                    }

                    if (!check(r, startC, blockNum)) continue;

                    usedBlock[blockNum] = true;
                    fill(r, startC, blockNum);

                    string nextBoard = getBoard();
                    if (visited.find(nextBoard) == visited.end() && (minAns.empty() || nextBoard < minAns)) {
                        dfs(cnt + 1);
                    }

                    usedBlock[blockNum] = false;
                    empty(r, startC, blockNum);
                }
                break;
            }
        }
    }
}

int main() {
    FastIO;

    cin >> L;

    for (int i = 0; i < L; ++i) {
        board.push_back(string(L, '0'));
    }

    minAns = string(L * L, '6');

    for (int i = 0; i < 5; ++i) {
        int n, m;
        cin >> n >> m;
        vector<string> currBlock(n);
        for (int j = 0; j < n; ++j) {
            cin >> currBlock[j];
        }
        block[i] = currBlock;
    }

    dfs(0);

    if (minAns == string(L * L, '6')) {
        cout << "gg" << endl;
    }
    else {
        for (int i = 0; i < L; ++i) {
            for (int j = 0; j < L; ++j) {
                cout << minAns[i * L + j];
            }
            cout << endl;
        }
    }

    return 0;
}