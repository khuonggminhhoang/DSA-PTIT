#include<iostream>

using namespace std;

long long Mul(long long n){
	if( n==0 ) return 1;
	long long  p = Mul(n/2);
	if(n%2) return 2*p*p;
	return p*p;
}

long long Search(long long n, long long k){
	long long len=Mul(n)/2;
	while(1){
		if(len == k){
			return n;
		}
		if(k>len){
			k= len - (k - len);
		}
		n--;
		len/=2;
	}
}

main(){
	int t;
	cin>>t;
	while(t--){
		long long n,k;
		cin>>n>>k;
		cout<<Search(n,k)<<endl;
	}
}
