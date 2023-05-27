#include<iostream>
#include<queue>

using namespace std;

vector <int> adj[1001];
int degree[1001];
int n,m;

void adj_edge(){
	while(m--){
		int x,y;
		cin>>x>>y;
		adj[x].emplace_back(y);
		degree[y]++;
	}
}

int Kahn(){
	queue <int> q;
	for(int i = 1; i<=n; ++i){
		if(degree[i] == 0) q.push(i);
	}
	int cnt = 0;
	while(!q.empty()){
		int v = q.front();
		q.pop();
		++cnt;
		for(auto x : adj[v]){
			degree[x]--;
			if(degree[x] == 0) q.push(x);
		}
	}
	return cnt;
}

void Reinit(){
	for(int i=1; i<=n; ++i){
		degree[i] = 0;
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
		if(Kahn() != n) ok = 1;
		if(ok) cout<<"YES\n";
		else cout<<"NO\n";
		Reinit();
	}
}
