#include<iostream>
#include<vector>

using namespace std;

vector <int> adj[1001];
int color[1001];
int n,m;

void adj_edge(){
	while(m--){
		int x,y;
		cin>>x>>y;
		adj[x].emplace_back(y);
	}
}

bool DFS(int u){
	color[u] = 1;
	for(auto v : adj[u]){
		if(color[v] == 0){
			if(DFS(v)) return true;
		}
		if(color[v] == 1) return true;
	}
	color[u] = 2;
	return false;
}

void Reinit(){
	for(int i=1; i<=n; ++i){
		color[i] = 0;
		adj[i].clear();
	}
}

main(){
	int t;
	cin>>t;
	while(t--){
		cin>>n>>m;
		adj_edge();
		int ok = 0;
		for(int i=1; i<=n; ++i){
			if(DFS(i)){
				ok=1;
				break;
			}
		}
		if(ok ==1) cout<<"YES\n";
		else cout<<"NO\n";
		Reinit();
	}
}
