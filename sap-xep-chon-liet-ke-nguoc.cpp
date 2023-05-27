#include<iostream>
#include<stack>
#include<vector>

using namespace std;

main(){
	int n;
	cin>>n;
	int a[n];
	for(int i=0; i<n; ++i) cin>>a[i];
	// selection sort:
	vector <int> v[100], vct;
	stack <vector <int>> stk;
	int min=0;
	for(int i=0; i<n-1; ++i){
		min=i;
		for(int j=i+1; j<n; ++j){
			if(a[j]<a[min]) min=j;
		}
		swap(a[i], a[min]);
		
		for(int k=0; k<n; ++k)
			v[i].push_back(a[k]);
		stk.push(v[i]);
	}
	
	while(!stk.empty()){
		vct = stk.top();
		cout<<"Buoc "<< stk.size()<< ": ";
		
		for( int  x : vct)
			cout<<x << " ";
		cout<<endl;
		
		stk.pop();
	}
	
}
