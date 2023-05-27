#include<iostream>
#include<queue>
#include<vector>

using namespace std;

int n,m;
vector <int> adj[1001];
bool visited[1001];

void ReInit(){
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

int BFS(int u){
	int cnt = 1;
	queue <int> q;
	visited[u] = 1;
	q.push(u);
	while(!q.empty()){
		int v = q.front();
		q.pop();
		for(auto x : adj[v]){
			if(!visited[x]){
				cnt++;
				visited[x] = 1;
				q.push(x);
			}
		}
	}
	return cnt;
}

void LKtru(){
	for(int u=1; u<=n; ++u){
		visited[u] = 1;
		for(int v=1; v<=n; ++v){
			if(!visited[v]){
				if(BFS(v) != n-1) cout<<u<<" ";
				break;
			}
		}
		ReInit();
	}
}

main(){
	int t;
	cin>>t;
	while(t--){
		cin>>n>>m;
		adj_edge();
		LKtru();
		cout<<endl;
		ReInit();
		for(int i=1; i<=n; ++i) adj[i].clear();
	}
}
