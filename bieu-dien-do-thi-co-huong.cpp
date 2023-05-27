#include<iostream>
#include<vector>

using namespace std;

main(){
	int t;
	cin>>t;
	while(t--){
		int n,m;
		cin>>n>>m;
		vector <int> adj[n+1];
		for(int i=1; i<= m; ++i){
			int x,y;
			cin>>x>>y;
			adj[x].push_back(y);
		}
		
		//in ra man
		for(int i=1; i<=n; ++i){
			cout<< i << ": ";
			for( vector <int> :: iterator it=adj[i].begin(); it != adj[i].end(); ++it){
				cout<<*it<<" ";
			}
			cout<<endl;
		}
		
	}
}
