#include<iostream>
#include<set>
#include<vector>

using namespace std;

main(){
	int t;
	cin>>t;
	while(t--){
		int m,n,k;
		cin>>m>>n>>k;
		multiset <int> st;
		int x=m+n;
		while(x--){
			int y;
			cin>>y;
			st.insert(y);
		}
		vector <int> v;
		for(auto x : st){
			v.push_back(x);
		}
		cout<<v[k-1]<<endl;
	}
}
