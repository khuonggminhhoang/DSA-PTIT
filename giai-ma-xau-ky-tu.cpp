#include<iostream>
#include<stack>
#include<algorithm>
#include<string>

using namespace std;

long long so(string s){
	long long num = 0;
	for(auto x : s){
		num = 10 * num + (x - '0');
	}
	return num;
}

main(){
	int t;
	cin>>t;
	while(t--){
		string s;
		cin>>s;
		int k=0;
		for(auto x : s){
			if(isdigit(x)) k++;
		}
		reverse(s.begin(), s.end());
		for(int i=0; i<s.size() ; ++i){
			if(s[i] == '[') s[i] = ']';
			else if(s[i]== ']') s[i] = '[';
		}
		stack <string> stk;
		for(int i=0 ; i<s.size() ; ++i){
			if(s[i] == '[') {
				stk.push(string(1,s[i]));
			}
			else if( s[i] == ']') {
				string res = "";
				string top;
				while( stk.top() != "["){
					string top = stk.top(); stk.pop();
					res += top;
				}
				stk.pop();
				stk.push(res);
			}
			else if(isdigit(s[i])){
				string ans="";
				while(isdigit(s[i])){
					ans += s[i];
					++i;
				}
				--i;
				reverse(ans.begin(), ans.end());
				long long num = so(ans);
				string top = stk.top();
				stk.pop();
				string res = "";
				while(num--){
					res += top;
				}
				stk.push(res);
			}
			else{
			 	stk.push(string(1,s[i]));
			}
		}	
		string ans="";
		while(!stk.empty()){
			ans += stk.top();
			stk.pop();
		}
		cout<<ans<<endl;
	}
}
