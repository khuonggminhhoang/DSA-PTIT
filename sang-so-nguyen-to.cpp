#include<iostream>
#include<cmath>

using namespace std;

const int maxn=1000;

bool prime[maxn+1];

void sang(){
	for(int i=0; i<maxn; ++i){
		prime[i] = true;
	}
	prime[0] = prime[1] = false;
	for(int i=2; i<= sqrt(maxn); ++i){
		if(prime[i]){
			for(int j=i*i ; j <= maxn; j+=i){
				prime[j]=false;
			}
		}
	}
}

main(){
	int n;
	cin>>n;
	sang();
	for(int i=0; i<=n; ++i){
		if(prime[i]) cout<<i<<" ";
	}
}
