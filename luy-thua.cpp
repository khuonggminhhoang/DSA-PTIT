#include<iostream>

using namespace std;

const int mod = 1e9 + 7;
long long res;
long long power(long long n,long long k){
	if( k==0 ) return 1;
	long long r = power(n,k/2)%mod;
	if( k%2==0 ) {
		return ((r%mod) * (r%mod))%mod;
	}
	else {
		return ((r*r)%mod * n%mod)%mod;
	}
}

main(){
	int t;
	cin>>t;
	while(t--){
		long long n,k;
		cin>>n>>k;
		long long res = power(n,k);
		cout<<res<<endl;
	}
}
