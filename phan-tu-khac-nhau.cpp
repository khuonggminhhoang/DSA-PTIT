#include<iostream>

using namespace std;

int Search_element_dif(int a[], int b[], int n){
	int l=0 , r=n-1, m;
	int res=0;
	while(l<=r){
		m=(l+r)/2;
		if(a[m]==b[m]) {
			l=m+1;
		}
		else{
			r=m-1;
			res=m;
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
		int a[n], b[n-1];
		for(auto &x : a) cin>>x;
		for(auto &y : b) cin>>y;
		cout<<Search_element_dif(a,b,n)+1<<endl;
	}
}
