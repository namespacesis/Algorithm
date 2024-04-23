#include <iostream>
#include <queue>

using namespace std;

int R, C;
int Hr, Hc;
string record;
int len;
char arr[1001][1001];
bool visited[1001][1001];
char res[1001][1001];
int dx[4] = { 1, -1, 0, 0 };
int dy[4] = { 0, 0, 1, -1 };

void bfs(int x, int y) {
	queue<pair<int, int>> q;
	q.push({ x, y });
	visited[x][y] = true;
	res[x][y] = '.';

	while (!q.empty()) {
		pair<int, int> cur = q.front();
		q.pop();

		for (int i = 0; i < 4; i++) {
			int nx = cur.first + dx[i];
			int ny = cur.second + dy[i];
			
			if (0 < nx && nx <= R && 0 < ny && ny <= C && !visited[nx][ny] && arr[nx][ny] == arr[x][y]) {
				visited[nx][ny] = true;
				res[nx][ny] = '.';
				q.push({ nx, ny });
			}
		}
	}
}

int main() {
	ios::sync_with_stdio(false);
	cin.tie(nullptr);
	cout.tie(nullptr);

	cin >> R >> C;

	for (int i = 1; i <= R; i++) {
		for (int j = 1; j <= C; j++) {
			cin >> arr[i][j];
			res[i][j] = '#';
		}
	}

	cin >> Hr >> Hc;

	cin >> record;
	len = record.size();
	
	for (int i = 0; i < len; i++) {
		if (record[i] == 'W') {
			bfs(Hr, Hc);
		}
		else if (record[i] == 'L') {
			Hc -= 1;
		}
		else if (record[i] == 'R') {
			Hc += 1;
		}
		else if (record[i] == 'U') {
			Hr -= 1;
		}
		else if (record[i] == 'D') {
			Hr += 1;
		}

		if (i == len - 1) {
			res[Hr][Hc] = '.';
			for (int i = 0; i < 4; i++) {
				int nx = Hr + dx[i];
				int ny = Hc + dy[i];

				if (0 < nx && nx <= R && 0 < ny && ny <= C) {
					res[nx][ny] = '.';
				}
			}
		}
	}

	for (int i = 1; i <= R; i++) {
		for (int j = 1; j <= C; j++) {
			cout << res[i][j];
		}
		cout << "\n";
	}
	
	return 0;
}