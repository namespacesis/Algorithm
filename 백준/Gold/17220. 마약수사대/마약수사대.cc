#include<bits/stdc++.h>

using namespace std;
int n, m;
vector<int> adj[27];
bool Root[27];
int vis[27];
int toInt = 'A' - 1;
int root;

void bfs(int r){
	queue<int>q;
	q.push(r);
	
	while(!q.empty()){
		int cur = q.front();q.pop();
		
		for(auto nxt : adj[cur]){
			if(vis[nxt] != 0) continue;
			vis[nxt] = 1;
			q.push(nxt);
		}
	}
}
int main(){
	ios::sync_with_stdio(0);
	cin.tie(0);
	cin >> n >> m;
		
	for(int i = 0; i <m; i++){
		char a,b;
		cin >> a >> b;
		adj[a - toInt].push_back(b - toInt);
		Root[b-toInt] = 1;
	}
	int k = 0;
	cin >> k;
	vector<int> del;
	for(int i = 0; i < k; i++){
		char h;
		cin >> h;
		adj[h-toInt].clear();
		del.push_back(h-toInt);
	}
	for(int i = 1; i <= n; i++){
		if(Root[i] == 0){
			root = i;
			vis[i] = 2;
			bfs(i);
		}
	}
	
	
	int ans = 0;
	for(auto de : del){
		vis[de] = 0;		
	}
	for(int i = 1; i <=n; i++){
		if(vis[i] == 1)
			ans++;
	}
	cout << ans << '\n';
	return 0;
}