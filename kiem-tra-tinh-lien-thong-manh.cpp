#include<iostream>
#include<queue>
#include<vector>
#include<cstring>

using namespace std;

vector <int> adj[1001];
bool visited[1001];
int n,m;

void ReInit(){
	memset(visited, false, sizeof(visited));
}

void adj_edge(){
	while(m--){
		int x,y;
		cin>>x>>y;
		adj[x].push_back(y);
	}
}

int BFS(int u){
	int cnt = 1;
	queue <int> q;
	q.push(u);
	visited[u] = 1;
	while(!q.empty()){
		int v = q.front();
		q.pop();
		for(auto x : adj[v]){
			if(!visited[x]){
				visited[x] = 1;
				cnt++;
				q.push(x);
			}
		}
		
	}
	return cnt;
}

bool Strong_connective(){
	for(int i=1; i<=n; ++i){
		if(BFS(i) != n) return false;
		ReInit();
	}
	return true;
}

main(){
	int t;
	cin>>t;
	while(t--){
		cin>>n>>m;
		adj_edge();
		if(Strong_connective()) cout<<"YES\n";
		else cout<<"NO\n";
		ReInit();
		for(int i=1; i<=n; ++i) adj[i].clear();
	}
}
