#include<iostream>

using namespace std;

char res[100];
char c;
int k;
bool visited[200];
void Try(char u, char a){
	for(int i=a; i<=c; ++i){
		res[u-1]=i;
		if(u==k){
			cout<<res<<endl;
		}
		else Try(u+1,i);
	}
}

main(){
	cin>>c>>k;
	Try(1,'A');
}
