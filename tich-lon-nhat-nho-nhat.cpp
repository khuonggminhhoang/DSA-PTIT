#include<iostream>
#include<algorithm>

using namespace std;

main(){
	int t;
	cin>>t;
	while(t--){
		int n,m;
		cin>>n>>m;
		long long a[n], b[m];
		for(int i=0; i<n; ++i) cin>>a[i];
		for(int j=0; j<m; ++j) cin>>b[j];
		
		sort(a,a+n);
		sort(b,b+m);
		long long res=a[n-1] * b[0];
		cout<<res<<endl;
	}
}
