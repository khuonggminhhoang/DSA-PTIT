#include<iostream>
#include<stack>
#include<vector>

using namespace std;

void adjacent_edge( vector <int> adj[], int m ){
    while(m--){
        int x,y;
        cin>>x>>y;
        adj[x].push_back(y);
        adj[y].push_back(x);
    }
}

void print(vector <int> adj[], int n){
    for(int i=1; i<=n; ++i){
        cout<<i<<":";
        for(int j=0; j<adj[i].size(); ++j){
            cout<<adj[i][j]<<" ";
        }
        cout<<endl;
    }
}

void DFS(int u, vector <int> adj[], int visited[]){
    stack <int> stk;
    visited[u] = 1;
    stk.push(u);
    while(!stk.empty()){
    	int s = stk.top();
    	stk.pop();
    	for( auto x : adj[s]){
    		if(!visited[x]){
	    		visited[x] = 1;
	    		stk.push(s);
	    		stk.push(x);
	    		break;
			}
		}
	}
}

int main(){
    int t;
    cin>>t;
    while (t--)
    {
        int n,m;
        cin>>n>>m;
        vector <int> adj[n+1];
        adjacent_edge(adj,m);
		int q;
		cin>>q;
		while(q--){
			int visited[n+1];
	        for(int i=1; i<=n; ++i){
	            visited[i] = 0;
	        }	
			int start, vertex;
			cin>>start>>vertex;
			DFS(start,adj,visited);
			cout<< (visited[vertex] ? "YES\n" : "NO\n");
		}
    }
    
   // system("pause");
}

