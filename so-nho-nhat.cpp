#include<iostream>
#include<stack>

using namespace std;

main(){
	int t;
	cin>>t;
	while(t--){
		int n,k;
		cin>>n>>k;
		stack <int> stk;
		if( (n==0 && k>1) || n>9*k ) cout<<-1<<endl;
		else if(n<9*k){
			while(n!=0){
				if(n > 9) {
					n-=9;
					stk.push(9);
					k--;
				}
				else{
					if( k > 1){
						stk.push(n-1);
						if(n!=1){
							n=1;
						}
						k--;
					}
					else{
						stk.push(n);
						n=0;
						k--;
					}
				}
			}
		}
		while(!stk.empty()){
			cout<<stk.top();
			stk.pop();
		}
		cout<<endl;
	}
}
