#include<iostream>
#include<stack>

using namespace std;

main(){
	int t;
	cin>>t;
	while(t--){
		string s;
		cin>>s;
		stack <string> stk;
		for(auto x: s){
			if(isalpha(x)) stk.push( string(1,x));
			else{
				string s1 = stk.top(); stk.pop();
				string s2 = stk.top(); stk.pop();
				string tmp = x + s2 + s1;
				stk.push(tmp);
			}
		}
		cout<<stk.top()<<endl;
	}
}
