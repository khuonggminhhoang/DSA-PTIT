#include<iostream>

using namespace std;

main(){
	int t;
	cin>>t;
	while(t--){
		long long f[93];
		f[1] = f[2] = 1;
		for(int i=3; i<=92; ++i) f[i]=f[i-2] + f[i-1];
		
		long long n,k;
		cin>>n>>k;
		
		while(f[n] != 1){
			if(k > f[n-2]){
				k-=f[n-2];
				--n;
			}
			else n-=2;
		}
		if(n==2) cout<<1<<endl;
		else cout<<0<<endl;
	}
}
