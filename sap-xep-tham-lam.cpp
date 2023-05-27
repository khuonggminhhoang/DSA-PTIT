#include<iostream>
#include<algorithm>

using namespace std;

main(){
	int t;
	cin>>t;
	while(t--){
		int n;
		cin>>n;
		int a[n];
		for( auto &x : a) cin>>x;
		int b[n];
		for(int i=0; i<n; ++i) b[i]=a[i];
		sort(b,b+n);
		bool flag=true;
		for(int i=0; i<=n/2; ++i){
			if(a[i] + a[n-i-1] != b[i] + b[n-i-1]){
				flag=false;
				break;
			}
		}
		if(flag) cout<<"Yes\n";
		else cout<<"No\n";
		
	}
}
