#include<iostream>
#include<algorithm>
#include<set>

using namespace std;

main(){
	int t;
	cin>>t;
	while(t--){
		int n;
		cin>>n;
		long long a[n];
		string s;
		set <char> st;
		for(int i=0; i<n; ++i) cin>>a[i];
		for(int i=0; i<n; ++i){
			s=to_string(a[i]);
			for( int j=0; j<s.size(); ++j){
				st.insert(s[j]);
			}
		}
		for( char x : st){
			cout<<x<<" ";
		}
		cout<<endl;
	}
}
