#include<iostream>
#include<string>

using namespace std;

main(){
	int t,n;
	string s;
	cin>>t;
	while(t--){
		cin>>n;
		s=to_string(n); cout<<s<<endl;
		if(s[0] == s[s.size()-1]) cout<<"YES\n";
		else cout<<"NO\n";
	}
}
