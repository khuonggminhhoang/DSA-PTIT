#include<iostream>
#include<stack>
#include<string>

using namespace std;

main(){
	int t;
	cin>>t;
	while(t--){
		string s;
		cin>>s;
		stack <char> stk;
		bool ok = true ;
		for(int i=0; i<s.size(); ++i){
			if( s[i] == '(' || s[i] == '[' || s[i] == '{'){
				stk.push(s[i]);
			}
			else if( s[i] == ')'){
				if(stk.size() == 0){
					ok = false;
					break;
				}
				else{
					if(stk.top() == '(') stk.pop();
				}
			}
			else if( s[i] == ']'){
				if(stk.size() == 0){
					ok = false;
					break;
				}
				else{
					if(stk.top() == '[') stk.pop();
				}
			}
			else if( s[i] == '}'){
				if(stk.size() == 0){
					ok = false;
					break;
				}
				else{
					if(stk.top() == '{') stk.pop();
				}
			}
		}
		if(stk.size() != 0 ) ok = false;
		if(ok) cout<<"YES\n";
		else cout<<"NO\n";
	}
}

