#include<iostream>
#include<stack>
#include<vector>
#include<queue>

using namespace std;

vector <int> adj[1001];
bool visited[1001];
int trace[1001];
int n,m,s,e;

void adj_edge(){
	while(m--){
		int x,y;
		cin>>x>>y;
		adj[x].push_back(y);
		adj[y].push_back(x);
	}
}

void Init(){
	for(int i=1; i<=n; ++i){
		visited[i] = 0;
		trace[i] = 0;
	}
	for(int i=1; i<=n; ++i) adj[i].clear();
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
				trace[x] = v;
				visited[x]=1;
				stk.push(v);
				stk.push(x);
				break;
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
				trace[x] = v;
				q.push(x);
			}
		}
	}	
}

void Trace(int s, int e){
	vector <int> a; 
	while(e != s){
		a.push_back(e);
		e = trace[e];
		if(e == 0){
			cout<<-1<<endl;
			return;
		}
	}
	a.push_back(e);
	for(int i = a.size()-1; i>=0; --i) cout<<a[i]<<" ";
	cout<<endl;
}

main(){
	int t;
	cin>>t;
	while(t--){
		cin>>n>>m>>s>>e;
		adj_edge();
		BFS(s);
		Trace(s,e);
		Init();
	}
}

/*

2
6  9 1 6
1 2 1 3 2 3 2 5 3 4 3 5 4 5 4 6 5 6
6  9 2 6
1 2 1 3 2 3 2 5 3 4 3 5 4 5 4 6 5 6

*/

