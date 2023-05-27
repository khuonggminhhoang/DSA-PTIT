#include<iostream>
#include<algorithm>

using namespace std;

main(){
	int n;
	cin>>n;
	int a[n];
	for(auto &x : a) cin>>x;
	sort(a,a+n);
	int x= a[0]*a[1],
		y= a[n-1]*a[n-2];
	cout<<max(max(x,y), max(x*a[n-1], y*a[n-3]));
}
