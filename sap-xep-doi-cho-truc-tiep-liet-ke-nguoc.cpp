#include<iostream>
#include<vector>
#include<stack>

using namespace std;

main(){
	int t;
	cin>>t;
	while(t--){
		vector <int> v[100], vct;
		stack <vector<int>> stk;
		int n;
		cin>>n;
		int a[n];
		for(int i=0; i<n; ++i) cin>>a[i];
		
		for(int i=0; i<n-1; ++i){
			for(int j=i+1; j<n; ++j){
				if(a[i]>a[j]){
					swap(a[i],a[j]);
				}
			}
			
			for(int k=0; k<n; ++k){
				v[i].push_back(a[k]);
			}
			stk.push(v[i]);
		}
		
		while(!stk.empty()){
			vct = stk.top();
			cout<<"Buoc "<< stk.size() << ": ";
			for( int x : vct){
				cout<<x<<" ";
			}
			cout<<endl;
			stk.pop();
		}
	}
}
