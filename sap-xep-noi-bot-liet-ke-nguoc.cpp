#include<iostream>
#include<stack>
#include<vector>

using namespace std;

main(){
	int t;
	cin>>t;
	while(t--){
		int n;
		cin>>n;
		int a[n];
		for(int i=0; i<n; ++i) cin>>a[i];
		
		vector <int> v[100], vct;
		stack <vector <int>> stk;
		
		//bubble sort
		
		for(int i=0; i<n-1; ++i){
			bool flag=false;
			for(int j=0; j<n-i-1; ++j){
				if(a[j]>a[j+1]){
					swap(a[j], a[j+1]);
					flag=true;
				} 
			}
			if(flag) {
				for(int k=0; k<n; ++k){
					v[i].push_back(a[k]);
				}
				stk.push(v[i]);
			}
		}
		
		while(!stk.empty()){
			vct = stk.top();
			cout<<"Buoc "<< stk.size() << ": ";
			for( int x : vct) cout<<x<<" ";
			cout<<endl;
			stk.pop();
		}
		
	}
}
