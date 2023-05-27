#include<iostream>

using namespace std;

main(){
	int t;
	cin>>t;
	while(t--){
		int n;
		cin>>n;
		int a[n];
		for(auto &x : a) cin>>x;
		int max_=-1e9, sum=0;
		for(auto x : a){
			sum+=x;
			if(x < 0 && sum<0){
				max_=max( max_, x);
				sum=0;
				continue;
			}
			max_ = max(max_, sum);
		}
		cout<<max_<<endl;
	}
}

/*

-2 -5 6 -2 -3 1 5 -6

gap so am thi sum=0, max= max cua so am
gap so duong thi sum += x, neu sum > 0 thi cong tiep cac so dang sau no.
in ra max cua sum.

*/
