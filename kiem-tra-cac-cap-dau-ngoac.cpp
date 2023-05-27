#include<iostream>
#include<stack>
#include<string>

using namespace std;

bool check(string s ){
	stack <char> stk;
	for(int i=0; i<s.size(); ++i){
		if(s[0]==')' || s[0] == ']' || s[0] == '}') return false;
		else{
			if(s[i] =='(' || s[i] == '[' || s[i] == '{' ){
				stk.push(s[i]);
			}
			else{
				char c = stk.top();
				if(s[i]==')' && c=='(' ) stk.pop();
				else if( s[i] == ']' && c == '[') stk.pop();
				else if( s[i] == '}' && c == '{') stk.pop();
				else if(s[i] == ')' && (c == '[' || c == '{') ) return false;
				else if( s[i] == ']' && (c == '(' || c == '{')) return false;
				else if( s[i] == '}' && ( c == '('|| c == '[')) return false;
			}
		}
	}
	if(stk.empty()) return true;
	return false;
}

main(){
	int t;
	cin>>t;
	while(t--){
		string s;
		cin>>s;
		if(check(s)) cout<<"true\n";
		else cout<<"false\n";
	}
}
