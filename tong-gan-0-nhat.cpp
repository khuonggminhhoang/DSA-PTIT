#include<iostream>
#include<cmath>

using namespace std;

main(){
	int t;
	cin>>t;
	while(t--){
		int n;
		cin>>n;
		int a[n];
		for(int i=0; i<n; ++i) cin>>a[i];
		int min=1e9, res;
		for(int i=0; i<n-1; ++i)
			for(int j=i+1; j<n; ++j){
				if( abs(a[i] + a[j]) < min ){
					min= abs(a[i] + a[j]);
					res= a[i] + a[j];
				}
			}
		cout<<res<<endl;
	}
}
