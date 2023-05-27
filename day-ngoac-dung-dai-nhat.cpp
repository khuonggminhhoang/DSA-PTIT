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
		stack <int> stk;
		int longest=0;
		stk.push(-1);
		for( int i=0; i<s.size(); ++i){
			if(s[i]=='(') stk.push(i);
			else{
				stk.pop();
				if(!stk.empty()){
					longest= max(longest, i- stk.top());
				}
				else
					stk.push(i);
			}
		}
		cout<<longest<<endl;
	}
}
