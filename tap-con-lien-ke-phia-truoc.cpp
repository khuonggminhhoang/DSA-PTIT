#include<iostream>
#include<stack>

using namespace std;

int a[1005], n,k;
stack <int>
bool sinh_to_hop(){
	int pos;
	for(pos=k; pos>=1; --pos)
		if(a[pos] < n-k+pos) break;
	
	a[pos]+=1;
	for(int i=pos+1; i<=k; ++i)
		a[i]= a[pos] + (i-pos);
		
	for(int i=1; i<=k; ++i)
		if(a[i] != n-k+i) return false;
	return true;
}

void in(){
	for(int i=1; i<=k; ++i) 
		cout<<a[i];
	cout<<" ";
}

main(){
	int t;
	cin>>t;
	while(t--){
		cin>>n>>k;
		for(int i=1; i<=k; ++i) a[i]=i;
		
		
		cout<<endl;
	}
}
