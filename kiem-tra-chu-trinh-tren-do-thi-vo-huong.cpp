#include<iostream>
#include<queue>
#include<vector>

using namespace std;

int n,m;
bool visited[1001];
vector <int> adj[1001];

void Init(){
	for(int i=1; i<=n; ++i){
		visited[i] = 0;
	}
}

void adj_edge(){
	while(m--){
		int x,y;
		cin>>x>>y;
		adj[x].push_back(y);
		adj[y].push_back(x);
	}
}

bool DFS(int u, int par){
	visited[u] = true;
	for(auto x : adj[u]){
		if(!visited[x]){
			if(DFS(x,u)) return true;
		}
		else{
			if(x != par) return true;
		}
	}
	return false;
}

main(){
	int t;
	cin>>t;
	while(t--){
		cin>>n>>m;
		adj_edge();
		int ok =0;
		for(int i=1; i<=n; ++i){
			if(!visited[i]){
				if(DFS(i,0)) {
					cout<<"YES\n";
					ok=1;
					break;
				}
			}
		}
		if(!ok) cout<<"NO\n";
		Init();
		for(int i=1; i<=n;++i) adj[i].clear();
	}
}
