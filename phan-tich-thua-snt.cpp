#include<iostream>
#include<cmath>

using namespace std;

const int maxn=1000;
int prime[maxn+1];

void sang(){
	for(int i=0; i<=maxn; ++i){
		prime[i]=i;
	}
	
	for(int i=2; i<=sqrt(maxn); ++i){
		if(prime[i]==i){
			for(int j=i*i; j<=maxn; j+=i){
				if(prime[j]==j){
					prime[j]=i;
				}
			}
		}
	}
}

void pt(int n){
	while(n!=1){
		cout<<prime[n]<<" ";
		n/=prime[n];
	}
}

main(){
	int n;
	cin>>n;
	sang();
	pt(n);
}
