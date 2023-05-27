#include<iostream>
#include<algorithm>
#include<vector>
#include<set>

using namespace std;

struct Char{
	char c;
	int times;
};

bool cmp( Char a, Char b){
	return a.times < b.times;
}

main(){
	int t;
	cin>>t;
	while(t--){
		string s;
		cin>>s;
		vector <Char> v;
		set <char> st;
		for(int i=0; i<s.size(); ++i){
			st.insert(s[i]);
		}
		for( auto x : st){
			int cnt=0;
			for(auto y : s){
				if(x==y) ++cnt;
			}
			Char r = {x,cnt};
			v.push_back(r);
		}
		sort(v.begin(), v.end(), cmp);
		if(s.size() - v[v.size()-1].times >= v[v.size()-1].times-1) cout<<1<<endl;
		else cout<<-1<<endl;
	}
}
