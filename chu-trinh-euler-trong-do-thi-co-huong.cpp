#include<iostream>
#include<vector>

using namespace std;

vector <int> adj[1001], uadj[1001];
int n,m;

void adj_edge(){
	while(m--){
		int x,y;
		cin>>x>>y;
		adj[x].push_back(y);
		uadj[y].push_back(x);
	}
}

bool check(){
	for(int i=1; i<=n; ++i){
		if(adj[i].size() != uadj[i].size()) return false;
	}
	return true;
}

main(){
	int t;
	cin>>t;
	while(t--){
		cin>>n>>m;
		adj_edge();
		cout<<check()<<endl;
		
		for(int i=1; i<=n; ++i) {
			adj[i].clear();
			uadj[i].clear();
		}
	}
}
