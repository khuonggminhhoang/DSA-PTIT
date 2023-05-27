#include<iostream>
#include<string>
#include<vector>

using namespace std;

main(){
	string s;
	vector <int> v;
	getline(cin,s);
	for(int i=0; i<s.size(); ++i)
		if(isdigit(s[i])) v.push_back(s[i]-'0');
	if(v[0] + v[1] == v[2]) cout<<"YES\n";
	else cout<<"NO\n";
	
}
