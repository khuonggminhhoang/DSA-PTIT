#include<iostream>
#include<stack>

using namespace std;

main(){
	int t;
	cin>>t;
	while(t--){
		string s;
		cin>>s;
		stack <char> stk;
		int ans=0;				
		
		for(int i=0; i<s.size(); ++i){
			if(s[i] == '(') stk.push('(');
			else{
				if(!stk.empty()){
					stk.pop();
				}
				else{
					stk.push(')');
					ans++; 
				}
			}
		}
		cout<<stk.size()/2 + ans<<endl;
	}
}
