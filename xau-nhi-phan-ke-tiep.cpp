#include<iostream>

using namespace std;

void sinh(string s){
	int pos=0;
	for(int i=s.size()-1; i>=0; --i)
		if(s[i]=='0'){
			pos=i;
			break;
		}
	for(int i=pos; i<s.size(); ++i)
		if(s[i]=='0') s[i]='1';
		else s[i]='0';
	cout<<s<<endl;
}

main(){
	int t;
	cin>>t;
	while(t--){
		string s;
		cin>>s;
		sinh(s);
	}
}
