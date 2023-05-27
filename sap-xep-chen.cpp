#include<iostream>

using namespace std;

void print(int a[], int pos){
	for(int i=0; i<= pos; ++i)
		cout<<a[i]<<" ";
	cout<<endl;
}

void Insertion_Sort(int a[], int n){
	int pos, x;
	for(int i=0; i<n; ++i){
		x=a[i];
		pos=i-1;
		int positions=pos;
		
		while( pos>=0 && a[pos] > x ){
			a[pos+1] = a[pos];
			--pos;
		}
		a[pos+1]=x;
		cout<<"Buoc "<<i<<": ";
		print(a,positions+1);
	}
}

main(){
	int n;
	cin>>n;
	int a[n];
	for(int i=0; i<n; ++i)
		cin>>a[i];
	Insertion_Sort(a,n);

}
