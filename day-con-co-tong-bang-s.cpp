#include<iostream>

using namespace std;

main(){
	int t;
	cin>>t;
	while(t--){
		int n, s;
		cin>>n>>s;
		int a[n];
		for( auto &x : a) cin>>x;
		int dp[s+1]={0};
		dp[0]=1;
		
		for(int i=0; i<n; ++i){
			int m=s;
			while( m>=a[i]){
				if( dp[m-a[i]] ) dp[m]=1;
				--m;
			}
		}
		
		if(dp[s]) cout<<"YES\n";
		else cout<<"NO\n";
	}
}
