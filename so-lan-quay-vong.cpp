#include<iostream>

using namespace std;

main(){
	int t;
	cin>>t;
	while(t--){
		int n;
		cin>>n;
		long long a[n];
		bool ok=false;
		for(auto &x : a) cin>>x;
		for(int i=1; i<n; ++i){
			if(a[i-1] > a[i]){
				cout<<i<<endl;
				ok=true;
				break;
			}
		}
		if(!ok) cout<<0<<endl;
	}
}
