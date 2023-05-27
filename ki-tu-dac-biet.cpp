#include<iostream>
#include<string>

using namespace std;

void solve(string s, int n){
	while( n > s.size()){
		string res=s;
		res.insert(res.begin(),res[res.size()-1]);
		res.pop_back();
		s+=res;
	}
	cout<<s[n-1]<<endl;
}

main(){
	int t;
	cin>>t;
	while(t--){
		int n;
		string s;
		cin>>s>>n;
		solve(s,n);
	}
}
