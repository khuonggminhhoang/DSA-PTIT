#include<iostream>
#include<algorithm>

using namespace std;

main(){
	int t;
	cin>>t;
	while(t--){
		int n;
		cin>>n;
		long long a[n],b[n];
		for(auto &x : a) cin>>x;
		for(auto &x : b) cin>>x;
		sort(a,a+n);
		sort(b,b+n, greater <long long>());
		long long res=0;
		for(int i=0; i<n; ++i) res+=a[i]*b[i];
		cout<<res<<endl;
	}
}
