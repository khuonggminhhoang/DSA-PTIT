#include<iostream>
#include<algorithm>

using namespace std;

main(){
	int t;
	cin>>t;
	while(t--){
		int n;
		int k;
		cin>>n>>k;
		long long a[n];
		for(auto &x : a) cin>>x;
		sort(a,a+n);
		long long res=0;
		for(int i=0; i<n-2; ++i){
			long long l=i+1, r=n-1;
			while(l < r){
				if(a[i] + a[l] + a[r] < k){
					res+= r-l;
					l++;
				}
				else r--;
			}
		}
		cout<<res<<endl;
	}
}
