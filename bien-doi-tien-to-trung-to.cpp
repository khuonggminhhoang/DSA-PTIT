#include<bits/stdc++.h>

using namespace std;

main(){
	int t;
	cin>>t;
	while(t--){
		string s;
		cin>>s;
		reverse(s.begin(), s.end());
		stack <string> stk;
		for(int i=0; i<s.size(); ++i){
			if(isalpha(s[i]) ){
				string x ="";
				x+=s[i];
				stk.push(x);
			}
			else{
				string s1 = stk.top(); stk.pop();
				string s2 = stk.top(); stk.pop();
				string tmp ="(" + s1 + s[i] + s2 + ")";
				stk.push(tmp);
			}
		}
		cout<<stk.top()<<endl;
	}
}
