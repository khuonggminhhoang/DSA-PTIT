//#include<iostream>
//#include<set>
//
//using namespace std;
//
//main(){
//	int t;
//	cin>>t;
//	while(t--){
//		int n,m;
//		cin>>n>>m;
//		multiset <int> st;
//		for(int i=0; i<n+m; ++i){
//			int x;
//			cin>>x;
//			st.insert(x);
//		}
//		
//		for( auto x: st)
//			cout<<x<<" ";
//		cout<<endl;
//		
//	}
//}

#include<iostream>
#include<algorithm>

using namespace std;

main(){
	int t;
	cin>>t;
	while(t--){
		int n,m;
		cin>>n>>m;
		int a[n], b[m];
		for( auto &x : a) cin>>x;
		for( auto &x : b) cin>>x;
		sort(a,a+n);
		sort(b,b+m);
		int i=0, j=0;
		while(i<n && j<m){
			if( a[i] <= b[j]){
				cout<<a[i]<<" ";
				++i;
			}
			else {
				cout<<b[j]<<" ";
				++j;
			}
		}
		
		while( i<n) {
			cout<<a[i]<<" ";
			++i;
		}
		
		while(j<m){
			cout<<b[j]<<" ";
			++j;
		}
		cout<<endl;
	}
}
