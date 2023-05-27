#include<iostream>
#include<cmath>

using namespace std;

main(){
	int t;
	cin>>t;
	while(t--){
		int n;
		cin>>n;
		int count=0, i;
		for(i=1; i<sqrt(n); ++i){
			if(n%i == 0){
				count = (i%2 == 0)? ++count : count;
				count = ( (n/i)%2 == 0)? ++count : count;
			}
		}
		if(i == sqrt(n)) count = (i%2 == 0)? ++count : count;
		cout<<count<<endl;
	}
}
