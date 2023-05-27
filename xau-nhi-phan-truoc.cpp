#include<iostream>
#include<string>

using namespace std;

string s;
int t;

void sinh(){
	int pos;
	for(int i=s.size()-1; i>=0; --i ){
		if(s[i]=='1') {
			pos=i;
			break;
		}
	}
	
	for(int i=pos; i<s.size(); ++i){
		s[i] = (s[i]=='1') ? '0':'1';
	}
}

main(){
	cin>>t;
	while(t--){
		cin>>s;
		sinh();
		cout<<s<<endl;
	}
}
