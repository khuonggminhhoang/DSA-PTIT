#include<iostream>

using namespace std;

struct Node {
	int data;
	Node* next;
};

typedef Node* node;

node makeNode(int data){
	node res = new Node;
	res->data = data;
	res->next = NULL;
	return res;
}

void push( node &queue, int data){
	node tmp = new Node;
	tmp = makeNode(data);
	if(queue == NULL){
	 	queue = tmp;
		return ;
	}
	node temp = queue;
	while( temp->next != NULL ){
		temp = temp->next;
	}
	temp->next = tmp;
}

void pop( node &queue){
	if(queue == NULL) return;
	queue = queue->next;
}

int front(node queue){
//	if(queue == NULL) return -1;
	return queue->data;
}

int back( node queue){
	while(queue->next != NULL){
		queue = queue->next;
	}
	return queue->data;
}

int size(node queue){
	int ans = 0;
	while(queue != NULL){
		ans++;
		queue = queue->next;
	}
	return ans;
}

bool empty(node queue){
	return queue == NULL;
}

void Display(node queue){
	while(queue != NULL){
		cout<<queue->data<<' ';
		queue = queue->next;
	}
}

main(){
	node queue = NULL;
	push(queue, 100);
	push(queue, 200);
	push(queue, 300);
	push(queue, 400);
	Display(queue); cout<<endl;
	cout<<front(queue)<<endl;
	cout<<size(queue)<<endl;
	cout<<back(queue)<<endl;
}
