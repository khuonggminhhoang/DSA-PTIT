#include<iostream>
#include<algorithm>
#include<vector>

using namespace std;

struct Element{
	int x, index;
};

bool cmp(Element a, Element b){
	return a.x < b.x;
}

main(){
	int t;
	cin>>t;
	while(t--){
		int n;
		cin>>n;
		vector <Element> v;
		
		Element e;
		for(int i=0; i<n; ++i){
			int x;
			cin>>x;
			e={x,i};
			v.push_back(e);
		}
		sort(v.begin(), v.end(), cmp);
		int max_= -1;
		for(int i=0; i<n-1; ++i){
			for(int j=i+1; j<n; ++j){
				max_=max(v[j].index - v[i].index, max_);
			}
		}
		cout<<max_<<endl;
	}
}
