#include<iostream>
#include<map>

using namespace std;

main(){
	int t;
	cin>>t;
	while(t--){
		int n;
		cin>>n;
		int a[n];
		bool flag=false;
		map <int,int> mp;
		for(int i=0; i<n; ++i){
			cin>>a[i];
			mp[a[i]]++;
		}
		for(int i=0; i<n; ++i){
			if(mp[a[i]] != 1){
				cout<<a[i]<<endl;
				flag=true;
				break;
			}
		}
		if(!flag) cout<<"NO\n";
	}
}
