#include<iostream>
#include<vector>
#include<stack>

using namespace std;

main(){
	int n;
	cin>>n;
	int a[n];
	for(int i=0; i<n; ++i) cin>>a[i];
	
	vector <int> v[100], vct;
	stack <vector<int>> stk;
	
	// insertion sort
	int x,pos;
	for(int i=0; i<n; ++i){
		x=a[i];
		pos=i-1;
		
		while( pos >=0 && a[pos] > x){
			a[pos+1]= a[pos];
			--pos;
		}
		a[pos+1]=x;
		
		for(int k=0; k<=i; ++k)
			v[i].push_back(a[k]);
		stk.push(v[i]);	 	
	}
	
	while(!stk.empty()){
		vct = stk.top();
		cout<< "Buoc "<< stk.size()-1 << ": ";
		for( int x : vct) cout<<x << " ";
		cout<<endl;
		stk.pop();
	}

}

