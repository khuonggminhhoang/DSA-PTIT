#include<iostream>
#include<vector>

using namespace std;

main(){
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	
	int n;
	cin>>n;
	int a[n+1][n+1];
	for( int i=1; i<=n; ++i)
		for(int j=1; j<=n; ++j)
			cin>>a[i][j];
			
	vector <int> ke[n+1];
	for( int i=1; i<=n; ++i){
		for(int j=1; j<=n; ++j)
			if(a[i][j]){
				ke[i].push_back(j);
			//	ke[j].push_back(i);
			}
	}
	
	for(int i=1; i<=n; ++i){
		for(auto x: ke[i]) cout<<x<<" ";
		cout<<endl;
	}
}
