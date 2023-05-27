#include<iostream>
#include<algorithm>
#include<set>
using namespace std;

main(){
	int c,n;
	cin>>c>>n;
	set <int> st;
	int a[n];
	for( auto &x : a){
		cin>>x;
	}
	sort(a,a+n);
	int dp[c+1]={0};
	dp[0]=1;
	for(int i=0; i<n; ++i){
		int m=c;
		while( m>=a[i] ){
			if( dp[m-a[i]]) {
				dp[m]=1;
				st.insert(m); 
			}
			--m;
		}
	}
	int cnt=0;
	for(auto x : st) {
		++cnt;
		if(cnt==st.size()) cout<<x<<endl;
	}
	
}
