#include<iostream>
#include<stack>
#include<cmath>

using namespace std;

long long so(string s){
	long long res=0;
	if( s[0] == '-'){
		for(int i=1; i<s.size(); ++i){
			res = 10 * res + (s[i] - '0');
		}
		return -1*res;
	}
	else{
		for(int i=0; i<s.size(); ++i){
			res = 10 * res + (s[i] - '0');
		}
		return res;
	}
}

main(){
	int t;
	cin>>t;
	while(t--){
		int n;
		cin>>n;
		stack <long long> stk;
		while(n--){
			string x;
			cin>>x;
			if(x.size() == 1){
				if(isdigit(x[0])) stk.push(so(x));
				else{
					long long s1=stk.top(); stk.pop();
					long long s2 = stk.top(); stk.pop();
					if(x == "+") stk.push(s2+s1);
					else if( x == "-") stk.push((s2-s1));
					else if(x == "*") stk.push(s2*s1);
					else if( x == "/") stk.push(s2/s1);
					else if( x == "^") stk.push(pow(s2,s1));
				}
			}
			else{
				stk.push(so(x));
			}	
		}
		cout<<stk.top()<<endl;
	}
}
