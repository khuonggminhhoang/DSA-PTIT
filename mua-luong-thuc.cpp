#include<iostream>

using namespace std;

int greedy(int n, int s, int m){
	if(n<m) return -1;
		if(s >=7 )
			if(6*n < 7*m) return -1;
				if((double) s*m/n == s*m/n) return s*m/n;
				return s*m/n+1;	
}

main(){
	int t;
	cin>>t;
	while(t--){
		int n,s,m;
		cin>>n>>s>>m;
		cout<<greedy(n,s,m)<<endl;
	}
}
