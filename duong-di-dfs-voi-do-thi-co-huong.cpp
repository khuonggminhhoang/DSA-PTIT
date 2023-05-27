#include<iostream>
#include<stack>
#include<vector>
#include<queue>

using namespace std;

vector <int> Ke[1001];
int truoc[1001];
int visited[1001];
/*
void DFS(int s, int t){
	stack <int> stk;
	visited[s]=1;
	stk.push(s);
	while(!stk.empty()){
		if(visited[t]==1) return;
		int y = stk.top();
		stk.pop();
		for(auto x:Ke[y]){
			if(visited[x]==0){
			
				visited[x]=1;
				truoc[x]=y;
				stk.push(y);
				stk.push(x);
				break;
			}
		}
	}
}
*/
void BFS(int s, int t){
	queue <int> q;
	q.push(s);
	visited[s]=1;
//	cout<<s<<" ";
	while(!q.empty()){
		int y = q.front();
		q.pop();
		if(y==t) return;
		for(auto x: Ke[y]){
			if(visited[x]==0){
				//cout<<x<<" ";
				visited[x]=1;
				q.push(x);
				truoc[x]=y;
			}
		}
	}
	
}

void print(int u, int v){
	vector <int> a;
	while(u!=v){
		if(u==0){
			cout<<-1;
			return;
		}
		a.push_back(u);
		u=truoc[u];
	}
	a.push_back(v);
	for(int i=a.size()-1; i>=0; --i){
		cout<<a[i]<<" ";
	}
}

main(){
	int t;
	cin>>t;
	while(t--){
		for(int i=0; i<1001; ++i){
			Ke[i].clear();
		}
		int V,E,s,t;
		cin>>V>>E>>s>>t;
		while(E--){
			int u,v;
			cin>>u>>v;
			Ke[u].push_back(v);
		}
		for(int i=1; i<=V; ++i){
			visited[i]=0;
		}
		BFS(s,t);
		print(t,s);
		cout<<endl;
	}
}


