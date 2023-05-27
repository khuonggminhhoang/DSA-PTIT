#include<iostream>
#include<set>
#include<algorithm>

using namespace std;

bool sequentialSearch(int a[], int n, int x){
	for(int i=0; i<n;++i)
		if(x == a[i]) return true;
	return false;
}

main(){
	int t;
	cin>>t;
	while(t--){
		int n,m;
		set<int> st;
		cin>>n>>m;
		int a[n], b[m];
		for(int i=0; i<n; ++i){
		 	cin>>a[i];
		 	st.insert(a[i]);
		}
		for(int j=0; j<m; ++j) {
			cin>>b[j];
			st.insert(b[j]);
		}
		
	
		for( set <int> :: iterator it=st.begin(); it!= st.end(); ++it)
			cout<<*it<<" ";
		cout<<endl;
		
		for(int i=0; i<n; ++i){
			if( sequentialSearch(b,m,a[i])) cout<<a[i]<<" ";
		}
		cout<<endl;
	}
}
