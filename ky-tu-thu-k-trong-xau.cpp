#include<iostream>

using namespace std;

long long Mul(int k){
	if(k==0) return 1;
	long long p = Mul(k/2);
	if(k%2) return 2*p*p;
	return p*p;
}

char Search(int n, int k){
	long long mid = Mul(n-1);
	while(k!=mid){
		if(k > mid){
			k= mid - (k-mid);
		}
		--n;
		mid/=2;
	} 
	return '@' +  n;
}

main(){
	int t;
	cin>>t;
	while(t--){
		int n,k;
		cin>>n>>k;
		cout<<Search(n,k)<<endl;
	}
}
