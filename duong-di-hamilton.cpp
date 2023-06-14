#include<iostream>
#include<vector>
#include<cstring>

using namespace std;

int V, E, ok;
bool visited[11];
vector <int> adj[11];

void inp(){
	cin>>V>>E;
	while(E--){
		int x, y;
		cin>>x>>y;
		adj[x].push_back(y);
		adj[y].push_back(x);
	}
}

void DFS(int u, int cnt){
	if(cnt == V){
		ok = 1;
		return;
	}
	visited[u] = 1;
	for(auto v : adj[u]){
		if(!visited[v]){
			DFS(v,cnt+1);
		}
	}
}

void setup(){
	for(int i=1; i<=V; ++i){
		visited[i] = 0;
		adj[i].clear();
		ok = 0;
	}
}

main(){
	int t;
	cin>>t;
	while(t--){
		inp();
		for(int i=1; i<=V; ++i){
			DFS(i,1);
			if(ok) break;
			memset(visited, false, sizeof(visited));
		}
		if(ok) cout<<1<<endl;
		else cout<<0<<endl;
		setup();
	}
}


