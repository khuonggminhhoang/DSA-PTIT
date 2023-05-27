#include<iostream>

using namespace std;

main(){
	int t;
	cin>>t;
	while(t--){
		int n; cin>>n;
		int a[n];
		for(int i=0; i<n; ++i) cin>>a[i];
		int l=0, r=n-1;
		bool flag=true;
		while(l<r){
			if(a[l] == a[r]) {
				l++;
				r--;
			}
			else {
				flag=false;
				break;
			}
		}
		if(flag) cout<<"YES"<<endl;
		else cout<<"NO"<<endl;
	}
}
