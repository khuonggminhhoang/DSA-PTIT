#include<iostream>
#include<map>
#include<algorithm>

using namespace std;

main(){
	int t;
	cin>>t;
	while(t--){
		int n;
		cin>>n;
		map <int, int> mp;
		int max_=0, m=n;
		while(n--){
			int x;
			cin>>x;
			mp[x]++;
			max_ = max(max_, mp[x]);
		}
		if(max_ > m/2) {
			for(auto x : mp){
				if(x.second == max_) cout<<x.first;
			}
		}
		else cout<<"NO";
		cout<<endl;
	}
}
