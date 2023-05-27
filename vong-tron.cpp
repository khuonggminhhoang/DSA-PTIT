#include<iostream>

using namespace std;

int a[199],count=0;
string s;

void solve( int l, int r){
	for(int i=l+1; i<r; ++i){
		a[ s[i] ]++;
	}
	for(int i='A'; i<= 'Z'; ++i)
	{
		if(a[i]==1) count++;
		if(a[i] != 0) a[i]=0;
	}
}

main(){	
	cin>>s;
	for(int l=0; l<s.size()-1; ++l){
		for(int r=l+1; r<s.size(); ++r){
			if(s[l] == s[r]){
				solve(l,r);
				break;
			}
		}
	}
	cout<<count/2<<endl;
	
}

//ABCCBDEADEFFGGHHIIJJKKLLMMNNOOPPQQRRSSTTUUVVWWXXYYZZ
