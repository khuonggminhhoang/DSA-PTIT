#include<iostream>
#include<stack>
#include<cmath>
#include<string>
#include<algorithm>

using namespace std;

main(){
	int t;
	cin>>t;
	while(t--){
		string s;
		cin>>s;
		reverse(s.begin(), s.end());
		stack <int> stk;
		for(int i=0; i<s.size(); ++i ){
			if(isdigit(s[i])){
				int num = s[i] - '0';
				stk.push(num);
			}
			else{
				int top1 = stk.top(); stk.pop();
				int top2 = stk.top(); stk.pop();
				if(s[i] == '+') top1+=top2;
				if(s[i] == '-') top1-=top2;
				if(s[i] == '*') top1*=top2;
				if(s[i] == '/') top1/=top2;
				if(s[i] == '^') top1 = pow(top1, top2);
				stk.push(top1);
			}
		}
		cout<<stk.top()<<endl;
	}
}
