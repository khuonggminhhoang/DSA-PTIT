#include<iostream>
#include<stack>
#include<vector>
#include<cstring>
#include<algorithm>

using namespace std;

bool visited[1001];
vector <int> adj[1001];
int n,m;

void adj_edge(){
	while(m--){
		int x, y;
		cin>>x>>y;
		adj[x].push_back(y);
		adj[y].push_back(x);
	}	
}

int check(){
	int cnt_le=0, cnt_chan=0;
	for(int i=1; i<=n; ++i){
		if(adj[i].size()%2) cnt_le++;
		else cnt_chan++;
	}
	if(cnt_chan == n) return 2;
	if(cnt_le == 2) return 1;
	return 0;
}

main(){
	int t;
	cin>>t;
	while(t--){
		cin>>n>>m;
		adj_edge();
		cout<<check()<<endl;
		memset(visited, false, sizeof(visited));
		for(int i=1; i<=n; ++i) adj[i].clear();
	}
}
