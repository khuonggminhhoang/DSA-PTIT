#include<iostream>

using namespace std;

const int mod = 123456789;

long long PawMod(long long n, long long k){
	if(k==0) return 1;
	long long r= PawMod(n,k/2)%mod;
	if(k%2==0)
		return (r%mod * r%mod) %mod;
	else 
		return (r*r)%mod * n%mod; 
}

main(){
	int t;
	cin>>t;
	while(t--){
		long long n;
		cin>>n;
		cout<<PawMod(2,n-1)<<endl;
	}
}
