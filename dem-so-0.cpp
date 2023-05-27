#include<iostream>

using namespace std;

int Search(int a[], int n){
	int l=0,r=n-1,m;
	int res=0;
	while(l<=r){
		m=(l+r)/2;
		if(a[m] == 0){
			l=m+1;
			res=m;
		}	
		else{
			r=m-1;
		}
	}
	return res;
}

main(){
	int t;
	cin>>t;
	while(t--){
		int n;
		cin>>n;
		int a[n];
		for(auto &x : a) cin>>x;
		int ans = Search(a,n);
		if(ans==0) cout<<0<<endl;
		else cout<<ans+1<<endl;
	}
}
