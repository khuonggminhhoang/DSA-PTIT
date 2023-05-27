#include<iostream>

using namespace std;

main(){
	int t;
	cin>>t;
	while(t--){
		int n;
		cin>>n;
		int L[n], a[n];
		for(auto &x : a) cin>>x;
		for(int i=0; i<n; ++i) L[i]=1;
		for(int i=1; i<n; ++i){
			for(int j=0; j<i; ++j){
				if(a[i]>=a[j]) {
					L[i]= max(L[i], L[j]+1);
				}
			}
		}
		
		int max_ = 0;
		for(int i=0; i<n; ++i)
			max_ = max(max_,L[i]);
		cout<<n-max_<<endl;
	}
}
