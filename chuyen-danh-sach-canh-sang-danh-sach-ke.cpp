#include<iostream>
#include<vector>

using namespace std;


main(){
	int t;
	cin>>t;
	while(t--){
		int n,m;
		cin>>n>>m;
		vector <int> adj[1000];
		for(int i=1; i<= m; ++i){
			int x,y;
			cin>>x>>y;
			adj[x].push_back(y);
			adj[y].push_back(x);
		}
		//in ra man hinh
		for(int i=1; i<=n; ++i){
			cout<<i<<": ";
			for(auto v : adj[i])
				cout<<v<<" ";
			cout<<endl;
		}
	}
}
