#include<iostream>
#include<algorithm>
using namespace std;
const int mod=1e9+7;
main(){
	int t;
	cin>>t;
	while(t--){
		int n;
		cin>>n;
		int a[n];
		for(auto &x : a) cin>>x;
		sort(a,a+n);
		long long sum=0;
		for(int i=n-1; i>0; --i){
			sum= (sum%mod + (a[i]*i)%mod) %mod;
		}
		cout<<sum<<endl;
	}
}
