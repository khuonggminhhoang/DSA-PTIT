#include<iostream>
#include<map>

using namespace std;

main(){
	int t;
	cin>>t;
	while(t--){
		int d;
		cin>>d;
		string s;
		cin>>s;
		map <char, int> mp;
		for(auto x : s){
			mp[x]++;
		}
		int max_ = 0;
		for(auto x : mp) max_=max(max_,x.second);
		int b=max_;
		d--;
		max_--;
		max_*=d;
		max_+=b;
		if(max_ > s.size()) cout<<-1<<endl;
		else cout<<1<<endl;
	}
}
