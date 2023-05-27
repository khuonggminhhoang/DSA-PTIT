#include<iostream>
#define MAX 1000
using namespace std;

struct Node{
	int top;
	Node* next;
};

typedef Node* node;

node makeNode(int data){
	node res = new Node;
	res->top = data;
	res->next = nullptr;
	return res;
}

int size(node a){
	int cnt = 0;
	while(a != nullptr){
		++cnt;
		a = a->next;
	}
	return cnt;
}

int top(node a){
	return a->top;
}

bool empty(node a){
	return a == nullptr;
}

void push(node &a, int data){
	node tmp = makeNode(data);
	if(a == nullptr) a = tmp;
	else{
		tmp->next = a;
		a = tmp;
	}
}

void pop(node &a){
	if( a == nullptr) return;
	else{
		a = a->next;
	}
}

main(){
	node stack = nullptr;
	for(int i=0; i<=10; ++i)
		push(stack,i);
	cout<<top(stack)<<endl;	
	pop(stack);
	cout<<top(stack)<<endl;
	if(!empty(stack)) cout<<"found\n";
	cout<<size(stack)<<endl;
}
