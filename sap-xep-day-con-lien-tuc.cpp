#include<iostream>
#include<set>
#include<vector>

using namespace std;

main(){
	int t;
	cin>>t;
	while(t--){
		int n;
		cin>>n;
		int a[n];
		multiset <int> mul;
		for(int i=0; i<n; ++i){
			cin>>a[i];
			mul.insert(a[i]);
		}
		vector <int> v;
		for( auto x : mul) v.push_back(x);
		int l,r;
		for(int i=0; i<n; ++i){
			if(a[i] != v[i]){
				l=i+1;
				break;
			}
		}
		for(int i=n-1; i>=0; --i){
			if(a[i] != v[i]) {
				r=i+1;
				break;
			}
		}
		cout<<l<<" "<<r<<endl;
	}
}
