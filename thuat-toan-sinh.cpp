//#include<iostream>
//
//using namespace std;
//
//int n, a[100];
// 
//bool check(){
//	int l=1, r=n;
//	while(l<r){
//		if(a[l] != a[r]) return false;
//		++l;
//		--r;
//	}
//	return true;
//}
//
//bool sinh(){
//	int pos;
//	for(pos=n; pos>=1; --pos)
//		if(a[pos]==0) break;
//	for(int i=pos; i<=n; ++i)
//		a[i]= 1-a[i];
//	for(int i=1; i<=n; ++i)
//		if(a[i]==0) return false;
//	return true;
//}
//
//void print(){
//	for( int i=1; i<=n; ++i)
//		cout<<a[i]<<' ';
//	cout<<endl;
//}
//
//main(){
//	cin>>n;
//	for(int i=1; i<=n; ++i) a[i]=0;
//	bool flag=false;
//	
//	while(!flag){	
//		if(check()) print();	
//		flag=sinh();
//	}
//	if(check()) print();
//}

#include<iostream>

using namespace std;

int n,a[100],ok;

void first(){
	for(int i=1;i<=n;i++) a[i]=0; 
}
	
void sinh(){
	int i=n;
	while(i>=1 && a[i]==1) { a[i]=0;  --i; }
	if(i==0) ok=0; // cau hinh cuoi cung. 
	else a[i]=1; 
}

bool check(){
	for(int i=1;i<=n;i++){
		if(a[i]!=a[n-i+1]) return false; 
	}
	return true ;
}

int main(){
	cin>>n;    
	ok=1;     
	first();
	while(ok==1){
		if(check()==true){
			for (int i=1;i<=n;i++)  {cout<<a[i]<<" ";}
			cout<<endl;	
		}
		sinh(); 
	}
}

