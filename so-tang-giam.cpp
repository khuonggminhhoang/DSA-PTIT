#include<iostream>
#include<string>

using namespace std;

main(){
	int t;
	cin>>t;
	while(t--){
		string s;
		cin>>s;
		bool flag1=true, flag2=true;
		for(int i=0; i<s.size()-1; ++i) 
			if(s[i] > s[i+1]){
				flag1=false;
				break;
			}
			
		for(int j=0; j<s.size()-1; ++j) 
			if(s[j] < s[j+1]){
				flag2=false;
				break;
			}
			
		if(flag1==true || flag2==true) cout<<"YES\n";
		else cout<<"NO\n";
	}
}
