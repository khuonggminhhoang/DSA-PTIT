#include<iostream>
#include<vector>

using namespace std;

int n,m;
vector <int> adj[1001];
bool visited[1001];

void adj_edge(){
	while(m--){
		int x,y;
		cin>>x>>y;
		adj[x].emplace_back(y);
		adj[y].emplace_back(x);
	}
}

bool DFS(int u, int par){
	visited[u] = 1;
	for(auto x : adj[u]){
		if(!visited[x]){
			if(DFS(x,u)) return true;
		}
		else
			if( x != par) return true;
	}
	return false;
}

void Reinit(){
	for(int i=1; i<=n; ++i){
		visited[i] = 0;
		adj[i].clear();
	}
}

main(){
	int t;
	cin>>t;
	while(t--){
		cin>>n;
		m=n-1;
		adj_edge();
		int ok =0;
		for(int i=1; i<=n; ++i){
			if(!visited[i]){
				if(DFS(i,0)) {
					ok=1;
					break;
				}
			}
		}
		if(ok) cout<<"NO\n";
		else cout<<"YES\n";
		
		
		Reinit();
	}
}

/*

2
4
1 2
1 3
2 4
4
1 2
1 3
2 3

*/
