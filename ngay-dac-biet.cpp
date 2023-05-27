#include<iostream>
#include<vector>

using namespace std;

main(){
	vector <string> a1 = {"02", "20", "22"};
	vector <string> a2 = {"02"};
	vector <string> a3 = {"2000", "2002", "2020", "2022", "2200", "2202", "2220", "2222"};
	for(auto x : a1){
		for(auto y : a2){
			for(auto z : a3){
				cout<<x<<'/'<<y<<'/'<<z<<endl;
			}
		}
	}
}
