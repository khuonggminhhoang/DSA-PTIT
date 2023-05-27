#include<iostream>
#include<stack>

using namespace std;

int priority(char c){
	if( c == '(' || c == ')') return 0;
	if( c == '+' || c == '-') return 1;
	if( c == '*' || c == '/') return 2;
	if( c == '^') return 3;
	return -1;
}

main(){
	int t;
	cin>>t;
	while(t--){
		string s;
		cin>>s;
		stack <char> stk;
		for(int i=0; i<s.size(); ++i){
			if(s[i] == '(') stk.push('(');
			else if( (s[i] >= 'A' && s[i] <= 'Z') || (s[i] >='a' && s[i] <= 'z')){
				cout<<s[i];
			}
			else if(s[i] == ')'){
				char top = stk.top(); stk.pop();
				while(top != '('){
					cout<<top;
					top = stk.top();
					stk.pop();
				}
			}
			else if(!stk.empty()){
				while(priority(s[i]) <= priority(stk.top())){//
					cout<<stk.top();
					stk.pop();
					if(stk.empty()) break;
				}
				stk.push(s[i]);
			}
			else stk.push(s[i]);
		}
		while(!stk.empty()){
			cout<<stk.top();
			stk.pop();
		}
		cout<<endl;
	}
	
}




