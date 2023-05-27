#include<iostream>
#include<string>
#include<algorithm>
using namespace std;

bool flag;

void solve(string s){
	for(int i=0; i<s.size()-1; ++i)
		if(s[i]<s[i+1]) flag=true;
	if(flag){
		int pos;
		for(pos=s.size()-2; pos>=0; --pos ){
			if( s[pos+1] > s[pos] ) {
				break;
			}
		}
		int i=pos+1;
		while( i<s.size() && s[i] > s[pos]) ++i;
		swap(s[pos], s[i-1]);
		reverse(s.begin()+pos+1, s.end());
		cout<<s<<endl;
	}
	else cout<<"BIGGEST"<<endl;
}

main(){
	int t;
	cin>>t;
	while(t--){
		int x;
		string s;
		cin>>x>>s;
		flag=false;
		cout<<x<<" ";
		solve(s);
	}
}


