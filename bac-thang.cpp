#include<iostream>

using namespace std;

const int mod= 1e9+7;

main(){
	int t;
	cin>>t;
	while(t--){
		int n,k;
		cin>>n>>k;
		long long sum=1;
		long long f[max(n,k)+2];
		f[1]=1;
		for(int i=2; i<=k; ++i){
			f[i]=(sum+1)%mod;
			sum+=f[i];
		}
		if( k<n){
			for(int i=k+1; i<=n; ++i){
				f[i]=sum%mod;
				sum+=(f[i]-f[i-k])%mod;
			}
		}
		cout<<f[n]<<endl;
	}
}
