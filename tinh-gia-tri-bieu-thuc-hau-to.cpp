#include<iostream>
#include<stack>
#include<cmath>
using namespace std;

main(){
	int t;
	cin>>t;
	while(t--){
		string s;
		cin>>s;
		stack <int> stk;
		for(int i=0; i<s.size(); ++i){
			if(isdigit(s[i])){
				int num = s[i] - '0';
				stk.push(num);
			}
			else {
				int top1 = stk.top();
				stk.pop();
				int top2 = stk.top();
				stk.pop();
				if(s[i] == '+') top2+=top1;
				if(s[i] == '-') top2-=top1;
				if(s[i] == '*') top2*=top1;
				if(s[i] == '/') top2/=top1;
				if(s[i] == '^') top2 = pow(top2, top1);
				stk.push(top2);
			}
		}
		cout<<stk.top()<<endl;
	}
}
