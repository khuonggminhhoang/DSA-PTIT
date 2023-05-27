#include<iostream>
#include<set>
#include<algorithm>

using namespace std;

main(){
	int t;
	cin>>t;
	while(t--){
		int n, m;
		cin>>n>>m;
		int a[n], b[m];
		set<int> st;
		for(int i=0; i<n; ++i){
			cin>>a[i];
			st.insert(a[i]);
		}
		
		for(int i=0; i<m; ++i){
			cin>>b[i];
			st.insert(b[i]);
		}
		
		for( auto x : st) cout<<x <<" ";
		cout<<endl;
		
		sort(a,a+n);
		for(int i=0; i<m; ++i){
			if( binary_search(a,a+n,b[i])) cout<<b[i]<<" ";
		}
		cout<<endl;
	}
}
