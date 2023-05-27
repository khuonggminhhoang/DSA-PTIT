#include<iostream>
#include<stack>
#include<algorithm>

using namespace std;

int priority(char c){
	if( c == '(' || c == ')') return 0;
	if( c == '-' || c == '+') return 1;
	if( c == '*' || c == '/') return 2;
	if( c == '^') return 3;
	return -1;
}

string PreToIndict(string s){
	reverse(s.begin(),s.end());
	stack <string> stk;
	for(int i=0; i<s.size(); ++i){
		if(isalpha(s[i])){
			stk.push(string(1,s[i]));    //ep kieu string sang char
		}
		else{
			string s1 = stk.top(); stk.pop();
			string s2 = stk.top(); stk.pop();
			string tmp = '(' + s1 + s[i] + s2 + ')';
			stk.push(tmp);
		}
	}
	return stk.top();
}

string IndictToPre(string s){
	stack <char> stk;
	string res = "";
	for(int i=0; i<s.size(); ++i){
		if(s[i] == '(') stk.push('(');
		else if( isalpha(s[i]) ){
			res+=s[i];
		}
		else if(s[i] == ')'){
			char top = stk.top(); stk.pop();
			while(top != '('){
				res+=top;
				top = stk.top();
				stk.pop();
			}
		}
		else if(!stk.empty()){
			while(priority(s[i]) <= priority(stk.top()) ){
				res+=stk.top();
				stk.pop();
				if(stk.empty()) break;
			}
			stk.push(s[i]);
		}
		else stk.push(s[i]);
	}
	while(!stk.empty()){
		res += stk.top();
		stk.pop();
	}
	return res;
}

main(){
	int t;
	cin>>t;
	while(t--){
		string s;
		cin>>s;
		string st = PreToIndict(s);
		cout<<IndictToPre(st)<<endl;
	}
}

