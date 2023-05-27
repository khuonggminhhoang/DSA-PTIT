#include<iostream>
#include<algorithm>

using namespace std;

main(){
	int t;
	cin>>t;
	while(t--){
		int n,k;
		cin>>n>>k;
		int a[n];
		int sum=0;
		for(auto &x : a ) {
			cin>>x;
			sum+=x;
		}
		sort(a,a+n);
		int m=min(k,n-k);
		int Sum=0;
		for(int i=0; i<m; ++i) Sum+=a[i];
		cout<<sum-2*Sum<<endl;
	}
}
