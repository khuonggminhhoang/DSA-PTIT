#include<iostream>
#include<queue>
#include<algorithm>

using namespace std;

long long a[20];
long long count_BDN(string s){
	long long cnt = 0;
	int pos = 0;
	for(pos = 0; pos <s.size(); ++pos){
		if(s[pos] > '1') break;
	}
	for(int i= pos ; i<s.size(); ++i){
		s[i] = '1';
	}
	reverse(s.begin(), s.end());
	for(int i=0; i<s.size(); ++i){
		if(s[i] == '1') cnt += a[i];
	}
	return cnt;
}

main(){
	a[0]=1;
	for(int i=1; i<=20; ++i){
		a[i] = a[i-1]*2;
	}
	int t;
	cin>>t;
	while(t--){
		string s;
		cin>>s;
		cout<<count_BDN(s)<<endl;
	}
}
