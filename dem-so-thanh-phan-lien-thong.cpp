#include<iostream>
#include<stack>
#include<vector>
#include<cstring>
#include<queue>

using namespace std;

int n,m;
vector <int> adj[1001];
bool visited[1001];

void Init(){
	memset(visited, false, sizeof(visited));
	for(int i=1; i<=n; ++i) adj[i].clear();
}

void adj_edge(){
	while(m--){
		int x,y;
		cin>>x>>y;
		adj[x].push_back(y);
		adj[y].push_back(x);
	}
}

void DFS(int u){
	stack <int> stk;
	stk.push(u);
	visited[u] = 1;
	while(!stk.empty()){
		int v = stk.top();
		stk.pop();
		for(auto x : adj[v]){
			if(!visited[x]){
				visited[x] = 1;
				stk.push(v);
				stk.push(x);
			}
		}
	}
}

void BFS(int u){
	queue <int> q;
	q.push(u);
	visited[u] = 1;
	while(!q.empty()){
		int v = q.front();
		q.pop();
		for(auto x : adj[v]){
			if(!visited[x]){
				visited[x] = 1;
				q.push(x);
			}
		}
	}
}

int counter(){
	int cnt = 0;
	for(int i=1; i<=n; ++i){
		if(!visited[i]){
			BFS(i);
			cnt++;
		}
	}
	return cnt;
}

main(){
	int t;
	cin>>t;
	while(t--){
		cin>>n>>m;
		adj_edge();
		cout<<counter()<<endl;
		Init();
	}
}
