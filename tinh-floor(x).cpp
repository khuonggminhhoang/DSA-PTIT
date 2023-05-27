#include<iostream>

using namespace std;

int Search(int a[], int n, int k){
	int res=-2;
	int l=0,r=n-1, m;
	while(l<=r){
		m=(l+r)/2;
		if(k < a[m]){
			r=m-1;
		}
		else{
			l=m+1;
			res=m;
		}
	}
	return res;
}

main(){
	int t;
	cin>>t;
	while(t--){
		int n, k;
		cin>>n>>k;
		int a[n];
		for(auto &x : a) cin>>x;
		cout<<Search(a,n,k)+1<<endl;
	}
}
