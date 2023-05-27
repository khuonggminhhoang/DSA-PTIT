#include<iostream>
#include<map>

using namespace std;

main(){
	int t;
	cin>>t;
	while(t--){
		int n,k;
		cin>>n>>k;
		int a[n];
		map <int,int> mp;
		for(auto &x : a){
			cin>>x;
			mp[x]++;
		}
		int count=0;
		for(int i=0; i<n; ++i){
			count += mp[k-a[i]];
			if(2*a[i] == k) --count;
		}
		cout<<count/2<<endl;
	}
}
