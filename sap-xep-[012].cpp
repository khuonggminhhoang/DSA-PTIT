#include<iostream>
#include<set>

using namespace std;

main(){
	int t;
	cin>>t;
	while(t--){
		int n;
		cin>>n;
		int a[n];
		multiset <int> muls;
		for(int i=0; i<n; ++i){
		 	cin>>a[i];
		 	muls.insert(a[i]);
		}
		for( int x : muls) cout<<x<<" ";
		cout<<endl;
	}
}
