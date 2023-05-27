#include<iostream>
#include<string>

using namespace std;

int transNumber(string s){
	int num=0;
	for(int  i=0; i<s.size(); ++i){
		num = 10*num + (s[i]-'0');
	}
	return num;
}

main(){
	string a,b;
	cin>>a>>b;
	for(int i=0; i<a.size(); ++i ) if(a[i]=='6') a[i]='5';
	for(int i=0; i<b.size(); ++i ) if(b[i]=='6') b[i]='5';
	cout<<transNumber(a)+transNumber(b)<<" ";
	for(int i=0; i<a.size(); ++i ) if(a[i]=='5') a[i]='6';
	for(int i=0; i<b.size(); ++i ) if(b[i]=='5') b[i]='6';
	cout<<transNumber(a)+transNumber(b)<<endl;
	
}
